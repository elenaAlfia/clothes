// sostav_funcion.cpp: �������������� ���� �������.
#include "stdafx.h"

#include <conio.h>
#include <time.h>
#include <fstream>
#include <iomanip>

#include "sostav_funcion.h"
#include <iostream> 
using namespace std;
List::List() 
{
       Sklad_L->head = NULL; // -> �������� ��������� ������� � ������ ������
       Komplektyushai_L->head = NULL; 
	   Master_L->head = NULL; 
	   Mesto_Hranenia_L->head = NULL; 
	   Remont_L->head = NULL; 
	   Ispolzyemie_Komplektyushie_L->head = NULL; 
	   Vid_Remonta_L->head = NULL; 
	   data->head = NULL;
}
List::~List() 
{
	 while (Sklad_L->head != NULL) // ���� 
		{
		Sklad *temp = Sklad_L->head;
		Sklad_L->head = Sklad_L->head->next;
		delete temp; //������� ������ �� 
		}
	    while (Komplektyushai_L->head != NULL) // ���� 
		{
		Komplektyushai *temp = Komplektyushai_L->head;
		Komplektyushai_L->head = Komplektyushai_L->head->next;
		delete temp;
		}
	    while (Master_L->head != NULL) // ���� 
		{
		Master *temp = Master_L->head;
		Master_L->head = Master_L->head->next;
		delete temp;
		}
	    while (Mesto_Hranenia_L->head != NULL) // ���� 
		{
		Mesto_Hranenia *temp = Mesto_Hranenia_L->head;
		Mesto_Hranenia_L->head = Mesto_Hranenia_L->head->next;
		delete temp;
		}
	    while (Remont_L->head != NULL) // ���� 
		{
		Remont *temp = Remont_L->head;
		Remont_L->head = Remont_L->head->next;
		delete temp;
		}
	    while (Ispolzyemie_Komplektyushie_L->head != NULL) // ���� 
		{
		Ispolzyemie_Komplektyushie *temp = Ispolzyemie_Komplektyushie_L->head;
		Ispolzyemie_Komplektyushie_L->head = Ispolzyemie_Komplektyushie_L->head->next;
		delete temp;
		}
	    while (Vid_Remonta_L->head != NULL) // ���� 
		{
		Vid_Remonta *temp = Vid_Remonta_L->head;
		Vid_Remonta_L->head = Vid_Remonta_L->head->next;
		delete temp;
		}
}
//  ���������� ���������
		void List::addSklad(int ID_s,int Kolichestvo_Skladskih_Mest,char *Nathvanie_Sklada)
		{
			for (Sklad *temp = Sklad_L->head; temp != NULL; temp = temp->next) { // ����  
				if (temp->ID_Sklad == ID_s) { // ����
					cout << "�����: ID = " << ID_s << " ��� ����������" << endl;
					return;
		}
	}
		for (Sklad *temp = Sklad_L->head; temp != NULL; temp = temp->next)
		{ 
		if (temp->Nathvanie_Sklada == Nathvanie_Sklada) 
		   {
			cout << "�����: �������� ������ = " << Nathvanie_Sklada << " ��� ����������" << endl;
			return;
		   }
	    }
			Sklad *temp = new Sklad;
	        temp->ID_Sklad = ID_s;
			temp->Kolichestvo_Skladskih_Mest=Kolichestvo_Skladskih_Mest;
			temp->Nathvanie_Sklada = Nathvanie_Sklada;
	        temp->next = Sklad_L->head;
	        Sklad_L.head = temp;
        }
	    void List::addKomplektyushai (int ID_K , char *Naimenovanie, int Cena_Komplektyushei) 
		{
	      for (Komplektyushai *temp = Komplektyushai_L->head; temp != NULL; temp = temp->next)
	      { 
		   if (temp->ID_Komplektyushai == ID_K) 
		   {
			cout << "�������������: ID = " << ID_K << " ��� ����������" << endl;
			return;
		   }
	      }
		  for (Komplektyushai *temp = Komplektyushai_L->head; temp != NULL; temp = temp->next) 
		  { 
		   if (temp->Naimenovanie == Naimenovanie) 
		   {
			cout << "�������������: ������������ = " << Naimenovanie << " ��� ����������" << endl;
			return;
		   }
	      }
		  Komplektyushai *temp = new Komplektyushai;
	      temp->ID_Komplektyushai = ID_K;
	      temp->Naimenovanie = Naimenovanie;
          temp->Cena_Komplektyushei = Cena_Komplektyushei;
	      temp->next = Komplektyushai_L->head;
	      Komplektyushai_L.head = temp;
         }
		void List::addMaster (int ID_M , char *FIO, int Zarplata) 
		{
	      for (Master *temp = Master_L->head; temp != NULL; temp = temp->next)
	      { 
		   if (temp->ID_Master == ID_M) 
		   {
			cout << "������: ID = " << ID_M << " ��� ����������" << endl;
			return;
		   }
	      }
		  for (Master *temp = Master_L->head; temp != NULL; temp = temp->next) 
		  { 
		   if (temp->FIO == FIO) 
		   {
			cout << "������: ��� = " << FIO << " ��� ����������" << endl;
			return;
		   }
	      }
		  Master *temp = new Master;
	      temp->ID_Master = ID_M;
	      temp->FIO = FIO;
          temp->Zarplata = Zarplata;
	      temp->next = Master_L->head;
	      Master_L.head = temp;
         }
	    void List::addMesto_Hranenia (int ID_Me , int ID_S, int ID_K, int Kolichestvo_Komplektyushih) 
		{
	      for (Mesto_Hranenia *temp = Mesto_Hranenia_L->head; temp != NULL; temp = temp->next)
	      { 
		   if (temp->ID_Mesto_Hranenia == ID_Me) 
		   {
			cout << "����� ��������: ID = " << ID_Me << " ��� ����������" << endl;
			return;
		   }
	      }
		 for (Sklad *tmp = Sklad_L->head; tmp != NULL; tmp = tmp->next)
		 {
	       for (Komplektyushai *tmp2 = Komplektyushai_L->head; tmp2 != NULL; tmp2 = tmp2->next)
		   {
			   if ((tmp->ID_Sklad == ID_S) && (tmp2->ID_Komplektyushai == ID_K))
			   {
				Mesto_Hranenia *temp = new Mesto_Hranenia;
				temp->ID_Mesto_Hranenia = ID_Me;
				temp->ID_Sklad = ID_S;
				temp->ID_Komplektyushai = ID_K;
				temp->Kolichestvo_Komplektyushih = Kolichestvo_Komplektyushih;
				temp->next = Mesto_Hranenia_L->head;
				Mesto_Hranenia_L.head = temp;

			
			}
		}
	}
	cout << "���� \"ID ������ \" � \"ID �������������\"  �� ����������" << endl;
}
        void List::addVid_Remonta(int ID_V, char *Nazvanie) 
		{
	      for (Vid_Remonta *temp = Vid_Remonta_L->head; temp != NULL; temp = temp->next)
		  { 
		    if (temp->ID_Vid_Remonta == ID_V)
			{
			cout << "��� �������: ID = " << ID_V << " ��� ����������" << endl;
			return;
		    }
	      }
	      for (Vid_Remonta *temp = Vid_Remonta_L->head; temp != NULL; temp = temp->next)
		     { 
		     if (temp->Nazvanie == Nazvanie)
			 {
			 cout << "��� �������: �������� = " << Nazvanie << " ��� ����������" << endl;
			 return;
		     }
	         }
	         Vid_Remonta *temp = new Vid_Remonta;
	         temp->ID_Vid_Remonta = ID_V;
	         temp->Nazvanie = Nazvanie;
	         temp->next = Vid_Remonta_L->head;
	         Vid_Remonta_L.head = temp;
        }
	    void List::addRemont (int ID_R , int ID_V,int Stoimost, int ID_M, Data data) 
		{
	      for (Remont *temp = Remont_L->head; temp != NULL; temp = temp->next)
	      { 
		   if (temp->ID_Remont == ID_R) 
		   {
			cout << "������: ID = " << ID_R << " ��� ����������" << endl;
			return;
		   }
	      }
		 for (Vid_Remonta *tmp = Vid_Remonta_L->head; tmp != NULL; tmp = tmp->next)
		 {
	       for (Master *tmp2 = Master_L->head; tmp2 != NULL; tmp2 = tmp2->next)
		   {
			   if ((tmp->ID_Vid_Remonta == ID_V) && (tmp2->ID_Master == ID_M))
			   {
				Remont *temp = new Remont;
				temp->ID_Remont = ID_R;
				temp->ID_Vid_Remonta = ID_V;
				temp->Stoimost = Stoimost;
				temp->ID_Master = ID_M;
				temp->Data_Remonta.month = data.month;
			    temp->Data_Remonta.year = data.year;  
				temp->next = Remont_L->head;
				Remont_L.head = temp;

				return;
			}
		}
	}
	cout << "���� \"ID ��� ������� \" � \"ID �������\"  �� ����������" << endl;
}
	    void List::addIspolzyemie_Komplektyushie (int ID_I , int ID_K,int Kolichestvo, int ID_R) 
		{
	      for (Ispolzyemie_Komplektyushie *temp = Ispolzyemie_Komplektyushie_L->head; temp != NULL; temp = temp->next)
	      { 
		   if (temp->ID_Ispolzyemie_Komplektyushie == ID_I) 
		   {
			cout << "������������ �������������: ID = " << ID_I << " ��� ����������" << endl;
			return;
		   }
	      }
		 for (Komplektyushai *tmp = Komplektyushai_L->head; tmp != NULL; tmp = tmp->next)
		 {
	       for (Remont *tmp2 = Remont_L->head; tmp2 != NULL; tmp2 = tmp2->next)
		   {
			   if ((tmp->ID_Komplektyushai == ID_K) && (tmp2->ID_Remont == ID_R))
			   {
				Ispolzyemie_Komplektyushie *temp = new Ispolzyemie_Komplektyushie;
				temp->ID_Ispolzyemie_Komplektyushie = ID_I;
				temp->ID_Komplektyushai = ID_K;
				temp->Kolichestvo = Kolichestvo;
				temp->ID_Remont = ID_R;
				temp->next = Ispolzyemie_Komplektyushie_L->head;
				Ispolzyemie_Komplektyushie_L.head = temp;

				return;
			}
		}
	}
	cout << "���� \"ID ������������� \" � \"ID ������\"  �� ����������" << endl;
}
		// ������ ���������
		void List::printSklad() 
		{
	     cout << "������ ������:" << endl << endl;
	     cout << "-----------------------------------------------------------------------" << endl;
	     cout.setf(ios::left, ios::adjustfield);
	     cout << setw(4) << " ID" << setw(5) << "| ����������" <<  setw(30) << "| �������� ������" << endl;
	     cout << "-----------------------------------------------------------------------" << endl;
	     for (Sklad *temp = Sklad_L->head; temp != NULL; temp = temp->next) 
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
	     for (Komplektyushai *temp = Komplektyushai_L->head; temp != NULL; temp = temp->next) 
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
	     for (Master *temp = Master_L->head; temp != NULL; temp = temp->next) 
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
	     for (Mesto_Hranenia *temp = Mesto_Hranenia_L->head; temp != NULL; temp = temp->next) 
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
	     for (Remont *temp = Remont_L->head; temp != NULL; temp = temp->next) 
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
	     for (Ispolzyemie_Komplektyushie *temp = Ispolzyemie_Komplektyushie_L->head; temp != NULL; temp = temp->next) 
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
	     for (Vid_Remonta *temp = Vid_Remonta_L->head; temp != NULL; temp = temp->next) 
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
		        char *Nathvanie_Sklada;
		       
	         };
	         for (Sklad *temp = Sklad_L->head; temp != NULL; temp = temp->next) 
			 {
		        SkladTemp head;
		        head.ID_Sklad = temp->ID_Sklad;
		        head.Kolichestvo_Skladskih_Mest = temp->Kolichestvo_Skladskih_Mest;
		        head.Nathvanie_Sklada = temp->Nathvanie_Sklada;
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
	            char *Naimenovanie;        
	            int Cena_Komplektyushei;
		       
	         };
	         for (Komplektyushai *temp = Komplektyushai_L->head; temp != NULL; temp = temp->next) 
			 {
		        KomplektyushaiTemp head;
		        head.ID_Komplektyushai = temp->ID_Komplektyushai;
		        head.Naimenovanie = temp->Naimenovanie;
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
	            char *FIO;        
	            int Zarplata;
		       
	         };
	         for (Master *temp = Master_L->head; temp != NULL; temp = temp->next) 
			 {
		        MasterTemp head;
		        head.ID_Master = temp->ID_Master;
		        head.FIO = temp->FIO;
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
	         for (Mesto_Hranenia *temp = Mesto_Hranenia_L->head; temp != NULL; temp = temp->next) 
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
	         for (Remont *temp = Remont_L->head; temp != NULL; temp = temp->next) 
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
	         for (Ispolzyemie_Komplektyushie *temp = Ispolzyemie_Komplektyushie_L->head; temp != NULL; temp = temp->next) 
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
				char *Nazvanie;                 
	         };
	         for (Vid_Remonta *temp = Vid_Remonta_L->head; temp != NULL; temp = temp->next) 
			 {
		        Vid_RemontaTemp head;
		        head.ID_Vid_Remonta = temp->ID_Vid_Remonta;
		        head.Nazvanie = temp->Nazvanie;        
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
            char *Nathvanie_Sklada;
	      };
	      SkladTemp head;
	      while (fread(&head, sizeof(head), 1, in)) 
		  {
		    addSklad(head.ID_Sklad, head.Kolichestvo_Skladskih_Mest, head.Nathvanie_Sklada);
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
		    char *Naimenovanie;        
	        int Cena_Komplektyushei;
	      };
	      KomplektyushaiTemp head;
	      while (fread(&head, sizeof(head), 1, in)) 
		  {
		    addKomplektyushai(head.ID_Komplektyushai, head.Naimenovanie, head.Cena_Komplektyushei);
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
		    char *FIO;        
	        int Zarplata;
	      };
	      MasterTemp head;
	      while (fread(&head, sizeof(head), 1, in)) 
		  {
		    addMaster(head.ID_Master, head.FIO, head.Zarplata);
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
			char *Nazvanie;
	      };
	      Vid_RemontaTemp head;
	      while (fread(&head, sizeof(head), 1, in)) 
		  {
		    addVid_Remonta(head.ID_Vid_Remonta, head.Nazvanie);
	      }
	fclose(in);
	printVid_Remonta();	
}
		//  ������������� ID
		bool List::existIDSklad(int ID) 
		{
          for (Sklad *temp = Sklad_L->head; temp != NULL; temp = temp->next) 
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
          for (Komplektyushai *temp = Komplektyushai_L->head; temp != NULL; temp = temp->next) 
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
          for (Master *temp = Master_L->head; temp != NULL; temp = temp->next) 
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
          for (Mesto_Hranenia *temp = Mesto_Hranenia_L->head; temp != NULL; temp = temp->next) 
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
          for (Remont *temp = Remont_L->head; temp != NULL; temp = temp->next) 
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
          for (Ispolzyemie_Komplektyushie *temp = Ispolzyemie_Komplektyushie_L->head; temp != NULL; temp = temp->next) 
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
          for (Vid_Remonta *temp = Vid_Remonta_L->head; temp != NULL; temp = temp->next) 
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
		    }
	      }
        }
		void List::findByIDRemont(int ID_R, int ID_V, int Stoim, int ID_M, Data data) 
		{
	      for (Remont *temp = Remont_L->head; temp != NULL; temp = temp->next) 
		  {
		    if (temp->ID_Remont == ID_R) 
			{
			    temp->ID_Vid_Remonta = ID_V;
			    temp->Stoimost = Stoim;
                temp->ID_Master = ID_M;
                temp->Data_Remonta.month = data.month;
			    temp->Data_Remonta.year = data.year; 
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
            }
	      }
        }
		// ��������
		void List::delByValueMesto_Hranenia(int ID) 
		{
	        while (Mesto_Hranenia_L.head != NULL) 
			{
		      if (Mesto_Hranenia_L.head->ID_Mesto_Hranenia == ID) 
			  {
			   	 Mesto_Hranenia *temp = Mesto_Hranenia_L.head;
			     Mesto_Hranenia_L.head = Mesto_Hranenia_L.head->next;
			     delete temp;
		     } 
			 else 
		     {
			   break;
		     }
	         }
	         if (Mesto_Hranenia_L.head == NULL)
			 {
		     return;
	         }
	         Mesto_Hranenia *prevNode = Mesto_Hranenia_L.head;
	         while (prevNode->next != NULL)
			 {
		        if (prevNode->next->ID_Mesto_Hranenia == ID) 
				{
			       Mesto_Hranenia *temp = prevNode->next;
			       prevNode->next = prevNode->next->next;
			       delete temp;
		        } 
				else 
				{
			    prevNode = prevNode->next;
		        }
	         }
         }
		void List::delByValueSklad(int ID) 
		{
	        while (Sklad_L.head != NULL) 
			{
		      if (Sklad_L.head->ID_Sklad == ID) 
			  {
			    for (Mesto_Hranenia *temp = Mesto_Hranenia_L.head; temp != NULL; temp = temp->next) 
				{
				   if (temp.ID_Sklad == ID)
				    {
					    delByValueMesto_Hranenia(ID);
				    }
			    }
			     Sklad *temp = Sklad_L.head;
			     Sklad_L.head = Sklad_L.head->next;
			     delete temp;
		     } 
			 else 
		     {
			   break;
		     }
	         }
	         if (Sklad_L.head == NULL)
			 {
		     return;
	         }
	         Sklad *prevNode = Sklad_L.head;
	         while (prevNode->next != NULL)
			 {
		        if (prevNode->next->ID_Sklad == ID) 
				{
			       for (Mesto_Hranenia *temp = Mesto_Hranenia_L->head; temp != NULL; temp = temp->next) 
				   {
				       if (temp->ID_Sklad == ID) 
					   {
					    delByValueMesto_Hranenia(ID);
				       }
			       }
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
		void List::delByValueKomplektyushai(int ID) 
		{
	        while (Komplektyushai_L.head != NULL) 
			{
		      if (Komplektyushai_L.head->ID_Komplektyushai == ID) 
			  {
			    for (Mesto_Hranenia *temp = Mesto_Hranenia_L.head; temp != NULL; temp = temp->next) 
				{
				   if (temp->ID_Komplektyushai == ID)
				    {
					    delByValueMesto_Hranenia(ID);
				    }
			    }
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
			   break;
		     }
	         }
	         if (Komplektyushai_L.head == NULL)
			 {
		     return;
	         }
	         Komplektyushai *prevNode = Komplektyushai_L.head;
	         while (prevNode->next != NULL)
			 {
		        if (prevNode->next->ID_Komplektyushai == ID) 
				{
			       for (Mesto_Hranenia *temp = Mesto_Hranenia_L.head; temp != NULL; temp = temp->next) 
				   {
				       if (temp->ID_Komplektyushai == ID) 
					   {
					    Mesto_Hranenia *temp = Mesto_Hranenia_L.head;   //��� �������� ��������
			            Mesto_Hranenia_L.head = Mesto_Hranenia_L.head->next;
			            delete temp;
				       }
			       }
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
		void List::delByValueMaster(int ID) 
		{
	        while (Master_L.head != NULL) 
			{
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
			   break;
		     }
	         }
	         if (Master_L.head == NULL)
			 {
		     return;
	         }
	         Master *prevNode = Master_L->head;
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
		void List::delByValueIspolzyemie_Komplektyushie(int ID) 
		{
	        while (Ispolzyemie_Komplektyushie_L.head != NULL) 
			{
		      if (Ispolzyemie_Komplektyushie_L.head->ID_Remont == ID) 
			  {
			     Ispolzyemie_Komplektyushie *temp = Ispolzyemie_Komplektyushie_L.head;
			     Ispolzyemie_Komplektyushie_L.head = Ispolzyemie_Komplektyushie_L.head->next;
			     delete temp;
		     } 
			 else 
		     {
			   break;
		     }
	         }
	         if (Ispolzyemie_Komplektyushie_L.head == NULL)
			 {
		     return;
	         }
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
		void List::delByValueRemont(int ID) 
		{
	        while (Remont_L.head != NULL) 
			{
		      if (Remont_L.head->ID_Remont == ID) 
			  {
			    for (Ispolzyemie_Komplektyushie *temp = Ispolzyemie_Komplektyushie_L.head; temp != NULL; temp = temp->next) 
				{
				   if (temp->ID_Remont == ID)
				    {
					   delByValueIspolzyemie_Komplektyushie( ID);
				    }
			    }
			     Remont *temp = Remont_L.head;
			     Remont_L.head = Remont_L.head->next;
			     delete temp;
		     } 
			 else 
		     {
			   break;
		     }
	         }
	         if (Remont_L.head == NULL)
			 {
		     return;
	         }
	         Remont *prevNode = Remont_L.head;
	         while (prevNode->next != NULL)
			 {
		        if (prevNode->next->ID_Remont == ID) 
				{
			       for (Ispolzyemie_Komplektyushie *temp = Ispolzyemie_Komplektyushie_L.head; temp != NULL; temp = temp->next) 
				   {
				       if (temp->ID_Remont == ID) 
					   {
					    delByValueIspolzyemie_Komplektyushie(ID);
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
		void List::delByValueVid_Remonta(int ID) 
		{
	        while (Vid_Remonta_L.head != NULL) 
			{
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
			     Master_L->head = Master_L.head->next;
			     delete temp;
		     } 
			 else 
		     {
			   break;
		     }
	         }
	         if (Vid_Remonta_L.head == NULL)
			 {
		     return;
	         }
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

		Date inputDate() 
		{
	    Date date;

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
	     date.month = myAtoi(temp2);

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
	     date.year = myAtoi(temp3);

	  return date;
     }
		// ��������
		// ���� �������������
		int List::RecordsComponents()
		{
			int IDv;
			int summa = 0;
			do {
				        cout << "������� ID ������" << endl;
                        inputStr(value);
						cout << endl;
						if (!st.existIDSvaz(myAtoi(value))) {
							cout << "������" << endl << "���������� �����: ";
						} else {
							break;
						}
				} while (true);

			for (Komplektyushai *temp = Komplektyushai_L.head; temp != NULL; temp = temp->next) 
			{
			   IDv = ID_Komplektyushai;
			   for (Mesto_Hranenia *temp = Mesto_Hranenia_L.head; temp != NULL; temp = temp->next) 
			   {
				    if (temp->ID_Sklad == myAtoi(value)) && (temp->ID_Komplektyushai == IDv)
						{
							summa = summa + Kolichestvo_Komplektyushih;
						}
				       
			}
			   cout << "���������� " << Naimenovanie << " = " << summa << endl;
		}
		}