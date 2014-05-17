using System;

namespace Clothes.Classes
{
    // структура ClothesStruct, для хранения объекта единицы оджежды
    public class ClothesStruct
    {
        public int id;              // уникальный идентификатор
        public string Name;         // название одежды
        public decimal Price;       // цена
        public string Picture;      // файл-изображение
        public int Color;           // цвет
    }

    // структура ClientStruct, для хранения данных клиента
    public class ClientStruct
    {
        public int id;              // уникальный идентификатор
        public string Name;         // имя
        public string eMail;        // адрес почты
        public int HistoryCount;    // история покупок
        public decimal HistorySumm; // история покупок
    }

    // структура ReportStruct, для хранения данных клиента
    public class ReportStruct
    {
        public string Name;         // имя
        public string eMail;        // адрес почты
        public DateTime Date;       // дата покупки
        public string ClothesName;  // название одежды
        public decimal Price;       // цена
        public int Count;           // количество
    }

    // структура EmailDataManager, для хранения данных отправки e-mail
    public class EmailDataManager
    {
        public string NameFrom;     // отправитель
        public string EmailFrom;    // адрес отправителя
        public string UserName;     // логин
        public string Password;     // пароль на сервер отправки
        public string SMTPServer;   // сервер отправки
        public bool SMTPSSL;        // SSL
        public int SMTPPort;        // порт сервера
        public string Subject;      // тема письма
        public string MessageText;  // сообщение
    }
}
