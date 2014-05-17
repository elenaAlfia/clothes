// kursovik.cpp: ������� ���� �������.

#include "stdafx.h"
#include <conio.h>
#include <time.h>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream> 

using namespace std;





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
		//Data* next;
	};
//struct listData
//{
//	Data* head;
//};
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
    listSklad Sklad_L;
	listKomplektyushai Komplektyushai_L;
	listMaster Master_L;
	listMesto_Hranenia Mesto_Hranenia_L;
	listRemont Remont_L;
	listIspolzyemie_Komplektyushie Ispolzyemie_Komplektyushie_L;
	listVid_Remonta Vid_Remonta_L;
	//listData data;
	List()
	{
	   /*Sklad_L = new listSklad; // new ������������ ��������� ������������ ������
       Komplektyushai_L = new listKomplektyushai;
	   Master_L = new listMaster;
	   Mesto_Hranenia_L = new listMesto_Hranenia;
	   Remont_L = new listRemont;
	   Ispolzyemie_Komplektyushie_L = new listIspolzyemie_Komplektyushie;
	   Vid_Remonta_L = new listVid_Remonta;
	   data = new listData;*/

       Sklad_L.head = NULL; // -> �������� ��������� ������� � ������ ������
       Komplektyushai_L.head = NULL; 
	   Master_L.head = NULL; 
	   Mesto_Hranenia_L.head = NULL; 
	   Remont_L.head = NULL; 
	   Ispolzyemie_Komplektyushie_L.head = NULL; 
	   Vid_Remonta_L.head = NULL; 
	   //data.head = NULL;
     }
	~List() 
{
	 while (Sklad_L.head != NULL) // ���� 
		{
		Sklad *temp = Sklad_L.head;
		Sklad_L.head = Sklad_L.head->next;
		delete temp; //������� ������ �� 
		}
	    while (Komplektyushai_L.head != NULL) // ���� 
		{
		Komplektyushai *temp = Komplektyushai_L.head;
		Komplektyushai_L.head = Komplektyushai_L.head->next;
		delete temp;
		}
	    while (Master_L.head != NULL) // ���� 
		{
		Master *temp = Master_L.head;
		Master_L.head = Master_L.head->next;
		delete temp;
		}
	    while (Mesto_Hranenia_L.head != NULL) // ���� 
		{
		Mesto_Hranenia *temp = Mesto_Hranenia_L.head;
		Mesto_Hranenia_L.head = Mesto_Hranenia_L.head->next;
		delete temp;
		}
	    while (Remont_L.head != NULL) // ���� 
		{
		Remont *temp = Remont_L.head;
		Remont_L.head = Remont_L.head->next;
		delete temp;
		}
	    while (Ispolzyemie_Komplektyushie_L.head != NULL) // ���� 
		{
		Ispolzyemie_Komplektyushie *temp = Ispolzyemie_Komplektyushie_L.head;
		Ispolzyemie_Komplektyushie_L.head = Ispolzyemie_Komplektyushie_L.head->next;
		delete temp;
		}
	    while (Vid_Remonta_L.head != NULL) // ���� 
		{
		Vid_Remonta *temp = Vid_Remonta_L.head;
		Vid_Remonta_L.head = Vid_Remonta_L.head->next;
		delete temp;
		}
}
	//  ���������� ���������
		void List::addSklad(int ID_s,int Kolichestvo_Skladskih_Mest,char *Nathvanie_Sklada)
		{
			
			Sklad *temp = new Sklad;
	        temp->ID_Sklad = ID_s;
			temp->Kolichestvo_Skladskih_Mest=Kolichestvo_Skladskih_Mest;
			temp->Nathvanie_Sklada = Nathvanie_Sklada;
	        temp->next = Sklad_L.head;
	        Sklad_L.head = temp;
        }
	    void List::addKomplektyushai (int ID_K , char *Naimenovanie, int Cena_Komplektyushei) 
		{
	      Komplektyushai *temp = new Komplektyushai;
	      temp->ID_Komplektyushai = ID_K;
	      temp->Naimenovanie = Naimenovanie;
          temp->Cena_Komplektyushei = Cena_Komplektyushei;
	      temp->next = Komplektyushai_L.head;
	      Komplektyushai_L.head = temp;
         }
		void List::addMaster (int ID_M , char *FIO, int Zarplata) 
		{
	     
		  Master *temp = new Master;
	      temp->ID_Master = ID_M;
	      temp->FIO = FIO;
          temp->Zarplata = Zarplata;
	      temp->next = Master_L.head;
	      Master_L.head = temp;
         }
	    void List::addMesto_Hranenia (int ID_Me , int ID_S, int ID_K, int Kolichestvo_Komplektyushih) 
		{
	     
		
				Mesto_Hranenia *temp = new Mesto_Hranenia;
				temp->ID_Mesto_Hranenia = ID_Me;
				temp->ID_Sklad = ID_S;
				temp->ID_Komplektyushai = ID_K;
				temp->Kolichestvo_Komplektyushih = Kolichestvo_Komplektyushih;
				temp->next = Mesto_Hranenia_L.head;
				Mesto_Hranenia_L.head = temp;
		}
	    void List::addVid_Remonta(int ID_V, char *Nazvanie) 
		{
	      
	         Vid_Remonta *temp = new Vid_Remonta;
	         temp->ID_Vid_Remonta = ID_V;
	         temp->Nazvanie = Nazvanie;
	         temp->next = Vid_Remonta_L.head;
	         Vid_Remonta_L.head = temp;
        }
	    void List::addRemont (int ID_R , int ID_V,int Stoimost, int ID_M, Data data) 
		{
	     
				Remont *temp = new Remont;
				temp->ID_Remont = ID_R;
				temp->ID_Vid_Remonta = ID_V;
				temp->Stoimost = Stoimost;
				temp->ID_Master = ID_M;
				temp->Data_Remonta.month = data.month;
			    temp->Data_Remonta.year = data.year;  
				temp->next = Remont_L.head;
				Remont_L.head = temp;

				
			
		}	
	    void List::addIspolzyemie_Komplektyushie (int ID_I , int ID_K,int Kolichestvo, int ID_R) 
		{
	      
				Ispolzyemie_Komplektyushie *temp = new Ispolzyemie_Komplektyushie;
				temp->ID_Ispolzyemie_Komplektyushie = ID_I;
				temp->ID_Komplektyushai = ID_K;
				temp->Kolichestvo = Kolichestvo;
				temp->ID_Remont = ID_R;
				temp->next = Ispolzyemie_Komplektyushie_L.head;
				Ispolzyemie_Komplektyushie_L.head = temp;
				
	
}
		// ������ ���������
		void List::printSklad() 
		{
	     cout << "������ ������:" << endl << endl;
	     cout << "-----------------------------------------------------------------------" << endl;
	     cout.setf(ios::left, ios::adjustfield);
	     cout << setw(4) << " ID" << setw(5) << "| ����������" <<  setw(30) << "| �������� ������" << endl;
	     cout << "-----------------------------------------------------------------------" << endl;
	     for (Sklad *temp = Sklad_L.head; temp != NULL; temp = temp->next) 
		      {
		       cout << " " << setw(3) << temp->ID_Sklad << "| " << setw(5) << temp->Kolichestvo_Skladskih_Mest << "| " << setw(30) <<temp->Nathvanie_Sklada << endl;
	          }
	    cout << "-----------------------------------------------------------------------" << endl;
       }
		void List::printKomplektyushai() 
		{
	     cout << "������ �������������:" << endl << endl;
	     cout << "-----------------------------------------------------------------------" << endl;
	     cout.setf(ios::left, ios::adjustfield);
	     cout << setw(4) << " ID" << setw(30) << "| ������������" <<  setw(15) << "| ���� �������������" << endl;
	     cout << "-----------------------------------------------------------------------" << endl;
	     for (Komplektyushai *temp = Komplektyushai_L.head; temp != NULL; temp = temp->next) 
		      {
		       cout << " " << setw(3) << temp->ID_Komplektyushai << "| " << setw(30) << temp->Naimenovanie << "| " << setw(15) <<temp->Cena_Komplektyushei << endl;
	          }
	    cout << "-----------------------------------------------------------------------" << endl;
       }
		void List::printMaster() 
		{
	     cout << "������ ��������:" << endl << endl;
	     cout << "-----------------------------------------------------------------------" << endl;
	     cout.setf(ios::left, ios::adjustfield);
	     cout << setw(4) << " ID" << setw(30) << "| ���" <<  setw(15) << "| ��������" << endl;
	     cout << "-----------------------------------------------------------------------" << endl;
	     for (Master *temp = Master_L.head; temp != NULL; temp = temp->next) 
		      {
		       cout << " " << setw(3) << temp->ID_Master << "| " << setw(30) << temp->FIO << "| " << setw(15) <<temp->Zarplata << endl;
	          }
	    cout << "-----------------------------------------------------------------------" << endl;
       }
		void List::printMesto_Hranenia() 
		{
	     cout << "������ ����� ��������:" << endl << endl;
	     cout << "-----------------------------------------------------------------------" << endl;
	     cout.setf(ios::left, ios::adjustfield);
	     cout << setw(4) << " ID" << setw(4) << "| ID ������"  << setw(4) << "| ID �������������" << setw(10) << "| ���������� �������������" << endl;
	     cout << "-----------------------------------------------------------------------" << endl;
	     for (Mesto_Hranenia *temp = Mesto_Hranenia_L.head; temp != NULL; temp = temp->next) 
		      {
		       cout << " " << setw(3) << temp->ID_Mesto_Hranenia << "| " << setw(3) << temp->ID_Sklad << "| " << setw(3) <<temp->ID_Komplektyushai<< "| "<< setw(10) <<temp->Kolichestvo_Komplektyushih  << endl;
	          }
	    cout << "-----------------------------------------------------------------------" << endl;
       }
		void List::printRemont() 
		{
	     cout << "������ ������:" << endl << endl;
	     cout << "-----------------------------------------------------------------------" << endl;
	     cout.setf(ios::left, ios::adjustfield);
	     cout << setw(4) << " ID" << setw(4) << "| ID ��� �������"  << setw(10) << "| ���������" << setw(4) << "| ID �������"<< setw(7) << "| ���� �������" << endl;
	     cout << "-----------------------------------------------------------------------" << endl;
	     for (Remont *temp = Remont_L.head; temp != NULL; temp = temp->next) 
		      {
		       cout << " " << setw(3) << temp->ID_Remont << "| " << setw(3) << temp->ID_Vid_Remonta << "| " << setw(10) << temp->Stoimost<< "| "<< setw(4) << temp->ID_Master << "| "<< setw(7) << temp->Data_Remonta.month << "/ "<< setw(4) << temp->Data_Remonta.year << endl;
	          }
	    cout << "-----------------------------------------------------------------------" << endl;
       }
		void List::printIspolzyemie_Komplektyushie() 
		{
	     cout << "������ ������������ �������������:" << endl << endl;
	     cout << "-----------------------------------------------------------------------" << endl;
	     cout.setf(ios::left, ios::adjustfield);
	     cout << setw(4) << " ID" << setw(4) << "| ID �������������" <<  setw(10) << "| ����������" <<  setw(4) << "| ID �������" << endl;
	     cout << "-----------------------------------------------------------------------" << endl;
	     for (Ispolzyemie_Komplektyushie *temp = Ispolzyemie_Komplektyushie_L.head; temp != NULL; temp = temp->next) 
		      {
		       cout << " " << setw(3) << temp->ID_Ispolzyemie_Komplektyushie << "| " << setw(3) << temp->ID_Komplektyushai << "| " << setw(10) <<temp->Kolichestvo << "| " << setw(4) << temp->ID_Remont << endl;
	          }
	    cout << "-----------------------------------------------------------------------" << endl;
       }
		void List::printVid_Remonta() 
		{
	     cout << "������ ��� �������:" << endl << endl;
	     cout << "-----------------------------------------------------------------------" << endl;
	     cout.setf(ios::left, ios::adjustfield);
	     cout << setw(4) << " ID" << setw(20) << "| ������������" <<   endl;
	     cout << "-----------------------------------------------------------------------" << endl;
	     for (Vid_Remonta *temp = Vid_Remonta_L.head; temp != NULL; temp = temp->next) 
		      {
		       cout << " " << setw(3) << temp->ID_Vid_Remonta << "| " << setw(5) << temp->Nazvanie <<  endl;
	          }
	    cout << "-----------------------------------------------------------------------" << endl;
       }
		// ����� �� �����
		void List::outFileSklad(char * path) 
		{
	         FILE *out;
	         if ((out = fopen(path,"wb")) == NULL)
		     {
		        cout << "���� " << path << "�� ����� ���� ������!" << endl;
		        return;
	         }
	         struct SkladTemp 
			 {
		        int ID_Sklad;
		        int Kolichestvo_Skladskih_Mest;
		        char Nathvanie_Sklada[50];
		       
	         };
	         for (Sklad *temp = Sklad_L.head; temp != NULL; temp = temp->next) 
			 {
		        SkladTemp head;
		        head.ID_Sklad = temp->ID_Sklad;
		        head.Kolichestvo_Skladskih_Mest = temp->Kolichestvo_Skladskih_Mest;
				strcpy(head.Nathvanie_Sklada , temp->Nathvanie_Sklada);
		        fwrite(&head, sizeof(head), 1, out);
	         }
	         fclose(out);
        }
		void List::outFileKomplektyushai(char * path) 
		{
	         FILE *out;
	         if ((out = fopen(path,"wb")) == NULL)
		     {
		        cout << "���� " << path << "�� ����� ���� ������!" << endl;
		        return;
	         }
	         struct KomplektyushaiTemp 
			 {
		        int ID_Komplektyushai;
	            char Naimenovanie[50];        
	            int Cena_Komplektyushei;
		       
	         };
	         for (Komplektyushai *temp = Komplektyushai_L.head; temp != NULL; temp = temp->next) 
			 {
		        KomplektyushaiTemp head;
		        head.ID_Komplektyushai = temp->ID_Komplektyushai;
		        strcpy(head.Naimenovanie , temp->Naimenovanie);
		        head.Cena_Komplektyushei = temp->Cena_Komplektyushei;
		        fwrite(&head, sizeof(head), 1, out);
	         }
	         fclose(out);
        }
		void List::outFileMaster(char * path) 
		{
	         FILE *out;
	         if ((out = fopen(path,"wb")) == NULL)
		     {
		        cout << "���� " << path << "�� ����� ���� ������!" << endl;
		        return;
	         }
	         struct MasterTemp 
			 {
		        int ID_Master;
	            char FIO[50];        
	            int Zarplata;
		       
	         };
	         for (Master *temp = Master_L.head; temp != NULL; temp = temp->next) 
			 {
		        MasterTemp head;
		        head.ID_Master = temp->ID_Master;
		        strcpy(head.FIO , temp->FIO);
		        head.Zarplata = temp->Zarplata;
		        fwrite(&head, sizeof(head), 1, out);
	         }
	         fclose(out);
        }
		void List::outFileMesto_Hranenia(char * path) 
		{
	         FILE *out;
	         if ((out = fopen(path,"wb")) == NULL)
		     {
		        cout << "���� " << path << "�� ����� ���� ������!" << endl;
		        return;
	         }
	         struct Mesto_HraneniaTemp 
			 {
		        int ID_Mesto_Hranenia;
	            int ID_Sklad;
                int ID_Komplektyushai;
                int Kolichestvo_Komplektyushih;
		       
	         };
	         for (Mesto_Hranenia *temp = Mesto_Hranenia_L.head; temp != NULL; temp = temp->next) 
			 {
		        Mesto_HraneniaTemp head;
		        head.ID_Mesto_Hranenia = temp->ID_Mesto_Hranenia;
		        head.ID_Sklad = temp->ID_Sklad;
		        head.ID_Komplektyushai = temp->ID_Komplektyushai;
                head.Kolichestvo_Komplektyushih = temp->Kolichestvo_Komplektyushih;
		        fwrite(&head, sizeof(head), 1, out);
	         }
	         fclose(out);
        }
		void List::outFileRemont(char * path) 
		{
	         FILE *out;
	         if ((out = fopen(path,"wb")) == NULL)
		     {
		        cout << "���� " << path << "�� ����� ���� ������!" << endl;
		        return;
	         }
	         struct RemontTemp 
			 {
		        int ID_Remont;
				int ID_Vid_Remonta;
	            int Stoimost;
                int ID_Master;
                Data Data;
		       
	         };
	         for (Remont *temp = Remont_L.head; temp != NULL; temp = temp->next) 
			 {
		        RemontTemp head;
		        head.ID_Remont = temp->ID_Remont;
		        head.ID_Vid_Remonta = temp->ID_Vid_Remonta;
		        head.Stoimost = temp->Stoimost;
				head.ID_Master = temp->ID_Master;
                head.Data.month = temp->Data_Remonta.month;
		        head.Data.year = temp->Data_Remonta.year;
  
		        fwrite(&head, sizeof(head), 1, out);
	         }
	         fclose(out);
        }
		void List::outFileIspolzyemie_Komplektyushie(char * path) 
		{
	         FILE *out;
	         if ((out = fopen(path,"wb")) == NULL)
		     {
		        cout << "���� " << path << "�� ����� ���� ������!" << endl;
		        return;
	         }
	         struct Ispolzyemie_KomplektyushieTemp 
			 {
		        int ID_Ispolzyemie_Komplektyushie;
				int ID_Komplektyushai;
	            int Kolichestvo;
                int ID_Remont;                      
	         };
	         for (Ispolzyemie_Komplektyushie *temp = Ispolzyemie_Komplektyushie_L.head; temp != NULL; temp = temp->next) 
			 {
		        Ispolzyemie_KomplektyushieTemp head;
		        head.ID_Ispolzyemie_Komplektyushie = temp->ID_Ispolzyemie_Komplektyushie;
		        head.ID_Komplektyushai = temp->ID_Komplektyushai;
		        head.Kolichestvo = temp->Kolichestvo;
				head.ID_Remont = temp->ID_Remont;            
		        fwrite(&head, sizeof(head), 1, out);
	         }
	         fclose(out);
        }
		void List::outFileVid_Remonta(char * path) 
		{
	         FILE *out;
	         if ((out = fopen(path,"wb")) == NULL)
		     {
		        cout << "���� " << path << "�� ����� ���� ������!" << endl;
		        return;
	         }
	         struct Vid_RemontaTemp 
			 {
		        int ID_Vid_Remonta;
				char Nazvanie[50];                 
	         };
	         for (Vid_Remonta *temp = Vid_Remonta_L.head; temp != NULL; temp = temp->next) 
			 {
		        Vid_RemontaTemp head;
		        head.ID_Vid_Remonta = temp->ID_Vid_Remonta;
		        strcpy(head.Nazvanie , temp->Nazvanie);        
		        fwrite(&head, sizeof(head), 1, out);
	         }
	         fclose(out);
        }
		// � ����
		void List::inFileSklad(char * path) 
		{
		  FILE *in;
	      if ((in = fopen(path,"rb")) == NULL) 
		  {
		    cout << "���� " << path << "�� ����� ���� ������!" << endl;
		    return;
	      }
	      struct SkladTemp
		  {
		    int ID_Sklad;
		    int Kolichestvo_Skladskih_Mest;  
            char Nathvanie_Sklada[50];//����������!
	      };
	      SkladTemp head;
	      while (fread(&head, sizeof(head), 1, in)) 
		  {
			char * tempStr = new char[];
		    strcpy(tempStr, head.Nathvanie_Sklada);
		    addSklad(head.ID_Sklad, head.Kolichestvo_Skladskih_Mest, tempStr);
	      }
	fclose(in);
	printSklad();	
}
		void List::inFileKomplektyushai(char * path) 
		{
		  FILE *in;
	      if ((in = fopen(path,"rb")) == NULL) 
		  {
		    cout << "���� " << path << "�� ����� ���� ������!" << endl;
		    return;
	      }
	      struct KomplektyushaiTemp
		  {
		    int ID_Komplektyushai;
		    char Naimenovanie[50];        
	        int Cena_Komplektyushei;
	      };
	      KomplektyushaiTemp head;
	      while (fread(&head, sizeof(head), 1, in)) 
		  {
            char * tempStr = new char[];
		    strcpy(tempStr, head.Naimenovanie);
		    addKomplektyushai(head.ID_Komplektyushai, tempStr, head.Cena_Komplektyushei);
	      }
	fclose(in);
	printKomplektyushai();	
}
		void List::inFileMaster(char * path) 
		{
		  FILE *in;
	      if ((in = fopen(path,"rb")) == NULL) 
		  {
		    cout << "���� " << path << "�� ����� ���� ������!" << endl;
		    return;
	      }
	      struct MasterTemp
		  {
		    int ID_Master;
		    char FIO[50];        
	        int Zarplata;
	      };
	      MasterTemp head;
	      while (fread(&head, sizeof(head), 1, in)) 
		  {
			char * tempStr = new char[];
		    strcpy(tempStr, head.FIO);
		    addMaster(head.ID_Master, tempStr, head.Zarplata);
	      }
	fclose(in);
	printMaster();	
}
		void List::inFileMesto_Hranenia(char * path) 
		{
		  FILE *in;
	      if ((in = fopen(path,"rb")) == NULL) 
		  {
		    cout << "���� " << path << "�� ����� ���� ������!" << endl;
		    return;
	      }
	      struct Mesto_HraneniaTemp
		  {
		    int ID_Mesto_Hranenia;
		    int ID_Sklad;
            int ID_Komplektyushai;
            int Kolichestvo_Komplektyushih;
	      };
	      Mesto_HraneniaTemp head;
	      while (fread(&head, sizeof(head), 1, in)) 
		  {
		    addMesto_Hranenia(head.ID_Mesto_Hranenia, head.ID_Sklad, head.ID_Komplektyushai, head.Kolichestvo_Komplektyushih);
	      }
	fclose(in);
	printMesto_Hranenia();	
}
		void List::inFileRemont(char * path) 
		{
		  FILE *in;
	      if ((in = fopen(path,"rb")) == NULL) 
		  {
		    cout << "���� " << path << "�� ����� ���� ������!" << endl;
		    return;
	      }
	      struct RemontTemp
		  {
		    int ID_Remont;
		    int ID_Vid_Remonta;
	        int Stoimost;
            int ID_Master;
            Data Data_Remonta;
	      };
	      RemontTemp head;
	      while (fread(&head, sizeof(head), 1, in)) 
		  {
		    addRemont(head.ID_Remont, head.ID_Vid_Remonta, head.Stoimost, head.ID_Master, head.Data_Remonta);
	      }
	fclose(in);
	printRemont();	
}
		void List::inFileIspolzyemie_Komplektyushie(char * path) 
		{
		  FILE *in;
	      if ((in = fopen(path,"rb")) == NULL) 
		  {
		    cout << "���� " << path << "�� ����� ���� ������!" << endl;
		    return;
	      }
	      struct Ispolzyemie_KomplektyushieTemp
		  {
		    int ID_Ispolzyemie_Komplektyushie;
			int ID_Komplektyushai;
	        int Kolichestvo;
            int ID_Remont;
	      };
	      Ispolzyemie_KomplektyushieTemp head;
	      while (fread(&head, sizeof(head), 1, in)) 
		  {
		    addIspolzyemie_Komplektyushie(head.ID_Ispolzyemie_Komplektyushie, head.ID_Komplektyushai, head.Kolichestvo, head.ID_Remont);
	      }
	fclose(in);
	printIspolzyemie_Komplektyushie();	
}
		void List::inFileVid_Remonta(char * path) 
		{
		  FILE *in;
	      if ((in = fopen(path,"rb")) == NULL) 
		  {
		    cout << "���� " << path << "�� ����� ���� ������!" << endl;
		    return;
	      }
	      struct Vid_RemontaTemp
		  {
		    int ID_Vid_Remonta;
			char Nazvanie[50];
	      };
	      Vid_RemontaTemp head;
	      while (fread(&head, sizeof(head), 1, in)) 
		  {
			char * tempStr = new char[];
		    strcpy(tempStr, head.Nazvanie);
		    addVid_Remonta(head.ID_Vid_Remonta, tempStr);
	      }
	fclose(in);
	printVid_Remonta();	
}
		//  ������������� ID
		bool List::existIDSklad(int ID) 
		{
          for (Sklad *temp = Sklad_L.head; temp != NULL; temp = temp->next) 
	      {
		        if (temp->ID_Sklad == ID)
				{
			    return true;
		        }
          }
          return false;
        }
		bool List::existIDKomplektyushai(int ID) 
		{
          for (Komplektyushai *temp = Komplektyushai_L.head; temp != NULL; temp = temp->next) 
	      {
		        if (temp->ID_Komplektyushai == ID)
				{
			    return true;
		        }
          }
          return false;
        }
		bool List::existIDMaster(int ID) 
		{
          for (Master *temp = Master_L.head; temp != NULL; temp = temp->next) 
	      {
		        if (temp->ID_Master == ID)
				{
			    return true;
		        }
          }
          return false;
        }
		bool List::existIDMesto_Hranenia(int ID) 
		{
          for (Mesto_Hranenia *temp = Mesto_Hranenia_L.head; temp != NULL; temp = temp->next) 
	      {
		        if (temp->ID_Mesto_Hranenia == ID)
				{
			    return true;
		        }
          }
          return false;
        }
		bool List::existIDRemont(int ID) 
		{
          for (Remont *temp = Remont_L.head; temp != NULL; temp = temp->next) 
	      {
		        if (temp->ID_Remont == ID)
				{
			    return true;
		        }
          }
          return false;
        }
		bool List::existIDIspolzyemie_Komplektyushie(int ID) 
		{
          for (Ispolzyemie_Komplektyushie *temp = Ispolzyemie_Komplektyushie_L.head; temp != NULL; temp = temp->next) 
	      {
		        if (temp->ID_Ispolzyemie_Komplektyushie == ID)
				{
			    return true;
		        }
          }
          return false;
        }
		bool List::existIDVid_Remonta(int ID) 
		{
          for (Vid_Remonta *temp = Vid_Remonta_L.head; temp != NULL; temp = temp->next) 
	      {
		        if (temp->ID_Vid_Remonta == ID)
				{
			    return true;
		        }
          }
          return false;
        }
		// ���������� ID
		void List::findByIDSklad(int ID_S, int KolichestvoSkladskihMest, char *NathvanieSklada) 
		{
	      for (Sklad *temp = Sklad_L.head; temp != NULL; temp = temp->next) 
		  {
		    if (temp->ID_Sklad == ID_S) 
			{
			    temp->Kolichestvo_Skladskih_Mest = KolichestvoSkladskihMest;
			    temp->Nathvanie_Sklada = NathvanieSklada;
				break;
		    }
	      }
        }
		void List::findByIDKomplektyushai(int ID_K, char *Naim, int CenaKomplektyushei) 
		{
	      for (Komplektyushai *temp = Komplektyushai_L.head; temp != NULL; temp = temp->next) 
		  {
		    if (temp->ID_Komplektyushai == ID_K) 
			{
			    temp->Naimenovanie = Naim;
			    temp->Cena_Komplektyushei = CenaKomplektyushei;
				break;
		    }
	      }
        }
		void List::findByIDMaster(int ID_m, char *F_I_O, int Zarplat) 
		{
	      for (Master *temp = Master_L.head; temp != NULL; temp = temp->next) 
		  {
		    if (temp->ID_Master == ID_m) 
			{
			    temp->FIO = F_I_O;
			    temp->Zarplata = Zarplat;
				break;
		    }
	      }
        }
		void List::findByIDMesto_Hranenia(int ID_me, int ID_S, int ID_K, int KolichestvoKomplektyushih) 
		{
	      for (Mesto_Hranenia *temp = Mesto_Hranenia_L.head; temp != NULL; temp = temp->next) 
		  {
		    if (temp->ID_Mesto_Hranenia == ID_me) 
			{
			    temp->ID_Sklad = ID_S;
			    temp->ID_Komplektyushai = ID_K;
                temp->Kolichestvo_Komplektyushih = KolichestvoKomplektyushih;
				break;
		    }
	      }
        }
		void List::findByIDRemont(int ID_R, int ID_V, int Stoim, int ID_M, Data data) 
		{
	      for (Remont *temp = Remont_L.head; temp != NULL; temp = temp->next) 
		  {
		    if (temp->ID_Remont == ID_R) 
			{
			    temp->ID_Vid_Remonta = ID_V;
			    temp->Stoimost = Stoim;
                temp->ID_Master = ID_M;
                temp->Data_Remonta.month = data.month;
			    temp->Data_Remonta.year = data.year;
				break;
		    }
	      }
        }
		void List::findByIDIspolzyemie_Komplektyushie(int ID_I, int ID_K, int Kol, int ID_R) 
		{
	      for (Ispolzyemie_Komplektyushie *temp = Ispolzyemie_Komplektyushie_L.head; temp != NULL; temp = temp->next) 
		  {
		    if (temp->ID_Ispolzyemie_Komplektyushie == ID_I) 
			{
			    temp->ID_Komplektyushai = ID_K;
			    temp->Kolichestvo = Kol;
                temp->ID_Remont = ID_R;
				break;
            }
	      }
        }
		void List::findByIDVid_Remonta(int ID_V, char *Nazv) 
		{
	      for (Vid_Remonta *temp = Vid_Remonta_L.head; temp != NULL; temp = temp->next) 
		  {
		    if (temp->ID_Vid_Remonta == ID_V) 
			{
			    temp->Nazvanie = Nazv;
				break;
            }
	      }
        }
		// ��������
		void List::delByValueMesto_Hranenia(int ID) 
		{
	         if (Mesto_Hranenia_L.head == NULL)
			 {
		     return;
	         }
	       if (Mesto_Hranenia_L.head->ID_Mesto_Hranenia == ID) 
			  {
			   	 Mesto_Hranenia *temp = Mesto_Hranenia_L.head;
			     Mesto_Hranenia_L.head = Mesto_Hranenia_L.head->next;
			     delete temp;
		     } 
			 else 
		     {
				 Mesto_Hranenia *prevNode = Mesto_Hranenia_L.head;
	         while (prevNode->next != NULL)
			 {
		        if (prevNode->next->ID_Mesto_Hranenia == ID) 
				{
			       Mesto_Hranenia *temp = prevNode->next;
			       prevNode->next = prevNode->next->next;
			       delete temp;
		     return;
		        } 
				else 
				{
			    prevNode = prevNode->next;
		        }
	         }
		     }
	                
         }
		void List::delByValueMesto_Hranenia2(int ID) 
		{
	         if (Mesto_Hranenia_L.head == NULL)
			 {
		     return;
	         }
	       if (Mesto_Hranenia_L.head->ID_Sklad == ID) 
			  {
			   	 Mesto_Hranenia *temp = Mesto_Hranenia_L.head;
			     Mesto_Hranenia_L.head = Mesto_Hranenia_L.head->next;
			     delete temp;
		     } 
			 else 
		     {
				 Mesto_Hranenia *prevNode = Mesto_Hranenia_L.head;
	         while (prevNode->next != NULL)
			 {
		        if (prevNode->next->ID_Sklad == ID) 
				{
			       Mesto_Hranenia *temp = prevNode->next;
			       prevNode->next = prevNode->next->next;
			       delete temp;
		     return;
		        } 
				else 
				{
			    prevNode = prevNode->next;
		        }
	         }
		     }
	                
         }
		void List::delByValueMesto_Hranenia3(int ID) 
		{
	         if (Mesto_Hranenia_L.head == NULL)
			 {
		     return;
	         }
	       if (Mesto_Hranenia_L.head->ID_Komplektyushai == ID) 
			  {
			   	 Mesto_Hranenia *temp = Mesto_Hranenia_L.head;
			     Mesto_Hranenia_L.head = Mesto_Hranenia_L.head->next;
			     delete temp;
		     } 
			 else 
		     {
				 Mesto_Hranenia *prevNode = Mesto_Hranenia_L.head;
	         while (prevNode->next != NULL)
			 {
		        if (prevNode->next->ID_Komplektyushai == ID) 
				{
			       Mesto_Hranenia *temp = prevNode->next;
			       prevNode->next = prevNode->next->next;
			       delete temp;
		     return;
		        } 
				else 
				{
			    prevNode = prevNode->next;
		        }
	         }
		     }
	                
         }
		void List::delByValueSklad(int ID) 
		{
			if (Sklad_L.head == NULL)
			 {
		     return;
	         }
	          if (Sklad_L.head->ID_Sklad == ID) 
			  {
			    
				 delByValueMesto_Hranenia2(ID);
				    		    
			     Sklad *temp = Sklad_L.head;
			     Sklad_L.head = Sklad_L.head->next;
			     delete temp;
		     } 
			 else 
		     {
			   
		     
	        
	         
	         Sklad *prevNode = Sklad_L.head;
	         while (prevNode->next != NULL)
			 {
		        if (prevNode->next->ID_Sklad == ID) 
				{
			      
					     delByValueMesto_Hranenia2(ID);
				    
			       Sklad *temp = prevNode->next;
			       prevNode->next = prevNode->next->next;
			       delete temp;
		        } 
				else 
				{
			    prevNode = prevNode->next;
		        }
	         }
			  }
         }
		void List::delByValueKomplektyushai(int ID)

		{
	        if (Komplektyushai_L.head == NULL)
			 {
		     return;
	         }
		      if (Komplektyushai_L.head->ID_Komplektyushai == ID) 
			  {
			    
					    delByValueMesto_Hranenia3(ID);
				   
				for (Ispolzyemie_Komplektyushie *temp = Ispolzyemie_Komplektyushie_L.head; temp != NULL; temp = temp->next) 
				{
				    if (temp->ID_Komplektyushai == ID) 
				    {
				 	   temp->ID_Komplektyushai = 0;
				    }
			    }

			     Komplektyushai *temp = Komplektyushai_L.head;
			     Komplektyushai_L.head = Komplektyushai_L.head->next;
			     delete temp;
		     } 
			 else 
		     {
			  
	         
	         Komplektyushai *prevNode = Komplektyushai_L.head;
	         while (prevNode->next != NULL)
			 {
		        if (prevNode->next->ID_Komplektyushai == ID) 
				{
			       
					    delByValueMesto_Hranenia3(ID);
				    
				for (Ispolzyemie_Komplektyushie *temp = Ispolzyemie_Komplektyushie_L.head; temp != NULL; temp = temp->next) 
				{
				    if (temp->ID_Komplektyushai == ID) 
				    {
				 	   temp->ID_Komplektyushai = 0;
				    }
			    }
			       Komplektyushai *temp = prevNode->next;
			       prevNode->next = prevNode->next->next;
			       delete temp;
		        } 
				else 
				{
			    prevNode = prevNode->next;
		        }
	         }
         }
		}
		void List::delByValueMaster(int ID) 
		{
	       if (Master_L.head == NULL)
			 {
		     return;
	         }
		      if (Master_L.head->ID_Master == ID) 
			  {
			    for (Remont *temp = Remont_L.head; temp != NULL; temp = temp->next) 
				{
				   if (temp->ID_Master == ID)
				    {
					    temp->ID_Master = 0;
				    }
			    }
				 Master *temp = Master_L.head;
			     Master_L.head = Master_L.head->next;
			     delete temp;
		     } 
			 else 
		     {
			
	         
	         Master *prevNode = Master_L.head;
	         while (prevNode->next != NULL)
			 {
		        if (prevNode->next->ID_Master == ID) 
				{
			       for (Master *temp = Master_L.head; temp != NULL; temp = temp->next) 
				   {
				       if (temp->ID_Master == ID) 
					   {
					    temp->ID_Master = 0;
				       }
			       }
				   Master *temp = prevNode->next;
			       prevNode->next = prevNode->next->next;
			       delete temp;
		        } 
				else 
				{
			    prevNode = prevNode->next;
		        }
	         }
         }
		}
		void List::delByValueIspolzyemie_Komplektyushie(int ID) 
		{
	        if (Ispolzyemie_Komplektyushie_L.head == NULL)
			 {
		     return;
	         }
		      if (Ispolzyemie_Komplektyushie_L.head->ID_Ispolzyemie_Komplektyushie == ID) 
			  {
			     Ispolzyemie_Komplektyushie *temp = Ispolzyemie_Komplektyushie_L.head;
			     Ispolzyemie_Komplektyushie_L.head = Ispolzyemie_Komplektyushie_L.head->next;
			     delete temp;
		     } 
			 else 
		     {
			 
	         
	         Ispolzyemie_Komplektyushie *prevNode = Ispolzyemie_Komplektyushie_L.head;
	         while (prevNode->next != NULL)
			 {
		        if (prevNode->next->ID_Ispolzyemie_Komplektyushie == ID) 
				{
			       Ispolzyemie_Komplektyushie *temp = prevNode->next;
			       prevNode->next = prevNode->next->next;
			       delete temp;
		        } 
				else 
				{
			    prevNode = prevNode->next;
		        }
	         }
         }
		}
			void List::delByValueIspolzyemie_Komplektyushie2(int ID) 
		{
	        if (Ispolzyemie_Komplektyushie_L.head == NULL)
			 {
		     return;
	         }
		      if (Ispolzyemie_Komplektyushie_L.head->ID_Remont == ID) 
			  {
			     Ispolzyemie_Komplektyushie *temp = Ispolzyemie_Komplektyushie_L.head;
			     Ispolzyemie_Komplektyushie_L.head = Ispolzyemie_Komplektyushie_L.head->next;
			     delete temp;
		     } 
			 else 
		     {
			 
	         
	         Ispolzyemie_Komplektyushie *prevNode = Ispolzyemie_Komplektyushie_L.head;
	         while (prevNode->next != NULL)
			 {
		        if (prevNode->next->ID_Remont == ID) 
				{
			       Ispolzyemie_Komplektyushie *temp = prevNode->next;
			       prevNode->next = prevNode->next->next;
			       delete temp;
		        } 
				else 
				{
			    prevNode = prevNode->next;
		        }
	         }
         }
		}
		void List::delByValueRemont(int ID) 
		{
	       if (Remont_L.head == NULL)
			 {
		     return;
	         }
		      if (Remont_L.head->ID_Remont == ID) 
			  {
			    for (Ispolzyemie_Komplektyushie *temp = Ispolzyemie_Komplektyushie_L.head; temp != NULL; temp = temp->next) 
				{
				   if (temp->ID_Remont == ID)
				    {
					   delByValueIspolzyemie_Komplektyushie2( ID);
				    }
			    }
			     Remont *temp = Remont_L.head;
			     Remont_L.head = Remont_L.head->next;
			     delete temp;
		     } 
			 else 
		     {
			   
	         
	         Remont *prevNode = Remont_L.head;
	         while (prevNode->next != NULL)
			 {
		        if (prevNode->next->ID_Remont == ID) 
				{
			       for (Ispolzyemie_Komplektyushie *temp = Ispolzyemie_Komplektyushie_L.head; temp != NULL; temp = temp->next) 
				   {
				       if (temp->ID_Remont == ID) 
					   {
					    delByValueIspolzyemie_Komplektyushie2(ID);
				       }
			       }
			       Remont *temp = prevNode->next;
			       prevNode->next = prevNode->next->next;
			       delete temp;
		        } 
				else 
				{
			    prevNode = prevNode->next;
		        }
	         }
			  }
         }
		void List::delByValueVid_Remonta(int ID) 
		{
	       if (Vid_Remonta_L.head == NULL)
			 {
		     return;
	         }
		      if (Vid_Remonta_L.head->ID_Vid_Remonta == ID) 
			  {
			    for (Remont *temp = Remont_L.head; temp != NULL; temp = temp->next) 
				{
				   if (temp->ID_Vid_Remonta == ID)
				    {
					    temp->ID_Vid_Remonta = 0;
				    }
			    }
				 Master *temp = Master_L.head;
			     Master_L.head = Master_L.head->next;
			     delete temp;
		     } 
			 else 
		     {
			   
	         
	        
	         Vid_Remonta *prevNode = Vid_Remonta_L.head;
	         while (prevNode->next != NULL)
			 {
		        if (prevNode->next->ID_Vid_Remonta == ID) 
				{
			       for (Remont *temp = Remont_L.head; temp != NULL; temp = temp->next) 
				   {
				       if (temp->ID_Vid_Remonta == ID) 
					   {
					    temp->ID_Vid_Remonta = 0;
				       }
			       }
				   Vid_Remonta *temp = prevNode->next;
			       prevNode->next = prevNode->next->next;
			       delete temp;
		        } 
				else 
				{
			    prevNode = prevNode->next;
		        }
	         }
         }
		}
		// ��������
		// ���� �������������
		int RecordsComponents(int ID)
		{
			int IDv;
			int K;
			int summa = 0;
			
         for (Komplektyushai *temp = Komplektyushai_L.head; temp != NULL; temp = temp->next) 
		  {

		   for (Mesto_Hranenia *temp2 = Mesto_Hranenia_L.head; temp2 != NULL; temp2 = temp2->next) 
			   {
				     IDv = temp->ID_Komplektyushai;
				    if ((temp2->ID_Sklad == ID) && (temp2->ID_Komplektyushai == IDv))
						{
						K = temp2->Kolichestvo_Komplektyushih;
							summa = summa + K;
						}
				       
			}
			  cout << "���������� " << temp->Naimenovanie << " = " << summa << endl; 
		}
		 return summa;
		}
		//�������� 
		 bool List::existKomplektyish(int cost, int IDCat)
	 		{
          for (Mesto_Hranenia *temp = Mesto_Hranenia_L.head; temp != NULL; temp = temp->next) 
	      {
			  
			  if (temp->ID_Komplektyushai == IDCat)
			  {
		        if ((temp->Kolichestvo_Komplektyushih) >= (cost))
				{
			    return true;
				
		        }
          }
		  }
          return false;
        }
		 // �������� �� ������ �������������
		void Recordskomplektyish(int cost, int IDCat)
		{
			int R;
			 for (Mesto_Hranenia *temp = Mesto_Hranenia_L.head; temp != NULL; temp = temp->next) 
			   {
			   if (temp->ID_Komplektyushai == IDCat)
			  {
				   
				   R=temp->Kolichestvo_Komplektyushih-cost;
				   temp->Kolichestvo_Komplektyushih=R;
			   }

			  }
		}

		// ������ ��  ���� ��� �������� �����
		bool List::isStartDate(Data dateStart, Data dateCheck) 
		{
	      if (dateStart.year < dateCheck.year) 
		  {
		    return true;
	      } 
		  else 
		  {
		    if (dateCheck.year == dateStart.year) 
			{
			if (dateStart.month < dateCheck.month) 
			{
				return true;
			}
			else
			{
				if (dateStart.month == dateCheck.month) 
				{
					
						return true;
					 
						}
						return false;
					}
			}

				
		}

		return false;
	}



	// ������ �� ���� ��� ��������� end
     bool List::isEndDate(Data dateEnd, Data dateCheck) 
	 {
	    if (dateEnd.year > dateCheck.year)
		{
		return true;
	    } else 
		{
		if (dateCheck.year == dateEnd.year) 
		{
			if (dateEnd.month > dateCheck.month) 
			{
				return true;
			}
			else
			{
				if (dateEnd.month == dateCheck.month)
				{
					
						return true;
									
				}

				return false;
			}
		}

		return false;
	}
}
	 // ���� ������� �� ����� �������
	 void Vid_RemontaMoney(Data dateStart, Data dateEnd)
	{
		int IDv;
		int Money;
		//int K;
          for (Vid_Remonta *temp = Vid_Remonta_L.head; temp != NULL; temp = temp->next) 
		  {
			  Money=0;
		  for (Remont *temp2 = Remont_L.head; temp2 != NULL; temp2 = temp2->next) 
		  {
			  IDv = temp->ID_Vid_Remonta;
			  if (temp2->ID_Vid_Remonta == IDv) 
			  {
				  if ((isStartDate(dateStart, temp2->Data_Remonta)) && (isEndDate(dateEnd, temp2->Data_Remonta)))
				  {
                  // K = temp2->Stoimost;
                   Money=Money+temp2->Stoimost;
				  }
			  }
	      }
		  cout << "������� �  " << temp->Nazvanie << " = " << Money << endl;
		  }
		  
	}
	  // ���� ������� �� ��������
	 void MasterMoney(Data dateStart, Data dateEnd)
	{
		int IDv;
		int Money;
		  for (Master *temp = Master_L.head; temp != NULL; temp = temp->next) 
		  {
			  Money=0;
		  for (Remont *temp2 = Remont_L.head; temp2 != NULL; temp2 = temp2->next) 
		  {
			  IDv = temp->ID_Master;
			  if (temp2->ID_Master == IDv) 
			  {
				  if ((isStartDate(dateStart, temp2->Data_Remonta)) && (isEndDate(dateEnd, temp2->Data_Remonta)))
				  {
                   Money=Money+temp2->Stoimost;
				  }
			  }
	      }
		  cout << "������� �  " << temp->FIO << " = " << Money << endl;
		  }
		  	}
	 	  // ���� �� ����� �� ������
	  bool List::existMesta(int cost, int IDCat)
	  {		  
		  int kol=0;
		  int r;
			    
		  for (Mesto_Hranenia *temp = Mesto_Hranenia_L.head; temp != NULL; temp = temp->next) 
			   {
			   if (temp->ID_Sklad == IDCat)
			  {
				   kol=kol+temp->Kolichestvo_Komplektyushih;
				    
				   	   }
		  }
			r=kol+cost; 
		    for (Sklad *temp2 = Sklad_L.head; temp2 != NULL; temp2 = temp2->next) 
	      {      
			  if (temp2->ID_Sklad == IDCat)
			  {
		         if	(temp2->Kolichestvo_Skladskih_Mest >= r)
		       { 
				   
					return true;
				
				}
			  }
				 
          }
          return false;
        }
	};	
		
		



void addCharToEnd(char *&str, char z) {
	int len = strlen(str);
	char *newStr = new char[len + 1 + 1];
	strcpy(newStr, str);
	newStr[len] = z;
	newStr[len + 1] = 0;
	delete[] str;
	str = newStr;
} 

void delCharToEnd(char *&str) {
	int len = strlen(str);
	char *newStr = new char[len];
	memmove (newStr, str, len * sizeof(char));
	newStr[len - 1] = 0;
	delete[] str;
	str = newStr;
}
void inputStr(char *&str) {
	str = new char[1];
	str[0] = 0;
	do {
		char c = _getch();
		if ((c == '\n') || (c == '\r')) {
			break;
		}
		if ((c == '\b') && (strlen(str) > 0)) {
			printf("\b \b");
			delCharToEnd(str);
		} else {
			printf("%c", c);
			addCharToEnd(str, c);
		}
	} while (true);
}

int myAtoi (char * str) 
		{
	    int length = 0;
	       while (str[length] != '\0') 
		   {
		    if (!isdigit(str[length]))
		     {
			  return 0;
		     }
		    length++;
	       }
	       return atoi(str);
        }
Data inputDate() 
		{
	    Data data;

	     cout << "������� �����: ";
	     char temp2[40];
	     do 
		 {
		    cin.getline(temp2, 40);
		    if ((myAtoi(temp2) <= 0) || (myAtoi(temp2) > 12)) {
			cout << "������ �������� ������" << endl << "���������� �����: ";
		 } 
			else 
		 {
			break;
		 }
	   }
		 while (true);
	     data.month = myAtoi(temp2);

	     cout << "������� ���: ";
	     char temp3[80];
	     do 
		 {
		   cin.getline(temp3, 80);
		   if ((myAtoi(temp3) <= 0) || (myAtoi(temp3) < 1994) || (myAtoi(temp3) > 2014))
		   {
			cout << "������ �����" << endl << "���������� �����: ";
		   } else
		   {
			break;
		   }
	     }
		 while (true);
	     data.year = myAtoi(temp3);

	  return data;
     }
		
void menu(List &st) 
					{
						char *value;
        char *name;
		int ID;
        int IDCat;
        int IDTov;
        int cost;
		bool isExitFromCat = false;
        do  //��������� ���� !isExitFromCat
	{                                   
		cout << "�������� ��������:" << endl;
		cout << "1. �����" << endl;
		cout << "2. �������������" << endl;
		cout << "3. ������" << endl;
		cout << "4. ����� ��������" << endl;
        cout << "5. ��� �������" << endl;
		cout << "6. ������" << endl;
	    cout << "7. ������������ �������������" << endl;
	   	cout << "8. ������� �����" << endl;
		cout << "9. ���������" << endl;
		cout << "10. ���������" << endl;
		cout << "11. �����" << endl;

      do 
          {
		   inputStr(value);
		   cout << endl;
		   if ((myAtoi(value) >= 1) && (myAtoi(value) <= 11)) 
			{
				break;
			}
		   cout << endl << "���������� ��� ���: " << endl;
		  } 
	  while (true);
	  if (myAtoi(value) == 9)
	    {
			system ("cls");
		}
	  switch(myAtoi(value)) 
		{
		case 1:
			cout << "�� ������� �����" << endl;

			do 
			{
				isExitFromCat = false;
				cout << "�������� ��������:" << endl;
				cout << "1. �������� �������" << endl;
				cout << "2. �������� �������" << endl;
				cout << "3. ������� �������" << endl;
				cout << "4. ������ � ������ " << endl;
				cout << "5. ��������� � �������� ����" << endl;
				do 
				{
					inputStr(value);
					cout << endl;
					if ((myAtoi(value) >= 1) && (myAtoi(value) <= 5))
					{
						break;
					}
					cout << endl << "���������� ��� ���: " << endl;
				}
				while (true);
				switch(myAtoi(value)) 
				{
				
				case 1:
					cout << "�� ������� ���������� ��������" << endl;
					do
					{
						srand(time(NULL));
						ID = rand() % 100 + 1;
						cout << endl;
						if (!st.existIDSklad(ID))
						{
							break;
						}
					}
					while(true);

					cout << "������� ���������� ��������� ����" << endl;
					do 
					{
						inputStr(value);
						cout << endl;
						if (myAtoi(value) == 0) 
						{
							cout << "������ ����� ���������� ��������� ����" << endl << "���������� ���: ";
						} 
						else 
						{
							break;
						}
					}
					while (true);
					cost = myAtoi(value);
					cout << "������� �������� ������" << endl;
					inputStr(name);
					cout << endl;

					st.addSklad(ID, cost, name);
					break;
				case 2:
					cout << "�� ������� ��������� ��������" << endl;
					cout << "������� id" << endl;

					do 
					{
						inputStr(value);
						cout << endl;
						if (!st.existIDSklad(myAtoi(value))) 
						{
							cout << "������ ����� id" << endl << "���������� ��� ���: ";
						} else
						{
							break;
						}
					} 
					while (true);
					ID = myAtoi(value);
					cout << "������� ����� �������� ������" << endl;
					inputStr(name);
					cout << "������� ���������� ��������� ����" << endl;
					do
					{
						inputStr(value);
						cout << endl;
						if (myAtoi(value) == 0)
						{
							cout << "������ ����� ���������� ����" << endl << "���������� �����: ";
						} else 
						{
							break;
						}
					} 
					while (true);
					cost = myAtoi(value);

					st.findByIDSklad(ID, cost, name);
					break;
                case 3:
					cout << "�� ������� �������� ��������" << endl;
					cout << "������� id" << endl;
					do {
						inputStr(value);
						cout << endl;
						if (!st.existIDSklad(myAtoi(value))) 
						{
							cout << "������ ����� id" << endl << "���������� �����: ";
						} 
						else 
						{
							break;
						}
					   } 
					while (true);
					st.delByValueSklad(myAtoi(value));
					break;
                case 4:
					st.printSklad();
					break;
                 case 5:
					isExitFromCat = true;
					break;
				}
			 }
			 while (!isExitFromCat);
			 isExitFromCat = false;
			 cout << "�����" << endl;
			 break;
   case 2:
        cout << "�� ������� ��������������" << endl;
		do 
		{
		     isExitFromCat = false;
		     cout << "�������� ��������:" << endl;
		     
			 cout << "1. �������� �������" << endl;
			 cout << "2. �������� �������" << endl;
			 cout << "3. ������� �������" << endl;
			 cout << "4. ������ � ������ " << endl;
			 cout << "5. ��������� � �������� ����" << endl;
			 do 
			 {
				inputStr(value);
				cout << endl;
				if ((myAtoi(value) >= 1) && (myAtoi(value) <= 5))
				{
						break;
				}
				cout << endl << "���������� �����: " << endl;
			 } 
			 while (true);
			 switch(myAtoi(value))
			 {
              
			  case 1:
					cout << "�� ������� ���������� ��������" << endl;
					do
					{
						srand(time(NULL));
						ID = rand() % 100 + 1;
						cout << endl;
						if (!st.existIDKomplektyushai(ID))
						{
							break;
						}
					}
					while(true);
					cout << "������� ������������" << endl;
					inputStr(name);
					cout << endl;
					cout << "������� ����" << endl;
					do 
					{
						inputStr(value);
						cout << endl;
						if (myAtoi(value) == 0) 
						{
							cout << "������ ����� " << endl << "���������� ���: ";
						} else {
							break;
						}
					}
					while (true);
					cost = myAtoi(value);
					st.addKomplektyushai (ID , name, cost);
					break;
			   case 2:
					cout << "�� ������� ��������� ��������" << endl;
					cout << "������� id" << endl;

					do 
					{
						inputStr(value);
						cout << endl;
						if (!st.existIDKomplektyushai(myAtoi(value))) 
						{
							cout << "������ ����� id" << endl << "���������� ��� ���: ";
						} else
						{
							break;
						}
					} 
					while (true);
					ID = myAtoi(value);
					cout << "������� ����� ������������" << endl;
					inputStr(name);
					cout << "������� ����" << endl;
					do
					{
						inputStr(value);
						cout << endl;
						if (myAtoi(value) == 0)
						{
							cout << "������ ����� " << endl << "���������� �����: ";
						} else 
						{
							break;
						}
					} 
					while (true);
					cost = myAtoi(value);

					st.findByIDKomplektyushai(ID, name, cost);
					break;
			   case 3:
					cout << "�� ������� �������� ��������" << endl;
					cout << "������� id" << endl;
					do {
						inputStr(value);
						cout << endl;
						if (!st.existIDKomplektyushai(myAtoi(value))) 
						{
							cout << "������ ����� id" << endl << "���������� �����: ";
						} 
						else 
						{
							break;
						}
					   } 
					while (true);
					st.delByValueKomplektyushai(myAtoi(value));
					break;
                 case 4:
					st.printKomplektyushai();
					break;
                 case 5:
					isExitFromCat = true;
					break;
				}
			 }

			 while (!isExitFromCat);
			 isExitFromCat = false;
			 cout << "�����" << endl;
			 break;
		case 3:
                 cout << "�� ������� ������" << endl;
		         do 
		         {
		              isExitFromCat = false;
		              cout << "�������� ��������:" << endl;
		              
			          cout << "1. �������� �������" << endl;
			          cout << "2. �������� �������" << endl;
			          cout << "3. ������� �������" << endl;
			          
			          cout << "4. ������ � ������ " << endl;
			          cout << "5. ��������� � �������� ����" << endl;
			          do 
			          {
				         inputStr(value);
				         cout << endl;
				         if ((myAtoi(value) >= 1) && (myAtoi(value) <= 5))
				         {
						     break;
				         }
				         cout << endl << "���������� �����: " << endl;
			          } 
			          while (true);
			          switch(myAtoi(value))
			          {
                        
			            case 1:
					           cout << "�� ������� ���������� ��������" << endl;
							   do
					           {
						         srand(time(NULL));
						         ID = rand() % 100 + 1;
						         cout << endl;
						         if (!st.existIDMaster(ID))
						       {
						         break;
						       }
					           }
					           while(true);
					           cout << "������� ���" << endl;
					           inputStr(name);
					           cout << endl;
					           cout << "������� ��������" << endl;
					           do 
					           {
					            	inputStr(value);
						            cout << endl;
						            if (myAtoi(value) == 0) 
						            {
						             	cout << "������ ����� " << endl << "���������� ���: ";
						            } 
									else 
									{
							        break;
						            }
					           }
					           while (true);
					           cost = myAtoi(value);
					st.addMaster (ID ,name, cost); 
					break;
			   case 2:
					cout << "�� ������� ��������� ��������" << endl;
					cout << "������� id" << endl;

					do 
					{
						inputStr(value);
						cout << endl;
						if (!st.existIDMaster(myAtoi(value))) 
						{
							cout << "������ ����� id" << endl << "���������� ��� ���: ";
						} 
						else
						{
							break;
						}
					} 
					while (true);
					ID = myAtoi(value);
					cout << "������� ����� ���" << endl;
					inputStr(name);
					cout << "������� ��������" << endl;
					do
					{
						inputStr(value);
						cout << endl;
						if (myAtoi(value) == 0)
						{
							cout << "������ ����� " << endl << "���������� �����: ";
						} else 
						{
							break;
						}
					} 
					while (true);
					cost = myAtoi(value);

					st.findByIDMaster(ID, name, cost) ;
					break;
			   case 3:
					cout << "�� ������� �������� ��������" << endl;
					cout << "������� id" << endl;
					do {
						inputStr(value);
						cout << endl;
						if (!st.existIDMaster(myAtoi(value))) 
						{
							cout << "������ ����� id" << endl << "���������� �����: ";
						} 
						else 
						{
							break;
						}
					   } 
					while (true);
					st.delByValueMaster(myAtoi(value));
					break;
                
                 case 4:
					st.printMaster();
					break;
                 case 5:
					isExitFromCat = true;
					break;
				}
			 }

			 while (!isExitFromCat);
			 isExitFromCat = false;
			 cout << "�����" << endl;
			 break;
		case 4:
                 cout << "�� ������� ����� ��������" << endl;
		         do 
		         {
		              isExitFromCat = false;
		              cout << "�������� ��������:" << endl;
		              
			          cout << "1. �������� �������" << endl;
			          cout << "2. �������� �������" << endl;
			          cout << "3. ������� �������" << endl;
			          
			          cout << "4. ������ � ������ " << endl;
			          cout << "5. ��������� � �������� ����" << endl;
			          do 
			          {
				         inputStr(value);
				         cout << endl;
				         if ((myAtoi(value) >= 1) && (myAtoi(value) <= 5))
				         {
						     break;
				         }
				         cout << endl << "���������� �����: " << endl;
			          } 
			          while (true);
			          switch(myAtoi(value))
			          {
                        
			            case 1:
					           cout << "�� ������� ���������� ��������" << endl;
							   do
					           {
						         srand(time(NULL));
						         ID = rand() % 100 + 1;
						         cout << endl;
						         if (!st.existIDMesto_Hranenia(ID))
						       {
						         break;
						       }
					           }
					           while(true);
					           cout << "������� ID ������" << endl;
					            do 
								{
						            inputStr(value);
						            cout << endl;
						            if (!st.existIDSklad(myAtoi(value))) {
						        	cout << "������ �����" << endl << "���������� �����: ";
						            } 
							        else 
							        {
							         break;
						            }
					           }
								while (true);
					            IDCat = myAtoi(value);
								cout << "������� ID ������������" << endl;
					            do 
								{
						            inputStr(value);
						            cout << endl;
						            if (!st.existIDKomplektyushai (myAtoi(value))) {
						        	cout << "������ �����" << endl << "���������� �����: ";
						            } 
							        else 
							        {
							         break;
						            }
					           }
								while (true);
					            IDTov = myAtoi(value);
					           cout << "������� ���������� �������������" << endl;
					           do 
					           {
					            	inputStr(value);
						            cout << endl;
									cost = myAtoi(value);
						             if (!st.existMesta(cost, IDCat))
                                     {
						        	cout << "������ �����" << endl << "���������� �����: ";
						             } 
							        else 
							        {
							         break;
						            }

					                
							   }
					           while (true);
					           
					st.addMesto_Hranenia (ID , IDCat, IDTov, cost); 
					break;
			   case 2:
					cout << "�� ������� ��������� ��������" << endl;
					cout << "������� id" << endl;

					do 
					{
						inputStr(value);
						cout << endl;
						if (!st.existIDMesto_Hranenia(myAtoi(value))) 
						{
							cout << "������ ����� id" << endl << "���������� ��� ���: ";
						} else
						{
							break;
						}
					} 
					while (true);
					ID = myAtoi(value);
					cout << "������� ID ������" << endl;
					do 
					{
						inputStr(value);
						cout << endl;
						if (!st.existIDSklad(myAtoi(value))) 
						{
							cout << "������ ����� id" << endl << "���������� ��� ���: ";
						} else
						{
							break;
						}
					} 
					while (true);
					IDCat = myAtoi(value);
					cout << "������� ID �������������" << endl;
					do 
					{
						inputStr(value);
						cout << endl;
						if (!st.existIDKomplektyushai(myAtoi(value))) 
						{
							cout << "������ ����� id" << endl << "���������� ��� ���: ";
						} else
						{
							break;
						}
					} 
					while (true);
					IDTov = myAtoi(value);
					cout << "������� ���������� �������������" << endl;
					do
					{
						inputStr(value);
						cout << endl;
						if (myAtoi(value) == 0)
						{
							cout << "������ ����� " << endl << "���������� �����: ";
						} else 
						{
							break;
						}
					} 
					while (true);
					cost = myAtoi(value);

					st.findByIDMesto_Hranenia(ID, IDCat, IDTov, cost) ;
					break;
			   case 3:
					cout << "�� ������� �������� ��������" << endl;
					cout << "������� id" << endl;
					do {
						inputStr(value);
						cout << endl;
						if (!st.existIDMesto_Hranenia(myAtoi(value))) 
						{
							cout << "������ ����� id" << endl << "���������� �����: ";
						} 
						else 
						{
							break;
						}
					   } 
					while (true);
					st.delByValueMesto_Hranenia(myAtoi(value));
					break;
                
                 case 4:
					st.printMesto_Hranenia();
					break;
                 case 5:
					isExitFromCat = true;
					break;
				}
			 }

			 while (!isExitFromCat);
			 isExitFromCat = false;
			 cout << "�����" << endl;
			 break;
	  case 5:
                 cout << "�� ������� ��� �������" << endl;
		         do 
		         {
		              isExitFromCat = false;
		              cout << "�������� ��������:" << endl;
		              
			          cout << "2. �������� �������" << endl;
			          cout << "3. �������� �������" << endl;
			          cout << "4. ������� �������" << endl;
			         
			          cout << "6. ������ � ������ " << endl;
			          cout << "7. ��������� � �������� ����" << endl;
			          do 
			          {
				         inputStr(value);
				         cout << endl;
				         if ((myAtoi(value) >= 1) && (myAtoi(value) <= 5))
				         {
						     break;
				         }
				         cout << endl << "���������� �����: " << endl;
			          } 
			          while (true);
			          switch(myAtoi(value))
			          {
                        
			            case 1:
					           cout << "�� ������� ���������� ��������" << endl;
							    do
					           {
						         srand(time(NULL));
						         ID = rand() % 100 + 1;
						         cout << endl;
						         if (!st.existIDVid_Remonta(ID))
						       {
						         break;
						       }
					           }
					           while(true);
					            cout << "������� ������������" << endl;
					            inputStr(name);
					           cout << endl;
						
					st.addVid_Remonta(ID, name)  ;
					break;
			   case 2:
					cout << "�� ������� ��������� ��������" << endl;
					cout << "������� id" << endl;

					do 
					{
						inputStr(value);
						cout << endl;
						if (!st.existIDVid_Remonta (myAtoi(value))) 
						{
							cout << "������ ����� id" << endl << "���������� ��� ���: ";
						} else
						{
							break;
						}
					} 
					while (true);
					ID = myAtoi(value);
					  cout << "������� ������������" << endl;
					            inputStr(name);
					           cout << endl;
					st.findByIDVid_Remonta(ID, name) ;
					break;
			   case 3:
					cout << "�� ������� �������� ��������" << endl;
					cout << "������� id" << endl;
					do {
						inputStr(value);
						cout << endl;
						if (!st.existIDVid_Remonta(myAtoi(value))) 
						{
							cout << "������ ����� id" << endl << "���������� �����: ";
						} 
						else 
						{
							break;
						}
					   } 
					while (true);
					st.delByValueVid_Remonta(myAtoi(value));
					break;
                 
                 case 4:
					st.printVid_Remonta();
					break;
                 case 5:
					isExitFromCat = true;
					break;
				}
			 }

			 while (!isExitFromCat);
			 isExitFromCat = false;
			 cout << "�����" << endl;
			 break;
	case 6:
                 cout << "�� ������� ������" << endl;
		         do 
		         {
		              isExitFromCat = false;
		              cout << "�������� ��������:" << endl;
		             
			          cout << "1. �������� �������" << endl;
			          cout << "2. �������� �������" << endl;
			          cout << "3. ������� �������" << endl;
			          
			          cout << "4. ������ � ������ " << endl;
			          cout << "5. ��������� � �������� ����" << endl;
			          do 
			          {
				         inputStr(value);
				         cout << endl;
				         if ((myAtoi(value) >= 1) && (myAtoi(value) <= 5))
				         {
						     break;
				         }
				         cout << endl << "���������� �����: " << endl;
			          } 
			          while (true);
			          switch(myAtoi(value))
			          {
                        
			            case 1:
					           cout << "�� ������� ���������� ��������" << endl;
					            do
					           {
						         srand(time(NULL));
						         ID = rand() % 100 + 1;
						         cout << endl;
						         if (!st.existIDRemont(ID))
						       {
						         break;
						       }
					           }
					           while(true);
					           cout << "������� ID ��� �������" << endl;
					            do 
								{
						            inputStr(value);
						            cout << endl;
						            if (!st.existIDVid_Remonta (myAtoi(value))) {
						        	cout << "������ �����" << endl << "���������� �����: ";
						            } 
							        else 
							        {
							         break;
						            }
					           }
								while (true);
					            IDCat = myAtoi(value);
								cout << "������� ���������" << endl;
					           do 
					           {
					            	inputStr(value);
						            cout << endl;
						            if (myAtoi(value) == 0) 
						            {
						             	cout << "������ ����� " << endl << "���������� ���: ";
						            } 
									else 
									{
							        break;
						            }
					           }
					           while (true);
					           cost = myAtoi(value);
							   cout << "������� ID �������" << endl;
					            do 
								{
						            inputStr(value);
						            cout << endl;
						            if (!st.existIDMaster (myAtoi(value))) {
						        	cout << "������ �����" << endl << "���������� �����: ";
						            } 
							        else 
							        {
							         break;
						            }
					           }
								while (true);
					            IDTov = myAtoi(value);
						
					st.addRemont (ID , IDCat,cost , IDTov, inputDate()) ;
					break;
			   case 2:
					cout << "�� ������� ��������� ��������" << endl;
					cout << "������� id" << endl;

					do 
					{
						inputStr(value);
						cout << endl;
						if (!st.existIDRemont (myAtoi(value))) 
						{
							cout << "������ ����� id" << endl << "���������� ��� ���: ";
						} else
						{
							break;
						}
					} 
					while (true);
					ID = myAtoi(value);
					cout << "������� ID ��� �������" << endl;
					do 
					{
						inputStr(value);
						cout << endl;
						if (!st.existIDVid_Remonta (myAtoi(value))) 
						{
							cout << "������ ����� id" << endl << "���������� ��� ���: ";
						} else
						{
							break;
						}
					} 
					while (true);
					IDCat = myAtoi(value);
					cout << "������� ���������" << endl;
					           do 
					           {
					            	inputStr(value);
						            cout << endl;
						            if (myAtoi(value) == 0) 
						            {
						             	cout << "������ ����� " << endl << "���������� ���: ";
						            } 
									else 
									{
							        break;
						            }
					           }
					           while (true);
					           cost = myAtoi(value);
							   cout << "������� ID �������" << endl;
					            do 
								{
						            inputStr(value);
						            cout << endl;
						            if (!st.existIDMaster (myAtoi(value))) {
						        	cout << "������ �����" << endl << "���������� �����: ";
						            } 
							        else 
							        {
							         break;
						            }
					           }
								while (true);
					            IDTov = myAtoi(value);

					st.findByIDRemont(ID , IDCat, cost, IDTov, inputDate()) ;
					break;
			   case 3:
					cout << "�� ������� �������� ��������" << endl;
					cout << "������� id" << endl;
					do {
						inputStr(value);
						cout << endl;
						if (!st.existIDRemont(myAtoi(value))) 
						{
							cout << "������ ����� id" << endl << "���������� �����: ";
						} 
						else 
						{
							break;
						}
					   } 
					while (true);
					st.delByValueRemont(myAtoi(value));
					break;
                 
                 case 4:
					st.printRemont();
					break;
                 case 5:
					isExitFromCat = true;
					break;
				}
			 }

			 while (!isExitFromCat);
			 isExitFromCat = false;
			 cout << "�����" << endl;
			 break;
		case 7:
                 cout << "�� ������� ������������ �������������" << endl;
		         do 
		         {
		              isExitFromCat = false;
		              cout << "�������� ��������:" << endl;
		              
			          cout << "1. �������� �������" << endl;
			          cout << "2. �������� �������" << endl;
			          cout << "3. ������� �������" << endl;
			          
			          cout << "4. ������ � ������ " << endl;
			          cout << "5. ��������� � �������� ����" << endl;
			          do 
			          {
				         inputStr(value);
				         cout << endl;
				         if ((myAtoi(value) >= 1) && (myAtoi(value) <= 5))
				         {
						     break;
				         }
				         cout << endl << "���������� �����: " << endl;
			          } 
			          while (true);
			          switch(myAtoi(value))
			          {
                       
			            case 1:
					           cout << "�� ������� ���������� ��������" << endl;
							   do
					           {
						         srand(time(NULL));
						         ID = rand() % 100 + 1;
						         cout << endl;
						         if (!st.existIDIspolzyemie_Komplektyushie(ID))
						       {
						         break;
						       }
					           }
					           while(true);
					           cout << "������� ID �������������" << endl;
					            do 
								{
						            inputStr(value);
						            cout << endl;
						            if (!st.existIDKomplektyushai (myAtoi(value))) {
						        	cout << "������ �����" << endl << "���������� �����: ";
						            } 
							        else 
							        {
							         break;
						            }
					           }
								while (true);
					            IDCat = myAtoi(value);
								cout << "������� ����������" << endl;
								do 
								{
						            inputStr(value);
						            cout << endl;
						            if (!st.existKomplektyish(myAtoi(value), IDCat)) 
									{
						        	cout << "������ �����" << endl << "���������� �����: ";
						            } 
							        else 
							        {
							         break;
						            }
					           }
								while (true);
							    
							   cost = myAtoi(value);
                               st.Recordskomplektyish(cost, IDCat);
							   cout << "������� ID �������" << endl;
					            do 
								{
						            inputStr(value);
						            cout << endl;
						            if (!st.existIDRemont (myAtoi(value))) {
						        	cout << "������ �����" << endl << "���������� �����: ";
						            } 
							        else 
							        {
							         break;
						            }
					           }
								while (true);
					            IDTov = myAtoi(value);
						
					st.addIspolzyemie_Komplektyushie (ID , IDCat, cost, IDTov); 
					break;
			   case 2:
					cout << "�� ������� ��������� ��������" << endl;
					cout << "������� id" << endl;

					do 
					{
						inputStr(value);
						cout << endl;
						if (!st.existIDIspolzyemie_Komplektyushie (myAtoi(value))) 
						{
							cout << "������ ����� id" << endl << "���������� ��� ���: ";
						} else
						{
							break;
						}
					} 
					while (true);
					ID = myAtoi(value);
					cout << "������� ID �������������" << endl;
					do 
					{
						inputStr(value);
						cout << endl;
						if (!st.existIDKomplektyushai (myAtoi(value))) 
						{
							cout << "������ ����� id" << endl << "���������� ��� ���: ";
						} else
						{
							break;
						}
					} 
					while (true);
					IDCat = myAtoi(value);
					cout << "������� ����������" << endl;
					           do 
					           {
					            	inputStr(value);
						            cout << endl;
						            if (myAtoi(value) == 0) 
						            {
						             	cout << "������ ����� " << endl << "���������� ���: ";
						            } 
									else 
									{
							        break;
						            }
					           }
					           while (true);
					           cost = myAtoi(value);
							   cout << "������� ID �������" << endl;
					            do 
								{
						            inputStr(value);
						            cout << endl;
						            if (!st.existIDRemont (myAtoi(value))) {
						        	cout << "������ �����" << endl << "���������� �����: ";
						            } 
							        else 
							        {
							         break;
						            }
					           }
								while (true);
					            IDTov = myAtoi(value);

					st.findByIDIspolzyemie_Komplektyushie(ID, IDCat, cost, IDTov) ;
					break;
			   case 3:
					cout << "�� ������� �������� ��������" << endl;
					cout << "������� id" << endl;
					do {
						inputStr(value);
						cout << endl;
						if (!st.existIDIspolzyemie_Komplektyushie(myAtoi(value))) 
						{
							cout << "������ ����� id" << endl << "���������� �����: ";
						} 
						else 
						{
							break;
						}
					   } 
					while (true);
					st.delByValueIspolzyemie_Komplektyushie(myAtoi(value));
					break;
                 
                 case 4:
					st.printIspolzyemie_Komplektyushie();
					break;
                 case 5:
					isExitFromCat = true;
					break;
				}
			 }

			 while (!isExitFromCat);
			 isExitFromCat = false;
			 cout << "�����" << endl;
			 break;
	case 8:
			cout << "�� ������� ������� �����" << endl;
			
			do 
			{
				isExitFromCat = false;
				cout << "�������� �����:" << endl;
				cout << "1. ���� ������������� �� ������" << endl;
				cout << "2. ���� ������� �� ����� ������� �� ������" << endl;
				cout << "3. ���� ������� �� �������� �� ������" << endl;
				cout << "4. ��������� � �������� ����" << endl;

				do 
				{
					inputStr(value);
					cout << endl;
					if ((myAtoi(value) >= 1) && (myAtoi(value) <= 4)) 
					{
						break;
					}
					cout << endl << "���������� ��� ���: " << endl;
				}
				while (true);
				switch(myAtoi(value)) 
				{
				case 1:
					cout << "���� ������������� �� ������" << endl;
				do {
				        cout << "������� ID ������" << endl;
                        inputStr(value);
						cout << endl;
						if (!st.existIDSklad(myAtoi(value))) {
							cout << "������" << endl << "���������� �����: ";
						} else {
							break;
						}
				} while (true);
				st.RecordsComponents(myAtoi(value));
					break;
			case 2:
				Data dateStart;
                Data dateEnd;
					cout << "���� ������� �� ����� ������� �� ������" << endl;
					cout << "������� ������ ������" << endl;

					
					            	cout << "������� ���� ������" << endl;
					                dateStart=inputDate();
					                cout << "������� ���� �����" << endl;
					                dateEnd=inputDate();
						            cout << endl;
						           st.Vid_RemontaMoney(dateStart, dateEnd);
								   		          
									break;

				case 3:
					
					cout << "���� ������� �� �������� �� ������" << endl;
					cout << "������� ������ ������" << endl;
	            	cout << "������� ���� ������" << endl;
					dateStart=inputDate();
					cout << "������� ���� �����" << endl;
		            dateEnd=inputDate();
					cout << endl;
				    st.MasterMoney(dateStart, dateEnd);
					break;

				case 4:
					isExitFromCat = true;
					break;
				}
			}
			while (!isExitFromCat);

			isExitFromCat = false;
			cout << "�����" << endl;
			break;
  case 9:
			cout << "�� ������� ��������� ���" << endl;
			cout << "������� ���� � ��������" << endl;
					inputStr(name);
					char *namestandart;
					namestandart=strcat(name,"pushSklad.txt");
					st.inFileSklad(namestandart);
					strcpy(namestandart, "");
					namestandart=strcat(name,"pushKomplektyushai.txt");
					st.inFileKomplektyushai(namestandart);
					strcpy(namestandart, "");
					namestandart=strcat(name,"pushMaster.txt");
	                st.inFileMaster(namestandart);
					strcpy(namestandart, "");
					namestandart=strcat(name,"pushMesto_Hranenia.txt");
	                st.inFileMesto_Hranenia(namestandart);
					strcpy(namestandart, "");
					namestandart=strcat(name,"pushRemont.txt");
	                st.inFileRemont(namestandart);
					strcpy(namestandart, "");
					namestandart=strcat(name,"pushIspolzyemie_Komplektyushie.txt");
                    st.inFileIspolzyemie_Komplektyushie(namestandart);
					strcpy(namestandart, "");
					namestandart=strcat(name,"pushVid_Remonta.txt");
                    st.inFileVid_Remonta(namestandart);
					strcpy(namestandart, "");
					cout << endl;
           





			/*st.inFileSklad("pushSklad.txt");
	        st.inFileKomplektyushai("pushKomplektyushai.txt");
	        st.inFileMaster("pushMaster.txt");
	        st.inFileMesto_Hranenia("pushMesto_Hranenia.txt");
	        st.inFileRemont("pushRemont.txt");
            st.inFileIspolzyemie_Komplektyushie("pushIspolzyemie_Komplektyushie.txt");
            st.inFileVid_Remonta("pushVid_Remonta.txt");
			*/

			isExitFromCat = false;
			cout << "�����" << endl;
			break;
case 10:
	       
			cout << "�� ������� ��������� ���" << endl;
			inputStr(name);
					
					namestandart=strcat(name,"pushSklad.txt");
					st.outFileSklad(namestandart);
					strcpy(namestandart, "");
					namestandart=strcat(name,"pushKomplektyushai.txt");
					st.outFileKomplektyushai(namestandart);
					strcpy(namestandart, "");
					namestandart=strcat(name,"pushMaster.txt");
	                st.outFileMaster(namestandart);
					strcpy(namestandart, "");
					namestandart=strcat(name,"pushMesto_Hranenia.txt");
	                st.outFileMesto_Hranenia(namestandart);
					strcpy(namestandart, "");
					namestandart=strcat(name,"pushRemont.txt");
	                st.outFileRemont(namestandart);
					strcpy(namestandart, "");
					namestandart=strcat(name,"pushIspolzyemie_Komplektyushie.txt");
                    st.outFileIspolzyemie_Komplektyushie(namestandart);
					strcpy(namestandart, "");
					namestandart=strcat(name,"pushVid_Remonta.txt");
                    st.outFileVid_Remonta(namestandart);
					strcpy(namestandart, "");
					cout << endl;
			/*st.outFileSklad("pushSklad.txt");
	        st.outFileKomplektyushai("pushKomplektyushai.txt");
	        st.outFileMaster("pushMaster.txt");
	        st.outFileMesto_Hranenia("pushMesto_Hranenia.txt");
	        st.outFileRemont("pushRemont.txt");
            st.outFileIspolzyemie_Komplektyushie("pushIspolzyemie_Komplektyushie.txt");
            st.outFileVid_Remonta("pushVid_Remonta.txt");
			*/

			isExitFromCat = false;
			break;

	case 11:
			isExitFromCat = true;
			break;
		}
		}

			while (!isExitFromCat); //����� �� ����� isExitFromCat
		}
	
	

int main() 
	{
		setlocale(LC_ALL, "Russian");
		cout << "����� ������ ������� ������ �����11"<< endl;
	    cout << "���� ������������� �� ������, ���� �������, ������� ���������"<< endl << endl;
		
   List st[5];
	bool flag = false;
	char *value;
	do {
		flag = false;
		cout << "�������� �����:" << endl;
		cout << "1. ����������" << endl;
		cout << "2. �������" << endl;
		cout << "3. ���������" << endl;
		cout << "4. ������" << endl;
		cout << "5. ��������" << endl;
		cout << "6. �����" << endl;

		do {
			inputStr(value);
			cout << endl;
			if ((myAtoi(value) >= 1) && (myAtoi(value) <= 6)) {
				break;
			}
			cout << endl << "���������� �����: " << endl;
		} while (true);
		system ("cls");
		switch(myAtoi(value)) {
		case 1:
			menu(st[0]);
			break;
		case 2:
			menu(st[1]);
			break;
		case 3:
			menu(st[2]);
			break;
		case 4:
			menu(st[3]);
			break;
		case 5:
			menu(st[4]);
			break;
				
		case 6:
			flag = true;
			break;
				
		}
	} while (!flag);
	 
	
	     return 0;
}


