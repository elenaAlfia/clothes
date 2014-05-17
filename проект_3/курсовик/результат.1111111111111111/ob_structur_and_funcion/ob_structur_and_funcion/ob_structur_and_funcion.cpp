// ob_structur_and_funcion.cpp: ������������� ���� �������.

#ifndef sostav_funcion_H
#define sostav_funcion_H

struct Sklad  // �������� ����� ��������� �����
{
    int ID_Sklad;    
    int Kolichestvo_Skladskih_Mest;  // ���������� ��������� ����
    char *Nathvanie_Sklada;         // �������� ������ 
    Sklad *next;              // ��������� �� ��������� ������� � ���������� �������
};
struct listSklad                 // ������� ������ ��������
{
	Sklad *head;                 // ������ ������� (������) ������
};
struct Komplektyushai            // �������� ����� ��������� ������������
{
	 int ID_Komplektyushai;
	 char *Naimenovanie;        // ������������
	 int Cena_Komplektyushei;    // ���� �������������
	 Komplektyushai *next;
};
struct listKomplektyushai                 // ������� ������ ��������
{
	Komplektyushai *head;                 // ������ ������� (������) ������
};
struct Master                    // �������� ����� ��������� ������
{
	int ID_Master;               
	char *FIO;                  // ���
	int Zarplata;                // ��������
	Master *next;
};
struct listMaster                 // ������� ������ ��������
{
	Master *head;                 // ������ ������� (������) ������
};
struct Mesto_Hranenia            // �������� ����� ��������� ����� ��������
{
	int ID_Mesto_Hranenia;       
	int ID_Sklad;
	int ID_Komplektyushai;
	int Kolichestvo_Komplektyushih;  // ���������� �������������
	Mesto_Hranenia *next;
};
struct listMesto_Hranenia                 // ������� ������ ��������
{
	Mesto_Hranenia *head;                 // ������ ������� (������) ������
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

struct Remont                     // �������� ����� ��������� ������
{
	int ID_Remont;
	int ID_Vid_Remonta;
	int ID_Komplektyushai;
	int Stoimost;                 // ���������
	int ID_Master;
	Data Data_Remonta;          // ���� �������
	Remont *next;
};
struct listRemont                 // ������� ������ ��������
{
	Remont *head;                 // ������ ������� (������) ������
};
struct Ispolzyemie_Komplektyushie  // �������� ����� ��������� ������������ �������������
{
	int ID_Ispolzyemie_Komplektyushie;
	int ID_Komplektyushai;
	int Kolichestvo;
	int ID_Remont;
	Ispolzyemie_Komplektyushie *next;
};
struct listIspolzyemie_Komplektyushie                 // ������� ������ ��������
{
	Ispolzyemie_Komplektyushie  *head;                 // ������ ������� (������) ������
};
struct Vid_Remonta
{
	int ID_Vid_Remonta;
	char *Nazvanie;          // ������������
	Vid_Remonta *next;
};
struct listVid_Remonta                 // ������� ������ ��������
{
	Vid_Remonta *head;                 // ������ ������� (������) ������
};
class List                       // ������� ��� ������ ������
{                               
	public:                      // ������ ������ ����, ��� ����� ����������� ������� ������.
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
	//  ���������� ���������
    void addSklad(int ,int ,char );
    void addKomplektyushai (int , char , int ) ;
	void addMaster (int , char , int );
	void addMesto_Hranenia (int , int , int , int ) ;
	void addVid_Remonta(int , char );
    void addRemont (int , int ,int , int , Data ) ;
	void addIspolzyemie_Komplektyushie (int  , int ,int , int ) ;
    // ������ ���������
	void printSklad() ;
	void printKomplektyushai();
	void printMaster() ;
	void printMesto_Hranenia() ;
	void printRemont() ;
	void printIspolzyemie_Komplektyushie() ;
	void printVid_Remonta() ;
	// ����� �� �����
	void outFileSklad(char *) ;
	void outFileKomplektyushai(char *) ;
	void outFileMaster(char *) ;
	void outFileMesto_Hranenia(char *) ;
	void outFileRemont(char *) ;
	void outFileIspolzyemie_Komplektyushie(char *) ;
	void outFileVid_Remonta(char *) ;
	// � ����
	void inFileSklad(char * path) ;
	void inFileKomplektyushai(char * path) ;
	void inFileMaster(char * path) ;
	void inFileMesto_Hranenia(char * path);
    void inFileRemont(char * path); 
	void inFileIspolzyemie_Komplektyushie(char * path) ;
	void inFileVid_Remonta(char * path);
	//  ������������� ID
	bool existIDSklad(int ID);
	bool existIDKomplektyushai(int ID) ;
	bool existIDMaster(int ID) ;
	bool existIDMesto_Hranenia(int ID);
	bool existIDRemont(int ID) ;
	bool existIDIspolzyemie_Komplektyushie(int ID);
	bool existIDVid_Remonta(int ID) ;
	// ���������� ID
	void findByIDSklad(int, int, char *);
	void findByIDKomplektyushai(int , char *, int );
	void findByIDMaster(int , char *, int ) ;
	void findByIDMesto_Hranenia(int , int , int , int ) ;
	void findByIDRemont(int , int , int , int , Data );
	void findByIDIspolzyemie_Komplektyushie(int , int , int , int ) ;
	void findByIDVid_Remonta(int , char *);
	// ��������
	void delByValueSklad(int );
	void delByValueKomplektyushai(int ) ;
	void delByValueMaster(int ) ;
	void delByValueMesto_Hranenia(int ) ;
	void delByValueRemont(int );
	void delByValueIspolzyemie_Komplektyushie(int ) ;
	void delByValueVid_Remonta(int ) ;
	// ����� ��� ���������� �������

};
    Date inputDate();

    int myAtoi (char * str);

#endif
