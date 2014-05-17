// ob_structur_and_funcion.cpp: дополнительнй файл проекта.

#ifndef sostav_funcion_H
#define sostav_funcion_H

struct Sklad  // Объявили новую структуру склад
{
    int ID_Sklad;    
    int Kolichestvo_Skladskih_Mest;  // количество складских мест
    char *Nathvanie_Sklada;         // название склада 
    Sklad *next;              // указатель на следующий элемент и предыдущий элемент
};
struct listSklad                 // задание списка ссылками
{
	Sklad *head;                 // Первый элемент (голова) списка
};
struct Komplektyushai            // Объявили новую структуру комплекующая
{
	 int ID_Komplektyushai;
	 char *Naimenovanie;        // Наименование
	 int Cena_Komplektyushei;    // Цена комплектующей
	 Komplektyushai *next;
};
struct listKomplektyushai                 // задание списка ссылками
{
	Komplektyushai *head;                 // Первый элемент (голова) списка
};
struct Master                    // Объявили новую структуру мастер
{
	int ID_Master;               
	char *FIO;                  // ФИО
	int Zarplata;                // Зарплата
	Master *next;
};
struct listMaster                 // задание списка ссылками
{
	Master *head;                 // Первый элемент (голова) списка
};
struct Mesto_Hranenia            // Объявили новую структуру Место хранения
{
	int ID_Mesto_Hranenia;       
	int ID_Sklad;
	int ID_Komplektyushai;
	int Kolichestvo_Komplektyushih;  // Количество комплектующих
	Mesto_Hranenia *next;
};
struct listMesto_Hranenia                 // задание списка ссылками
{
	Mesto_Hranenia *head;                 // Первый элемент (голова) списка
};
struct Data 		
	{
		unsigned month;		
		unsigned year;
		Data* next;
	};
struct listData
{
	Data* head;
};

struct Remont                     // Объявили новую структуру Ремонт
{
	int ID_Remont;
	int ID_Vid_Remonta;
	int ID_Komplektyushai;
	int Stoimost;                 // Стоимость
	int ID_Master;
	Data Data_Remonta;          // Дата ремонта
	Remont *next;
};
struct listRemont                 // задание списка ссылками
{
	Remont *head;                 // Первый элемент (голова) списка
};
struct Ispolzyemie_Komplektyushie  // Объявили новую структуру используемые комплектующие
{
	int ID_Ispolzyemie_Komplektyushie;
	int ID_Komplektyushai;
	int Kolichestvo;
	int ID_Remont;
	Ispolzyemie_Komplektyushie *next;
};
struct listIspolzyemie_Komplektyushie                 // задание списка ссылками
{
	Ispolzyemie_Komplektyushie  *head;                 // Первый элемент (голова) списка
};
struct Vid_Remonta
{
	int ID_Vid_Remonta;
	char *Nazvanie;          // Наименование
	Vid_Remonta *next;
};
struct listVid_Remonta                 // задание списка ссылками
{
	Vid_Remonta *head;                 // Первый элемент (голова) списка
};
class List                       // Создаем тип данных Список
{                               
	public:                      // доступ открыт всем, кто видит определение данного класса.
    listSklad *Sklad_L;
	listKomplektyushai *Komplektyushai_L;
	listMaster *Master_L;
	listMesto_Hranenia *Mesto_Hranenia_L;
	listRemont *Remont_L;
	listIspolzyemie_Komplektyushie *Ispolzyemie_Komplektyushie_L;
	listVid_Remonta *Vid_Remonta_L;
	listData *data;

	List();

	~List();
	//  Добавление сущностей
    void addSklad(int ,int ,char );
    void addKomplektyushai (int , char , int ) ;
	void addMaster (int , char , int );
	void addMesto_Hranenia (int , int , int , int ) ;
	void addVid_Remonta(int , char );
    void addRemont (int , int ,int , int , Data ) ;
	void addIspolzyemie_Komplektyushie (int  , int ,int , int ) ;
    // Печать сущностей
	void printSklad() ;
	void printKomplektyushai();
	void printMaster() ;
	void printMesto_Hranenia() ;
	void printRemont() ;
	void printIspolzyemie_Komplektyushie() ;
	void printVid_Remonta() ;
	// Вывод из файла
	void outFileSklad(char *) ;
	void outFileKomplektyushai(char *) ;
	void outFileMaster(char *) ;
	void outFileMesto_Hranenia(char *) ;
	void outFileRemont(char *) ;
	void outFileIspolzyemie_Komplektyushie(char *) ;
	void outFileVid_Remonta(char *) ;
	// В файл
	void inFileSklad(char * path) ;
	void inFileKomplektyushai(char * path) ;
	void inFileMaster(char * path) ;
	void inFileMesto_Hranenia(char * path);
    void inFileRemont(char * path); 
	void inFileIspolzyemie_Komplektyushie(char * path) ;
	void inFileVid_Remonta(char * path);
	//  Существование ID
	bool existIDSklad(int ID);
	bool existIDKomplektyushai(int ID) ;
	bool existIDMaster(int ID) ;
	bool existIDMesto_Hranenia(int ID);
	bool existIDRemont(int ID) ;
	bool existIDIspolzyemie_Komplektyushie(int ID);
	bool existIDVid_Remonta(int ID) ;
	// Нахождение ID
	void findByIDSklad(int, int, char *);
	void findByIDKomplektyushai(int , char *, int );
	void findByIDMaster(int , char *, int ) ;
	void findByIDMesto_Hranenia(int , int , int , int ) ;
	void findByIDRemont(int , int , int , int , Data );
	void findByIDIspolzyemie_Komplektyushie(int , int , int , int ) ;
	void findByIDVid_Remonta(int , char *);
	// Удаление
	void delByValueSklad(int );
	void delByValueKomplektyushai(int ) ;
	void delByValueMaster(int ) ;
	void delByValueMesto_Hranenia(int ) ;
	void delByValueRemont(int );
	void delByValueIspolzyemie_Komplektyushie(int ) ;
	void delByValueVid_Remonta(int ) ;
	// Место под обьявления функций

};
    Date inputDate();

    int myAtoi (char * str);

#endif
