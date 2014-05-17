using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

using NetOffice;
using Excel = NetOffice.ExcelApi;
using Word = NetOffice.WordApi;
using NetOffice.ExcelApi.Enums;
using NetOffice.WordApi.Enums;

using Clothes.Classes;

namespace Clothes
{
    // главная форма приложения
    public partial class frmMain : Form
    {
        private DBConnector DataBase = new DBConnector();
        private bool flagAllowUpdate = true;
        
        List<ClothesStruct> AvailableClothes = new List<ClothesStruct>();
        List<ClientStruct> Clients = new List<ClientStruct>();

        // To integer
        private int ColorToInt(Color color)
        {
            // ((Item.BackColor.B * 256 + Item.BackColor.G) * 256 + Item.BackColor.R);
            return (color.B << 16) | (color.G << 8) | color.R;
        }

        // диалог выбора цвета одежды
        private void ShowColorDialog(object sender, ListViewColumnMouseEventArgs e)
        {
            if (colorDialog.ShowDialog() != DialogResult.OK)
                return;

            ClothesStruct ClothesData = (ClothesStruct)e.Item.Tag;
            ClothesData.Color = ColorToInt(colorDialog.Color);

            e.Item.BackColor = colorDialog.Color;
            e.SubItem.ForeColor = colorDialog.Color;
        }

        // принудительное освобождение дочерних контролов во избежание мемориликов.
        private void FreeChildren(Control parent)
        {
            foreach (Control Item in parent.Controls)
            {
                FreeChildren(Item);
                Item.Dispose();
            }
        }

        private decimal CalcDiscount(decimal Summ) 
        {
            decimal Discount = 0;

            if (Summ >= 15000)
                Discount = 20;
            else if (Summ >= 10000)
                Discount = 10;
            else if (Summ >= 5000)
                Discount = 5;

            return Discount;
        }

        // расчет и отображение общей стоимости и скидки
        private void ShowPriceTotal(decimal PriceTotal)
        {
            decimal Discount = CalcDiscount(PriceTotal);

            if (Discount > 0)
                txtDiscount.Text = Discount.ToString() + "%";
            else txtDiscount.Text = "нет";

            txtPriceTotal.Text = (PriceTotal - ((PriceTotal / 100) * Discount)).ToString();
        }

        public frmMain()
        {
            InitializeComponent();
        }

        // стартовая инициализация алгоритма
        private void frmMain_Load(object sender, EventArgs e)
        {
            flagAllowUpdate = false;

            // настройка кнопок смены цвета одежды
            ListViewExtender lvExtender = new ListViewExtender(lvBasket);
            ListViewButtonColumn buttonAction = new ListViewButtonColumn(1);
            buttonAction.Click += ShowColorDialog;
            buttonAction.FixedWidth = true;

            lvExtender.AddColumn(buttonAction);

            // инициализация фильтров
            cbSize.SelectedIndex = 2;
            cbStyle.SelectedIndex = 0;
            rbSize.Checked = true;

            flagAllowUpdate = true;
            
            cbGender.SelectedIndex = 0;
            cbReportFormat.SelectedIndex = 0;
        }

        // функция, осуществляющая отображение БД клиентов
        private void ShowClients() 
        {
            lvClients.Items.Clear();
            DataBase.SelectClients(Clients);

            foreach (ClientStruct ClientData in Clients)
            {
                ListViewItem ClientItem = lvClients.Items.Add(ClientData.Name);
                ClientItem.SubItems.Add(ClientData.eMail);

                if (ClientData.HistoryCount > 0) 
                {
                    ClientItem.SubItems.Add(ClientData.HistoryCount.ToString());
                    ClientItem.SubItems.Add(ClientData.HistorySumm.ToString());
                    
                    decimal Discount = CalcDiscount(ClientData.HistorySumm);
                    if (Discount > 0) 
                    {
                        ClientItem.SubItems.Add(Discount.ToString());

                        if (Discount >= 20)
                            ClientItem.BackColor = Color.LightGreen;
                        if (Discount >= 10)
                            ClientItem.BackColor = Color.LightYellow;
                    }
                }

                ClientItem.Tag = ClientData;
            }
        }

        // функция, осуществляющая фильтрацию БД одежды соответственно пользовательскому запросу
        private void ApplyFilter(object sender, EventArgs e)
        {
            // блокируем возможность повторного вхождения
            if (!flagAllowUpdate)
                return;

            flagAllowUpdate = false;

            // очищаем предыдущий выбор
            lvCatalog.Items.Clear();
            lvBasket.Items.Clear();
            if (pictureModel.Image != null) pictureModel.Image.Dispose();
            FreeChildren(pictureModel);
            ShowPriceTotal(0);

            // устанавливаем изображение манекена
            string ModelPicture = "";
            if (cbGender.SelectedIndex == 0)
                ModelPicture = "model_female.png";
            else ModelPicture = "model_male.png";

            pictureModel.Image = Image.FromFile(Application.StartupPath + @"\Images\" + ModelPicture);
            pictureModel.Refresh();

            // выбираем из БД одежду
            DataBase.SelectClothesByCriteria(
                cbGender.SelectedIndex, 
                cbSize.SelectedIndex, 
                cbStyle.SelectedIndex,
                AvailableClothes
            );

            // заполняем каталог
            foreach (ClothesStruct Item in AvailableClothes) 
            {
                ListViewItem CatalogItem = lvCatalog.Items.Add(Item.Name);
                CatalogItem.SubItems.Add(Item.Price.ToString("N"));
                CatalogItem.Tag = Item;
            }

            pnlOrderActions.Enabled = false;

            // отключаем блокировку возможность повторного вхождения
            flagAllowUpdate = true;
        }

        private void SyzeTypeChanged(object sender, EventArgs e)
        {
            pnlSize_cm.Enabled = rbSize_cm.Checked;
            cbSize.Enabled = rbSize.Checked;
        }

        // производим расчет размера по введенным сантиметрам
        private void Size_cmChanged(object sender, EventArgs e)
        {
            // согласно http://www.weboutlet.com.ua/dimensions.html

            decimal SizeIndex = numHeight.Value + numHigh.Value + numMiddle.Value + numLow.Value;

            switch(cbGender.SelectedIndex)
            {
                case 0:
                //Женские размеры
                //США размеры  	XS 	S 	M 	L 	XL 	
                //Рост 	        158	164 168 172	176 	
                //Ширина груди 	84 	89 	94 	102	109 	
                //Ширина талии 	62 	66 	71 	79 	86 	
                //Ширина бедер 	89 	94 	99 	107	114 	
                {
                    if (SizeIndex < 413)
                        cbSize.SelectedIndex = 0;
                    else if (SizeIndex < 432)
                        cbSize.SelectedIndex = 1;
                    else if (SizeIndex < 460)
                        cbSize.SelectedIndex = 2;
                    else if (SizeIndex < 485)
                        cbSize.SelectedIndex = 3;
                    else 
                        cbSize.SelectedIndex = 4;
                    break;
                }
                case 1:
                //Мужские размеры
                //США размеры 	XS 	S 	M 	L 	XL
                //Рост 	        170 176 180 184 188
                //Ширина груди 	88 	92 	100 108 116
                //Ширина талии 	74 	78 	84 	92 	100
                //Ширина бедер 	92 	96 	104 112 120
                {
                    if (SizeIndex < 442)
                        cbSize.SelectedIndex = 0;
                    else if (SizeIndex < 468)
                        cbSize.SelectedIndex = 1;
                    else if (SizeIndex < 496)
                        cbSize.SelectedIndex = 2;
                    else if (SizeIndex < 524)
                        cbSize.SelectedIndex = 3;
                    else 
                        cbSize.SelectedIndex = 4;
                    break;
                }
            }

            cbSize.Refresh();
        }

        // обработка выбора одежды из каталога
        private void lvCatalog_SelectedIndexChanged(object sender, EventArgs e)
        {
            // очищаем козину
            FreeChildren(pictureModel);
            lvBasket.Items.Clear();

            // если пользователь ничего не выбрал
            if (lvCatalog.SelectedItems.Count == 0) return;

            PictureBox pictureParent = pictureModel;
            decimal PriceTotal = 0;

            // "одеваем" манекен и готовим заказ
            foreach (ListViewItem Item in lvCatalog.SelectedItems)
            {
                ClothesStruct ClothesData = (ClothesStruct)Item.Tag;
                // поля каталога
                ListViewItem basketItem = lvBasket.Items.Add(ClothesData.Name);
                basketItem.Tag = Item.Tag;
                basketItem.SubItems.Add("...");
                basketItem.SubItems.Add(ClothesData.Price.ToString());
                
                // общая цена
                PriceTotal += ClothesData.Price;

                PictureBox pictureClothes = new PictureBox();
                pictureClothes.Hide();

                // реализация "прозрачности", для этого каждое следующее изображение одежды
                // должно накладываться на предыдущее, а не на манекен. как то так.
                pictureParent.Controls.Add(pictureClothes);
                pictureParent = pictureClothes;

                // изображение одежды из файла
                pictureClothes.Image = Image.FromFile(
                    Application.StartupPath + @"\Base\" + 
                    (cbGender.SelectedIndex == 0 ? "Female":"Male") + @"\" + ClothesData.Picture
                );
                pictureClothes.Size = pictureModel.Size;
                pictureClothes.SizeMode = pictureModel.SizeMode;
                pictureClothes.BackColor = Color.Transparent;

                pictureClothes.Show();
            }

            ShowPriceTotal(PriceTotal);

            pnlOrderActions.Enabled = (lvCatalog.Items.Count > 0);
        }

        // предварительный просмотр заказа в MS Word
        private void btnOrderPreview_Click(object sender, EventArgs e)
        {
            object objMissing = System.Reflection.Missing.Value;

            // инициализация OLE-механизма
            Word.Application WordApplication = new Word.Application();
            WordApplication.Visible = true;

            // новый документ
            Word.Document Document = WordApplication.Documents.Add();

            Document.Content.Paragraphs.Add(objMissing).Range.Text =
                txtName.Text + ", Вы заказали:" + "\n";
            
            // таблица
            Word.Table objTable = Document.Tables.Add(
                Document.Content.Paragraphs.Add(objMissing).Range,
                lvBasket.Items.Count + 2,
                3,
                Word.Enums.WdDefaultTableBehavior.wdWord8TableBehavior,
                Word.Enums.WdAutoFitBehavior.wdAutoFitContent
            );

            objTable.Cell(1, 1).Range.Text = "Одежда";
            objTable.Cell(1, 2).Range.Text = "Цвет";
            objTable.Cell(1, 3).Range.Text = "Цена";

            int i = 2;
            decimal PriceTotal = 0;

            foreach (ListViewItem Item in lvBasket.Items)
            {
                ClothesStruct ClothesData = (ClothesStruct)Item.Tag;

                //Clipboard.SetImage(Image.FromFile(
                //    Application.StartupPath + @"\Base\" +
                //    (cbGender.SelectedIndex == 0 ? "Female" : "Male") + @"\" + ClothesData.Picture
                //));
                //objTable.Cell(i, 1).Range.Paste();
                objTable.Cell(i, 1).Range.Text = ClothesData.Name;
                objTable.Cell(i, 2).Range.Shading.BackgroundPatternColor = (WdColor)ClothesData.Color;
                objTable.Cell(i, 3).Range.Text = ClothesData.Price.ToString("N");
                PriceTotal += ClothesData.Price;

                i++;
            }
            objTable.Cell(i, 1).Range.Text = "Всего позиций - " + (i - 1).ToString();
            objTable.Cell(i, 3).Range.Text = "Общая сумма - " + PriceTotal.ToString("N");

            string strDiscount = "";

            if (txtDiscount.Text != "нет")
                strDiscount = "(со скидкой " + txtDiscount.Text + ")";

            Document.Content.Paragraphs.Add(objMissing).Range.Text = 
                "\nCумма заказа" + strDiscount + ": " + txtPriceTotal.Text + "\n\n";

            object fileFormat = WdSaveFormat.wdFormatPDF;
            Document.SaveAs(Application.StartupPath + @"\Мой заказ.pdf", fileFormat);
        }

        // регистрируем клиента и его покупку в БД
        private void btnCheckout_Click(object sender, EventArgs e)
        {
            int ClientID = DataBase.AddClient(txtName.Text, txtEMail.Text);
            if (ClientID == -1)
            {
                MessageBox.Show(
                    "Пожалуйста, еще раз проверьте Ваши реквизиты.",
                    "Неудача!",
                    MessageBoxButtons.OK,
                    MessageBoxIcon.Error
                );

                return;
            }

            List<ClothesStruct> Basket = new List<ClothesStruct>();
            foreach (ListViewItem Item in lvBasket.Items)
                Basket.Add((ClothesStruct)Item.Tag);

            if (DataBase.RegisterSale(ClientID, Basket))
            {
                MessageBox.Show(
                    "Ваш заказ успешно сформирован.",
                    "Поздравляем!",
                    MessageBoxButtons.OK,
                    MessageBoxIcon.Information
                );

                ApplyFilter(btnCheckout, new EventArgs());
            }
        }

        private void tabControl1_SelectedIndexChanged(object sender, EventArgs e)
        {
            ShowClients();
        }

        // в зависимости от выбора пользователя обрабатываем добавление(замену) или удаление клиента
        private void ManageClient(object sender, EventArgs e)
        {
            int id = -1;
            if (lvClients.SelectedItems.Count != 0)
                id = ((ClientStruct)lvClients.SelectedItems[0].Tag).id;

            if (sender == btnClientAddEdit) 
                DataBase.AddClient(txtClientName.Text, txtClientEMail.Text, id);
            else if (sender == btnClientDelete)
                DataBase.DeleteClient(id);

            ShowClients();
        }

        // проверяем выбрал пользователь клиента для редактирования или добавляет нового
        private void lvClients_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(lvClients.SelectedItems.Count == 0)
            {
                btnClientAddEdit.Text = "Добавить";
                btnClientDelete.Enabled = false;
            }
            else 
            {
                ClientStruct ClientData = (ClientStruct)lvClients.SelectedItems[0].Tag;
                txtClientName.Text = ClientData.Name;
                txtClientEMail.Text = ClientData.eMail;

                btnClientAddEdit.Text = "Заменить";
                btnClientDelete.Enabled = true;
            }
        }

        // рассылка
        private void button3_Click(object sender, EventArgs e)
        {
            EmailDataManager SMTPData = new EmailDataManager()
            {
                EmailFrom = txtUrEmail.Text,
                UserName = txtSMTPLogin.Text,
                Password = txtSMTPPassword.Text,
                SMTPServer = txtSmtpServer.Text,
                SMTPPort = (int)numPort.Value,
                SMTPSSL = checkSSL.Checked,
                Subject = txtSubject.Text,
                MessageText = txtLetterText.Text
            };

            new EmailSender(SMTPData, DataBase.ClientEMails()).SendToAllEmails();
        }

        // функция создания отчета о продажах за указанный период
        private void btnMakeReport_Click(object sender, EventArgs e)
        {
            if (dateReportFrom.Value.Date > dateReportTo.Value.Date)
            {
                MessageBox.Show(
                    "Дата начала периода не может быть больше даты его окончания.",
                    "Неудача!",
                    MessageBoxButtons.OK,
                    MessageBoxIcon.Error
                );
                return;
            }

            List<ReportStruct> Report = new List<ReportStruct>();
            // производим выборку из базы
            DataBase.SelectSalesByDate(
                dateReportFrom.Value.Date + new TimeSpan(0, 0, 0),
                dateReportTo.Value.Date + new TimeSpan(23, 59, 59),
                Report
            );
            if (Report.Count == 0)
            {
                MessageBox.Show(
                    "Нет продаж за указанный период.",
                    "Неудача!",
                    MessageBoxButtons.OK,
                    MessageBoxIcon.Error
                );

                return;
            }

            // создаем экземпляр MS Excel
            Excel.Application ExcelApplication = new Excel.Application();
            ExcelApplication.Visible = (cbReportFormat.SelectedIndex == 0);
            ExcelApplication.DisplayAlerts = false;
            // добавляем 
            Excel.Workbook Workbook = ExcelApplication.Workbooks.Add();
            Excel.Worksheet Worksheet = (Excel.Worksheet)Workbook.Worksheets[1];

            int r = 1;
            decimal Count = 0;
            decimal Summ = 0;
            string CurrentClient = "";

            // для каждой записи формируем вывод
            foreach (ReportStruct ReportItem in Report) 
            {
                if (ReportItem.eMail != CurrentClient) 
                {
                    // итог по клиенту
                    if (Count > 0) 
                    {
                        Worksheet.Range("C" + r.ToString()).Value = "Всего";
                        Worksheet.Range("D" + r.ToString()).Value = Count;
                        Worksheet.Range("E" + r.ToString()).Value = Summ;
                        Count = 0;
                        Summ = 0;
                        r++;
                    }
                    CurrentClient = ReportItem.eMail;
                    Worksheet.Range("A" + r.ToString()).Value = ReportItem.Name;
                    Worksheet.Range("B" + r.ToString()).Value = ReportItem.eMail;
                    r++;
                }
                Worksheet.Range("C" + r.ToString()).Value = ReportItem.Date;
                Worksheet.Range("D" + r.ToString()).Value = ReportItem.ClothesName;
                Worksheet.Range("E" + r.ToString()).Value = ReportItem.Price;
                Count++;
                Summ += ReportItem.Price;
                r++;
            }

            if (Count > 0)
            {
                Worksheet.Range("C" + r.ToString()).Value = "Всего";
                Worksheet.Range("D" + r.ToString()).Value = Count;
                Worksheet.Range("E" + r.ToString()).Value = Summ;
            }

            Worksheet.Range("C:C").EntireColumn.ColumnWidth = 15;
            Worksheet.Range("D:D").EntireColumn.ColumnWidth = 20;

            // если выбран формат вывода PDF
            if (cbReportFormat.SelectedIndex == 1)
            {
                // настраиваем создание документа
                XlFixedFormatType paramExportFormat = XlFixedFormatType.xlTypePDF;
                XlFixedFormatQuality paramExportQuality = XlFixedFormatQuality.xlQualityStandard;
                bool paramOpenAfterPublish = true;
                bool paramIncludeDocProps = true;
                bool paramIgnorePrintAreas = true;
                object paramFromPage = Type.Missing;
                object paramToPage = Type.Missing;

                // сохраняем
                Workbook.ExportAsFixedFormat(
                    paramExportFormat,
                    Application.StartupPath + @"\отчет.pdf",
                    paramExportQuality,
                    paramIncludeDocProps, 
                    paramIgnorePrintAreas, 
                    paramFromPage,
                    paramToPage, 
                    paramOpenAfterPublish
                );
            }

            // закрываем MS Excel
            ExcelApplication.Quit();
        }
    }
}
