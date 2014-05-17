using System;
using System.Collections.Generic;
using System.Data.SqlServerCe;

namespace Clothes.Classes
{
    // класс DBConnector, реализующий обращение к БД
    public class DBConnector
    {
        private SqlCeConnection Connection;

        public DBConnector()
        {
            // настройка подключения к БД
            Connection = new SqlCeConnection(@"Data Source=clothes.sdf");
            Connection.Open();

        }

        // деструктор
        ~DBConnector() 
        {
            Connection.Close();
        }

        // функция выборки списка эл.адресов клиентов из БД
        public List<string> ClientEMails() 
        {
            List<string> Result = new List<string>();

            SqlCeCommand Command = new SqlCeCommand("SELECT email FROM clients", Connection);
            SqlCeDataReader Reader = Command.ExecuteReader();
            while (Reader.Read())
                Result.Add((string)Reader["email"]);

            return Result;
        }

        // функция выбора клиентов из БД
        public void SelectClients(List<ClientStruct> ClientsList)
        {
            ClientsList.Clear();
            // дополнительно собираем историю покупок
            string Query = @"
SELECT c.id, c.name, c.email, COUNT(s.price) AS count, SUM(s.price) AS summ
FROM clients AS c
LEFT JOIN sales AS s ON s.id_client = c.id
GROUP BY c.id, c.name, c.email";

            // выполняем запрос
            SqlCeCommand Command = new SqlCeCommand(Query, Connection);
            SqlCeDataReader Reader = Command.ExecuteReader();
            // читаем занные
            while (Reader.Read())
            {
                ClientStruct ClientData = new ClientStruct();
                // сохраняем необходимые поля в структуру для дальнейшей обработки
                ClientData.id = (int)Reader["id"];
                ClientData.Name = (string)Reader["name"];
                ClientData.eMail = (string)Reader["email"];
                try
                {
                    ClientData.HistoryCount = (int)Reader["count"];
                    ClientData.HistorySumm = (int)Reader["summ"];
                }
                // если клиент еще не совершал покупок
                catch
                {
                    ClientData.HistoryCount = 0;
                    ClientData.HistorySumm = 0;
                }

                ClientsList.Add(ClientData);
            }
        }

        // поиск клиента в БД по его адресу эл.почты
        private int GetClientIDByEMail(string eMail)
        {
            int Result = -1;

            string Query = string.Format("SELECT id FROM clients WHERE email='{0}'", eMail);
            SqlCeCommand Command = new SqlCeCommand(Query, Connection);
            SqlCeDataReader Reader = Command.ExecuteReader();
            if (Reader.Read())
                Result = (int)Reader["id"];

            return Result;
        }

        // функция добавления нового клиента в базу
        // так же проверяется наличие по адресу эл.почты, в случае обнаружения заменяется имя.
        public int AddClient(string Name, string eMail, int id = -1)
        {
            if (Name == "" || eMail == "")
                return -1;

            string Query = "";
            if (id == -1)
                id = GetClientIDByEMail(eMail);

            if (id == -1)
                Query = string.Format("INSERT INTO clients (name, email) VALUES ('{0}','{1}')", Name, eMail);
            else
                Query = string.Format("UPDATE clients SET name='{1}', email='{2}' WHERE id={0}", id, Name, eMail);

            SqlCeCommand Command = new SqlCeCommand(Query, Connection);
            if (Command.ExecuteNonQuery() == 0)
                return -1;

            if (id == -1)
                id = GetClientIDByEMail(eMail);

            return id;
        }

        // регистрация новый продажи
        public bool RegisterSale(int ClientID, List<ClothesStruct> Clothes) 
        {
            DateTime Date = DateTime.Now;
            string Query = "INSERT INTO sales (id_client, id_clothes, price, color, count, date)";

            bool FirstValues = true;
            foreach (ClothesStruct ClothesData in Clothes)
            {
                if (!FirstValues)
                    Query += " UNION ALL";

                FirstValues = false;

                Query += string.Format(" SELECT {0}, {1}, {2}, {3}, {4}, '{5}'",
                    ClientID,
                    ClothesData.id,
                    ClothesData.Price,
                    ClothesData.Color,
                    1,
                    Date
                );
            }
           
            SqlCeCommand Command = new SqlCeCommand(Query, Connection);
            int r = Command.ExecuteNonQuery();
            return (r > 0);
        }

        // функция удаления клиента из БД
        public bool DeleteClient(int id)
        {
            string Query = string.Format("DELETE FROM clients WHERE id={0}", id);
            SqlCeCommand Command = new SqlCeCommand(Query, Connection);
            bool Result = (Command.ExecuteNonQuery() == 1);

            if (Result == true) 
            {
                Query = string.Format("DELETE FROM sales WHERE id_client={0}", id);
                new SqlCeCommand(Query, Connection).ExecuteNonQuery();
            }

            return Result;
        }

        // выборка продаж из БД за указанный период
        public void SelectSalesByDate(DateTime DateFrom, DateTime DateTo, List<ReportStruct> Report)
        {
            Report.Clear();

            string Query = string.Format(
                @"
SELECT c.name, c.email, s.date, l.name AS clothes, s.price
FROM sales AS s
INNER JOIN clients AS c ON c.id = s.id_client
INNER JOIN clothes AS l ON l.id = s.id_clothes
WHERE s.date BETWEEN '{0}' AND '{1}'",
                DateFrom,
                DateTo
            );

            // выполняем запрос
            SqlCeCommand Command = new SqlCeCommand(Query, Connection);
            SqlCeDataReader Reader = Command.ExecuteReader();
            // читаем занные
            while (Reader.Read())
            {
                ReportStruct ReportData = new ReportStruct();
                // сохраняем необходимые поля в структуру для дальнейшей обработки
                ReportData.Name = (string)Reader["name"];
                ReportData.eMail = (string)Reader["email"];
                ReportData.Date = (DateTime)Reader["date"];
                ReportData.ClothesName = (string)Reader["clothes"];
                ReportData.Price = (int)Reader["price"];
                ReportData.Count = 1;

                Report.Add(ReportData);
            }
        }

        // функция выбора одежды из БД, удовлетворяющей условиям пол, размер, стиль
        public void SelectClothesByCriteria(int Gender, int Size, int Style, List<ClothesStruct> Result)
        {
            Result.Clear();

            // составляем запрос согласно условий
            string QueryWHERE = "(count > 0) AND (gender = '";

            if (Gender == 0)
                QueryWHERE += "f')";
            else QueryWHERE += "m')";

            QueryWHERE += " AND (size = " + Size.ToString() + ")";

            if (Style > 0)
                QueryWHERE += " AND (style = " + Style.ToString() + ")";

            string Query = "SELECT id, name, price, image FROM clothes WHERE " + QueryWHERE + " ORDER BY level";

            // выполняем запрос
            SqlCeCommand Command = new SqlCeCommand(Query, Connection);
            SqlCeDataReader Reader = Command.ExecuteReader();
            // читаем занные
            while (Reader.Read())
            {
                ClothesStruct Item = new ClothesStruct();
                // сохраняем необходимые поля в структуру для дальнейшей обработки
                Item.id = Reader.GetInt32(0);
                Item.Name = Reader.GetString(1);
                Item.Price = Reader.GetInt32(2);
                Item.Picture = Reader.GetString(3);

                Result.Add(Item);
            }
        }
    }
}
