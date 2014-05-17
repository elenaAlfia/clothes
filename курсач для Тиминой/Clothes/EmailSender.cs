using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.Mail;

namespace Clothes.Classes
{
    // класс EmailSender, реализующий отправку e-mail
    class EmailSender
    {
        private List<String> eMailList;
        private EmailDataManager SMTPData;
        
        // данные для посылки email берутся из frmMain.SMTPData, который хранит данные для ящика, с которого будет проводиться рассылка
        public EmailSender(EmailDataManager SMTPData, List<String> eMailList)
        {
            this.eMailList = eMailList;
            this.SMTPData = SMTPData;
        }

        public void SendToAllEmails()
        {
            for (int i = 0; i < eMailList.Count; ++i)
            {
                SendToEmail(eMailList[i]);
            }
        }

        public void SendToEmail(String email)
        {
            // заполняем необходимые поля
            MailMessage message = new MailMessage(SMTPData.EmailFrom, email);
            message.Subject = SMTPData.Subject;
            message.Body = SMTPData.MessageText;

            // создаем экземпляр клиента SmtpClient
            SmtpClient client = new SmtpClient
            {
                Host = SMTPData.SMTPServer,
                Port = SMTPData.SMTPPort,
                EnableSsl = SMTPData.SMTPSSL,
                DeliveryMethod = SmtpDeliveryMethod.Network,
                UseDefaultCredentials = false,
                Credentials = new NetworkCredential(SMTPData.UserName, SMTPData.Password),
                Timeout = 30000
            };

            // отправляем письмо
            int Count = 3;
            while (Count > 0) 
            {
                try
                {
                    client.Send(message);
                    return;
                }
                catch (Exception ex)
                {
                    Count--;
                    Console.WriteLine("Exception caught in CreateTestMessage2(): {0}",
                          ex.ToString());
                }
            }
        }
    }
}
