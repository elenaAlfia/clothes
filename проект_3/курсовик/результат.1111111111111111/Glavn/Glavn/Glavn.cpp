// Glavn.cpp: ������� ���� �������.
#include "stdafx.h"
#include "conio.h"
#include <time.h>
#include <ctime>
#include <iomanip>

#include "sostav_funcion.h"
#include <iostream>
using namespace std;

char *value;
bool isExitFromCat = false;
char *name;
Date dateStart;
Date dateEnd;
listCat *newListCat;

int ID;
int IDCat;
int IDTov;
int cost;

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
void menu(List &st)
{
    st.inFileSklad("pushSklad.bin");
	st.inFileKomplektyushai("pushKomplektyushai.bin");
	st.inFileMaster("pushMaster.bin");
	st.inFileMesto_Hranenia("pushMesto_Hranenia.bin");
	st.inFileRemont("pushRemont.bin");
    st.inFileIspolzyemie_Komplektyushie("pushIspolzyemie_Komplektyushie.bin");
    st.inFileVid_Remonta("pushVid_Remonta.bin");
 do  //��������� ���� !isExitFromCat
	{                                   
		cout << "�������� �������:" << endl;
		cout << "1. �����" << endl;
		cout << "2. �������������" << endl;
		cout << "3. ������" << endl;
		cout << "4. ����� ��������" << endl;
        cout << "5. ��� �������" << endl;
		cout << "6. ������" << endl;
	    cout << "7. ������������ �������������" << endl;
	   	cout << "8. ������� �����" << endl;
		cout << "9. �����" << endl;

      do 
          {
		   inputStr(value);
		   cout << endl;
		   if ((myAtoi(value) >= 1) && (myAtoi(value) <= 9)) 
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
				cout << "1. ��������� ����" << endl;
				cout << "2. �������� �������" << endl;
				cout << "3. �������� �������" << endl;
				cout << "4. ������� �������" << endl;
				cout << "5. ������ � ���� " << endl;
				cout << "6. ������ � ������ " << endl;
				cout << "7. ��������� � �������� ����" << endl;
				do 
				{
					inputStr(value);
					cout << endl;
					if ((myAtoi(value) >= 1) && (myAtoi(value) <= 7))
					{
						break;
					}
					cout << endl << "���������� ��� ���: " << endl;
				}
				while (true);
				switch(myAtoi(value)) 
				{
				case 1:
					cout << "�� ������� ������ �� �����" << endl;
					cout << "������� ���� � �����" << endl;
					inputStr(name);
					st.inFileSklad(name);
					cout << endl;
					break;
				case 2:
					cout << "�� ������� ���������� ��������" << endl;
					do
					{
						srand(time(NULL));
						ID = rand() % 100 + 1;
						cout << endl;
						if (!st.existIDsklad(ID))
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
				case 3:
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

					st->findByIDSklad(ID, cost, name);
					break;
                case 4:
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
                 case 5:
					cout << "�� ������� ������ �� �����" << endl;
					cout << "������� ���� � �����" << endl;
					inputStr(name);
					st.outFileSklad(name);
					break;
                 case 6:
					st.printSklad();
					break;
                 case 7:
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
		     cout << "1. ��������� ����" << endl;
			 cout << "2. �������� �������" << endl;
			 cout << "3. �������� �������" << endl;
			 cout << "4. ������� �������" << endl;
			 cout << "5. ������ � ���� " << endl;
			 cout << "6. ������ � ������ " << endl;
			 cout << "7. ��������� � �������� ����" << endl;
			 do 
			 {
				inputStr(value);
				cout << endl;
				if ((myAtoi(value) >= 1) && (myAtoi(value) <= 7))
				{
						break;
				}
				cout << endl << "���������� �����: " << endl;
			 } 
			 while (true);
			 switch(myAtoi(value))
			 {
              case 1:
				    cout << "�� ������� ������ �� �����" << endl;
					cout << "������� ���� � �����" << endl;
					inputStr(name);
					st.inFileKomplektyushai(name);
					cout << endl;
					break;
			  case 2:
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
			   case 3:
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

					st.findByIDKomplektyushai(ID_K, name, cost);
					break;
			   case 4:
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
                 case 5:
					cout << "�� ������� ������ �� �����" << endl;
					cout << "������� ���� � �����" << endl;
					inputStr(name);
					st.outFileKomplektyushai(name);
					break;
                 case 6:
					st.printKomplektyushai();
					break;
                 case 7:
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
		              cout << "1. ��������� ����" << endl;
			          cout << "2. �������� �������" << endl;
			          cout << "3. �������� �������" << endl;
			          cout << "4. ������� �������" << endl;
			          cout << "5. ������ � ���� " << endl;
			          cout << "6. ������ � ������ " << endl;
			          cout << "7. ��������� � �������� ����" << endl;
			          do 
			          {
				         inputStr(value);
				         cout << endl;
				         if ((myAtoi(value) >= 1) && (myAtoi(value) <= 7))
				         {
						     break;
				         }
				         cout << endl << "���������� �����: " << endl;
			          } 
			          while (true);
			          switch(myAtoi(value))
			          {
                        case 1:
				               cout << "�� ������� ������ �� �����" << endl;
					           cout << "������� ���� � �����" << endl;
					           inputStr(name);
					           st.inFileMaster(name);
					           cout << endl;
					           break;
			            case 2:
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
					st->addMaster (ID ,name, cost) 
					break;
			   case 3:
					cout << "�� ������� ��������� ��������" << endl;
					cout << "������� id" << endl;

					do 
					{
						inputStr(value);
						cout << endl;
						if (!st.existIDMaster(myAtoi(value))) 
						{
							cout << "������ ����� id" << endl << "���������� ��� ���: ";
						} else
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

					st->findByIDMaster(ID, name, cost) ;
					break;
			   case 4:
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
                 case 5:
					cout << "�� ������� ������ �� �����" << endl;
					cout << "������� ���� � �����" << endl;
					inputStr(name);
					st.outFileMaster(name);
					break;
                 case 6:
					st.printMaster();
					break;
                 case 7:
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
		              cout << "1. ��������� ����" << endl;
			          cout << "2. �������� �������" << endl;
			          cout << "3. �������� �������" << endl;
			          cout << "4. ������� �������" << endl;
			          cout << "5. ������ � ���� " << endl;
			          cout << "6. ������ � ������ " << endl;
			          cout << "7. ��������� � �������� ����" << endl;
			          do 
			          {
				         inputStr(value);
				         cout << endl;
				         if ((myAtoi(value) >= 1) && (myAtoi(value) <= 7))
				         {
						     break;
				         }
				         cout << endl << "���������� �����: " << endl;
			          } 
			          while (true);
			          switch(myAtoi(value))
			          {
                        case 1:
				               cout << "�� ������� ������ �� �����" << endl;
					           cout << "������� ���� � �����" << endl;
					           inputStr(name);
					           st.inFileMesto_Hranenia(name);
					           cout << endl;
					           break;
			            case 2:
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
					st.addMesto_Hranenia (ID , IDCat, IDTov, cost) 
					break;
			   case 3:
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
			   case 4:
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
                 case 5:
					cout << "�� ������� ������ �� �����" << endl;
					cout << "������� ���� � �����" << endl;
					inputStr(name);
					st.outFileMesto_Hranenia(name);
					break;
                 case 6:
					st.printMesto_Hranenia();
					break;
                 case 7:
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
		              cout << "1. ��������� ����" << endl;
			          cout << "2. �������� �������" << endl;
			          cout << "3. �������� �������" << endl;
			          cout << "4. ������� �������" << endl;
			          cout << "5. ������ � ���� " << endl;
			          cout << "6. ������ � ������ " << endl;
			          cout << "7. ��������� � �������� ����" << endl;
			          do 
			          {
				         inputStr(value);
				         cout << endl;
				         if ((myAtoi(value) >= 1) && (myAtoi(value) <= 7))
				         {
						     break;
				         }
				         cout << endl << "���������� �����: " << endl;
			          } 
			          while (true);
			          switch(myAtoi(value))
			          {
                        case 1:
				               cout << "�� ������� ������ �� �����" << endl;
					           cout << "������� ���� � �����" << endl;
					           inputStr(name);
					           st.inFileVid_Remonta(name);
					           cout << endl;
					           break;
			            case 2:
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
						
					st->addVid_Remonta(ID, name)  
					break;
			   case 3:
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
					st->findByIDVid_Remonta(ID, name) ;
					break;
			   case 4:
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
                 case 5:
					cout << "�� ������� ������ �� �����" << endl;
					cout << "������� ���� � �����" << endl;
					inputStr(name);
					st.outFileVid_Remonta(name);
					break;
                 case 6:
					st.printVid_Remonta();
					break;
                 case 7:
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
		              cout << "1. ��������� ����" << endl;
			          cout << "2. �������� �������" << endl;
			          cout << "3. �������� �������" << endl;
			          cout << "4. ������� �������" << endl;
			          cout << "5. ������ � ���� " << endl;
			          cout << "6. ������ � ������ " << endl;
			          cout << "7. ��������� � �������� ����" << endl;
			          do 
			          {
				         inputStr(value);
				         cout << endl;
				         if ((myAtoi(value) >= 1) && (myAtoi(value) <= 7))
				         {
						     break;
				         }
				         cout << endl << "���������� �����: " << endl;
			          } 
			          while (true);
			          switch(myAtoi(value))
			          {
                        case 1:
				               cout << "�� ������� ������ �� �����" << endl;
					           cout << "������� ���� � �����" << endl;
					           inputStr(name);
					           st.inFileRemont(name);
					           cout << endl;
					           break;
			            case 2:
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
						
					st.addRemont (ID , IDCat,cost , IDTov, inputDate()) 
					break;
			   case 3:
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

					st.findByIDRemont(ID , IDCat, cost, IDTov, st->inputDate()) ;
					break;
			   case 4:
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
                 case 5:
					cout << "�� ������� ������ �� �����" << endl;
					cout << "������� ���� � �����" << endl;
					inputStr(name);
					st.outFileRemont(name);
					break;
                 case 6:
					st.printRemont();
					break;
                 case 7:
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
		              cout << "1. ��������� ����" << endl;
			          cout << "2. �������� �������" << endl;
			          cout << "3. �������� �������" << endl;
			          cout << "4. ������� �������" << endl;
			          cout << "5. ������ � ���� " << endl;
			          cout << "6. ������ � ������ " << endl;
			          cout << "7. ��������� � �������� ����" << endl;
			          do 
			          {
				         inputStr(value);
				         cout << endl;
				         if ((myAtoi(value) >= 1) && (myAtoi(value) <= 7))
				         {
						     break;
				         }
				         cout << endl << "���������� �����: " << endl;
			          } 
			          while (true);
			          switch(myAtoi(value))
			          {
                        case 1:
				               cout << "�� ������� ������ �� �����" << endl;
					           cout << "������� ���� � �����" << endl;
					           inputStr(name);
					           st.inFileIspolzyemie_Komplektyushie (name);
					           cout << endl;
					           break;
			            case 2:
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
						
					st.addIspolzyemie_Komplektyushie (ID , IDCat, cost, IDTov) 
					break;
			   case 3:
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
			   case 4:
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
                 case 5:
					cout << "�� ������� ������ �� �����" << endl;
					cout << "������� ���� � �����" << endl;
					inputStr(name);
					st.outFileIspolzyemie_Komplektyushie(name);
					break;
                 case 6:
					st.printIspolzyemie_Komplektyushie();
					break;
                 case 7:
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
				// ����������	cout << "��� ���������: " << st->summProdPer() << endl;
					break;

				case 2:
					cout << "���� ������� �� ����� ������� �� ������" << endl;
				// ����������	st->summProdCat();
					break;

				case 3:
					cout << "���� ������� �� �������� �� ������" << endl;
				// ����������	cout << "��� ���������: " << st->countProdPer() << endl;
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
		
	do {
		flag = false;
	   	menu(st[0]);
			break;
		
	   } while (!flag);
	     return 0;
}


