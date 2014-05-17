#include "stdafx.h"
#include "iostream"
#include <Windows.h>
#include <string>
#include <locale.h>
#include <conio.h>
#include "stdio.h"
#include "fstream"
#include <time.h>
#include <iomanip>
#pragma warning(disable : 4996)

using namespace std;

struct Teacher{
	int ID_Teacher;
	char * FIO;
	Teacher *next; };
struct ListTeach
{Teacher *head;
};

struct Lesson{
	int ID_Lesson;
	char * Name;
	Lesson *next; };
struct ListLess{
Lesson *head;
};

struct Auditoria{
		int ID_Auditoria;
		int VMESTIMOST;
		bool TIP;
		Auditoria *next;};
	struct ListAud{ 
Auditoria *head;  };

	struct Group{
		int ID_Group;
		char * Name;
		int Quantity;
		Group *next;
	};
	struct ListGr{ 
    Group *head;  };
	
	
struct Uchplan{
		int ID_Uchplan;
		int ID_Group;
		int ID_Less;
		int lekcii;
		int praktiki;
		int ID_Teach;
		Uchplan *next;
	};
	struct ListUch{ 
    Uchplan *head;  };

struct Raspisanie{
		int ID_Raspisanie;
		int ID_Uchplan;
		bool week;
        char * Day;
		int para;
		int ID_Auditoria;
		Raspisanie *next;
	};
struct ListRasp{ 
    Raspisanie *head;  
	};
	
	class List {
public:
	ListTeach teach;
	ListLess less;
	ListAud aud ;
	ListGr gr ;
    ListUch uch ;
	ListRasp rasp ;
	 
List() {

	teach.head = NULL;
	 less.head = NULL;
	 aud.head = NULL;
	 gr.head = NULL;
     uch.head = NULL;
	 rasp.head = NULL;
}
~List() {
	clearTeach();
	clearLess();
	clearAud();
	clearGr();
	clearUch();
	clearRasp();
}
void addTeach(int IDt, char * FIO) {
    Teacher *temp = new Teacher;
	temp->ID_Teacher = IDt;
	temp->FIO = FIO;
	temp->next = teach.head;
	teach.head = temp;
}
void addLess(int IDl, char * Name){
	Lesson *temp = new Lesson;
	temp->ID_Lesson = IDl;
	temp->Name = Name;
	temp->next = less.head;
	less.head = temp;
}
void addAud(int IDa, int VMESTIMOST,bool TIP){
	Auditoria *temp = new Auditoria;
    temp->ID_Auditoria = IDa;
	temp->VMESTIMOST = VMESTIMOST;
	temp->TIP = TIP;
	temp->next = aud.head;
	aud.head = temp;
} 
void addGr(int IDg,char * Name , int Quantity){
	Group *temp = new Group;
    temp->ID_Group = IDg;
	temp->Name = Name;
	temp->Quantity = Quantity;
	temp->next = gr.head;
	gr.head = temp;
}
void addUch(int IDu,int ID_Group, int ID_Less, int lekcii, int praktiki,int ID_Teach){
	Uchplan *temp = new Uchplan;
    temp->ID_Uchplan = IDu;
	temp->ID_Group = ID_Group;
	temp->ID_Less = ID_Less;
	temp->lekcii = lekcii;
	temp->praktiki = praktiki;
	temp->ID_Teach = ID_Teach;
	temp->next = uch.head;
	uch.head = temp;
}
void addRasp(int IDr, int ID_Uchplan, bool week ,char * Day, int para, int ID_Auditoria){
	Raspisanie *temp = new Raspisanie;
    temp->ID_Raspisanie = IDr;
	temp->ID_Uchplan = ID_Uchplan;
	temp->week = week;
	temp->Day = Day;
	temp->para = para;
	temp->ID_Auditoria = ID_Auditoria;
	temp->next = rasp.head;
	rasp.head = temp;
}
void changeByIDTeach(int ID, char * Name) {
	for (Teacher *temp = teach.head; temp != NULL; temp = temp->next) {
		if (temp->ID_Teacher == ID) {
		temp->FIO = Name;
		return;
		}}}
void changeByIDLess(int IDl, char * Name) {
	for (Lesson *temp = less.head; temp != NULL; temp = temp->next) { 
		if (temp->ID_Lesson == IDl) {
		temp->Name = Name;
		return;
		}}}
void changeByIDAud(int IDa, int VMESTIMOST, bool TIP){
	for (Auditoria *temp = aud.head; temp != NULL; temp = temp->next) { 
		if (temp->ID_Auditoria == IDa) {
		temp->VMESTIMOST = VMESTIMOST;
		temp->TIP = TIP;
		return;
		}}}
void changeByIDGr(int IDg, char * Name , int Quan){
for (Group *temp = gr.head; temp != NULL; temp = temp->next) { 
		if (temp->ID_Group == IDg) {
			temp->Name = Name;
			temp->Quantity = Quan;
			return;
		}}}
void changeByIDUch(int IDu,int ID_Group, int ID_Less, int lekcii, int praktiki,int ID_Teach){
for (Uchplan *temp = uch.head; temp != NULL; temp = temp->next) { 
		if (temp->ID_Uchplan == IDu) {
        temp->ID_Group = ID_Group;
		temp->ID_Less = ID_Less;
		temp->lekcii = lekcii;
		temp->praktiki = praktiki;
		temp->ID_Teach = ID_Teach;
		return;
		}}}
void changeByIDRasp(int IDr, int ID_Uchplan,bool week ,char * Day, int para, int ID_Auditoria){
for (Raspisanie *temp = rasp.head; temp != NULL; temp = temp->next) { 
		if (temp->ID_Raspisanie == IDr) {
		temp->ID_Uchplan = ID_Uchplan;
		temp->week = week;
		temp->Day = Day;
		temp->para = para;
		temp->ID_Auditoria = ID_Auditoria;
		return;}}}

bool existIDTeach(int ID) {
	for (Teacher *temp = teach.head; temp != NULL; temp = temp->next) {
		if (temp->ID_Teacher == ID) {
			return true;
		}
    }
    return false;
}
bool existIDLess(int IDl) {
	for (Lesson *temp = less.head; temp != NULL; temp = temp->next) { 
		if (temp->ID_Lesson == IDl) {
			return true;
		}}
    return false;
}
bool existIDAud(int IDa){
	for (Auditoria *temp = aud.head; temp != NULL; temp = temp->next) { 
		if (temp->ID_Auditoria == IDa) {
			return true;
		}}
    return false;
}
bool existIDGr(int IDg){
for (Group *temp = gr.head; temp != NULL; temp = temp->next) { 
		if (temp->ID_Group == IDg) {
			return true;
		}}
    return false;
}
bool existIDUch(int IDu){
for (Uchplan *temp = uch.head; temp != NULL; temp = temp->next) { 
		if (temp->ID_Uchplan == IDu) {
			return true;
		}
    }
    return false;}
bool existIDRasp(int IDr){
for (Raspisanie *temp = rasp.head; temp != NULL; temp = temp->next) { 
		if (temp->ID_Raspisanie == IDr) {
			return true;
		} }
    return false;
}

void delByValueTeach(int ID){
	while (teach.head != NULL) {
		if (teach.head->ID_Teacher == ID) {
			delByTeachUch(ID);
			delByUchRasp(ID);
			Teacher *tmp = teach.head;
			teach.head = teach.head->next;
			delete tmp;
		} else {
			break;
		}
	}
	if (teach.head == NULL) {
		return;
	}
	Teacher *prevNode = teach.head;
	while (prevNode->next != NULL) {
		if (prevNode->next->ID_Teacher == ID) {
			delByTeachUch(ID);
			Teacher *tmp = prevNode->next;
			prevNode->next = prevNode->next->next;
			delete tmp;
		} else {
			prevNode = prevNode->next;
		}
	}
}
void delByValueLess(int ID){
	while (less.head != NULL) {
		if (less.head->ID_Lesson == ID) {
        delByLessUch(ID);
		delByUchRasp(ID);
			Lesson *temp = less.head;
			less.head = less.head->next;
			delete temp;
		} else {
			break;
		}
	}
	if (less.head == NULL) {
		return;
	}
	Lesson *prevNode = less.head;
	while (prevNode->next != NULL) {
		if (prevNode->next->ID_Lesson == ID) {
		delByLessUch(ID);
			Lesson*temp = prevNode->next;
			prevNode->next = prevNode->next->next;
			delete temp;
		} else {
			prevNode = prevNode->next;
		}
	}

}
void delByValueAud(int ID){
	while (aud.head != NULL) {
		if (aud.head->ID_Auditoria== ID) {
		delByAudRasp(ID);
			Auditoria *temp = aud.head;
			aud.head = aud.head->next;
			delete temp;
		} else {
			break;
		}
	}
	if (aud.head == NULL) {
		return;
	}
	Auditoria *prevNode = aud.head;
	while (prevNode->next != NULL) {
		if (prevNode->next->ID_Auditoria == ID) {
		delByAudRasp(ID);
			Auditoria *temp = prevNode->next;
			prevNode->next = prevNode->next->next;
			delete temp;
		} else {
			prevNode = prevNode->next;
		}}}
void delByValueGr(int ID){
	while (gr.head != NULL) {
		if (gr.head->ID_Group == ID) {
		delByGrUch(ID);
		delByUchRasp(ID);
			Group *temp = gr.head;
			gr.head = gr.head->next;
			delete temp;
		} else {
			break;
		}
	}
	if (gr.head == NULL) {
		return;
	}
	Group *prevNode = gr.head;
	while (prevNode->next != NULL) {
		if (prevNode->next->ID_Group == ID) {
		delByGrUch(ID);
			Group *temp = prevNode->next;
			prevNode->next = prevNode->next->next;
			delete temp;
		} else {
			prevNode = prevNode->next;
		}
	}
}
void delByValueUch(int ID){
	while (uch.head != NULL) {
		if (uch.head->ID_Uchplan == ID) {
		delByUchRasp(ID);
			Uchplan *temp = uch.head;
			uch.head = uch.head->next;
			delete temp;
		} else {
			break;
		}
	}
	if (uch.head == NULL) {
		return;
	}
	Uchplan *prevNode = uch.head;
	while (prevNode->next != NULL) {
		if (prevNode->next->ID_Uchplan == ID) {
		delByUchRasp(ID);
			Uchplan *temp = prevNode->next;
			prevNode->next = prevNode->next->next;
			delete temp;
		} else {
			prevNode = prevNode->next;
		}}}
void delByGrUch(int ID) {
	while (uch.head != NULL) {
		if (uch.head->ID_Group== ID) {
			Uchplan *temp = uch.head;
			uch.head = uch.head->next;
			delete temp;
		} else {
			break;
		}
	}
	if (uch.head == NULL) {
		return;
	}
	Uchplan *prevNode = uch.head;
	while (prevNode->next != NULL) {
		if (prevNode->next->ID_Group == ID) {
			Uchplan *temp = prevNode->next;
			prevNode->next = prevNode->next->next;
			delete temp;
		} else {
			prevNode = prevNode->next;
		}
	}
}
void delByLessUch(int ID) {
	while (uch.head != NULL) {
		if (uch.head->ID_Less== ID) {
			Uchplan *temp = uch.head;
			uch.head = uch.head->next;
			delete temp;
		} else {
			break;
		}
	}
	if (uch.head == NULL) {
		return;
	}
	Uchplan *prevNode = uch.head;
	while (prevNode->next != NULL) {
		if (prevNode->next->ID_Less == ID) {
			Uchplan *temp = prevNode->next;
			prevNode->next = prevNode->next->next;
			delete temp;
		} else {
			prevNode = prevNode->next;
		}
	}
}
void delByTeachUch(int ID) {
	while (uch.head != NULL) {
		if (uch.head->ID_Teach== ID) {
			Uchplan *temp = uch.head;
			uch.head = uch.head->next;
			delete temp;
		} else {
			break;
		}
	}
	if (uch.head == NULL) {
		return;
	}
	Uchplan *prevNode = uch.head;
	while (prevNode->next != NULL) {
		if (prevNode->next->ID_Teach == ID) {
			Uchplan *temp = prevNode->next;
			prevNode->next = prevNode->next->next;
			delete temp;
		} else {
			prevNode = prevNode->next;
		}
	}
}
void delByValueRasp(int ID){
	while (rasp.head != NULL) {
		if (rasp.head->ID_Raspisanie == ID) {
			Raspisanie *temp = rasp.head;
			rasp.head = rasp.head->next;
			delete temp;
		} else {
			break;
		}
	}
	if (rasp.head == NULL) {
		return;
	}
	Raspisanie *prevNode = rasp.head;
	while (prevNode->next != NULL) {
		if (prevNode->next->ID_Raspisanie == ID) {
			Raspisanie *temp = prevNode->next;
			prevNode->next = prevNode->next->next;
			delete temp;
		} else {
			prevNode = prevNode->next;
		}
	}}
void delByUchRasp(int ID) {
	while (rasp.head != NULL) {
		if (rasp.head->ID_Uchplan== ID) {
			Raspisanie *temp = rasp.head;
			rasp.head = rasp.head->next;
			delete temp;
		} else {
			break;
		}
	}
	if (rasp.head == NULL) {
		return;
	}
	Raspisanie *prevNode = rasp.head;
	while (prevNode->next != NULL) {
		if (prevNode->next->ID_Uchplan == ID) {
			Raspisanie *temp = prevNode->next;
			prevNode->next = prevNode->next->next;
			delete temp;
		} else {
			prevNode = prevNode->next;
		}
	}
}
void delByAudRasp(int ID) {
	while (rasp.head != NULL) {
		if (rasp.head->ID_Auditoria == ID) {
			Raspisanie *temp = rasp.head;
			rasp.head = rasp.head->next;
			delete temp;
		} else {
			break;
		}
	}
	if (rasp.head == NULL) {
		return;
	}
	Raspisanie *prevNode = rasp.head;
	while (prevNode->next != NULL) {
		if (prevNode->next->ID_Auditoria == ID) {
			Raspisanie *temp = prevNode->next;
			prevNode->next = prevNode->next->next;
			delete temp;
		} else {
			prevNode = prevNode->next;
		}
	}
}

void printTeach(){
	if(teach.head == NULL){
		cout << "Данные не существует! Пожалуйста, добавьте данные." << endl << endl;
			return;
		}
	cout << "-----------------------------------------------------------------------" << endl;
	cout.setf(ios::left, ios::adjustfield);
	cout << setw(4) << " ID" << setw(30) << "| ФИО" << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	for (Teacher *temp = teach.head; temp != NULL; temp = temp->next) {
		cout << " " << setw(3) << temp->ID_Teacher << "| " << setw(30) << temp->FIO << endl;
	}
	cout << "-----------------------------------------------------------------------" << endl;
}
void printLess(){
		if(less.head == NULL){
		cout << "Данные не существует! Пожалуйста, добавьте данные." << endl << endl;
			return;
		}
	cout << "-----------------------------------------------------------------------" << endl;
	cout.setf(ios::left, ios::adjustfield);
	cout << setw(4) << " ID" << setw(30) << "| Название" << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	for (Lesson *temp = less.head; temp != NULL; temp = temp->next) {
		cout << " " << setw(3) << temp->ID_Lesson << "| " << setw(30) << temp->Name << endl;
	}
	cout << "-----------------------------------------------------------------------" << endl;
}
void printAud(){
	if(aud.head == NULL){
		cout << "Данные не существует! Пожалуйста, добавьте данные." << endl << endl;
			return;
		}
	cout << "-----------------------------------------------------------------------" << endl;
	cout.setf(ios::left, ios::adjustfield);
	cout << setw(4) << " ID" << setw(10) << "|Вместимость"<< setw(30) << "|Тип(0-лекционная,1-Компьютерный класс)" << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	for (Auditoria *temp = aud.head; temp != NULL; temp = temp->next) {
		cout << " " << setw(3) << temp->ID_Auditoria << "| " << setw(10) << temp->VMESTIMOST << "| " <<setw(30) << temp->TIP << endl;
	}
	cout << "-----------------------------------------------------------------------" << endl;
}
void printGr(){
		if(gr.head == NULL){
		cout << "Данные не существует! Пожалуйста, добавьте данные." << endl << endl;
			return;
		}
	cout << "-----------------------------------------------------------------------" << endl;
	cout.setf(ios::left, ios::adjustfield);
	cout << setw(4) << " ID" << setw(12) << "| Название"<< setw(10) << "| Кол-во студентов" << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	for (Group *temp = gr.head; temp != NULL; temp = temp->next) {
		cout << " " << setw(3) << temp->ID_Group << "| " << setw(10) << temp->Name << "| " <<setw(10) << temp->Quantity<< endl;
	}
	cout << "-----------------------------------------------------------------------" << endl;
}
void printUch(){
	if(uch.head == NULL){
		cout << "Данные не существует! Пожалуйста, добавьте данные." << endl << endl;
			return;
		}
	cout << "-----------------------------------------------------------------------" << endl;
	cout.setf(ios::left, ios::adjustfield);
	cout << setw(4) << " ID" << setw(10) << "|ID Группы" << setw(10) << "|ID Дисцип"<< setw(15) << "|Кол-во лекций"<< setw(15) << "|Кол-во практик"<< setw(15) << "|ID Препод"<< endl;
	cout << "-----------------------------------------------------------------------" << endl;
	for (Uchplan *temp = uch.head; temp != NULL; temp = temp->next) {
		cout << " " << setw(3) << temp->ID_Uchplan << "| " << setw(8) << temp->ID_Group << "| "<< setw(8) << temp->ID_Less << "| " <<setw(13) << temp->lekcii << "| " <<setw(13) << temp->praktiki << "| "<<setw(15) << temp->ID_Teach << endl;
	}
	cout << "-----------------------------------------------------------------------" << endl;
}
void printRasp(){
		if(rasp.head == NULL){
		cout << "Данные не существует! Пожалуйста, добавьте данные." << endl << endl;
			return;
		}
	cout << "-----------------------------------------------------------------------" << endl;
	cout.setf(ios::left, ios::adjustfield);
	cout << setw(4) << " ID" << setw(6) << "|ID Ауд."<< setw(12) << "|ID Уч.план"<< setw(10) << "|№ недели"<< setw(15) << "|День нед."<< setw(8) << "|№ пары" << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	for (Raspisanie *temp = rasp.head; temp != NULL; temp = temp->next) {
		cout << " " << setw(3) << temp->ID_Raspisanie << "| " << setw(6) << temp->ID_Auditoria << "| " 
		<<setw(10) << temp->ID_Uchplan << "| " <<setw(8) << temp->week << "| "<<setw(13) << temp->Day << "| "<<setw(8) << temp->para<< endl;
	}
	cout << "-----------------------------------------------------------------------" << endl;
}

void clearTeach(){
	Teacher *temp = teach.head;
	while (temp!=NULL) {
		Teacher *del=temp;
	 	temp=temp->next;
	 	delete del;
	}
	teach.head=NULL;
}
void clearLess(){
	Lesson *temp = less.head;
	while (temp!=NULL) {
		Lesson *del=temp;
	 	temp=temp->next;
	 	delete del;
	}
	less.head=NULL;
}
void clearGr(){
	Group *temp = gr.head;
	while (temp!=NULL) {
		Group *del=temp;
	 	temp=temp->next;
	 	delete del;
	}
	gr.head=NULL;
}
void clearAud(){
	Auditoria *temp = aud.head;
	while (temp!=NULL) {
		Auditoria *del=temp;
	 	temp=temp->next;
	 	delete del;
	}
	aud.head=NULL;
}
void clearUch(){
	Uchplan *temp = uch.head;
	while (temp!=NULL) {
		Uchplan *del=temp;
	 	temp=temp->next;
	 	delete del;
	}
	uch.head=NULL;
}
void clearRasp(){
	Raspisanie *temp = rasp.head;
	while (temp!=NULL) {
		Raspisanie *del=temp;
	 	temp=temp->next;
	 	delete del;
	}
	rasp.head=NULL;
}

void outFileTeach(char * path){
	FILE *out;
	if ((out = fopen(path,"wb")) == NULL) {
		cout << "Файл " << path << "не удалось открыть!" << endl;
		return;
	}
	struct TeacherTemp {
		int ID_Teacher;
		char FIO[80];
	};
	for (Teacher *temp = teach.head; temp != NULL; temp = temp->next) {
		TeacherTemp head;
		head.ID_Teacher = temp->ID_Teacher;
		strcpy(head.FIO, temp->FIO);
		fwrite(&head, sizeof(head), 1, out);
	}
	fclose(out);
}
void outFileLess(char * path){
	FILE *out;
	if ((out = fopen(path,"wb")) == NULL) {
		cout << "Файл " << path << "не удалось открыть!" << endl;
		return;
	}
	struct LessonTemp {
		int ID_Lesson;
		char Name[80];
	};
	for (Lesson *temp = less.head; temp != NULL; temp = temp->next) {
		LessonTemp head;
		head.ID_Lesson = temp->ID_Lesson;
		strcpy(head.Name, temp->Name);
		fwrite(&head, sizeof(head), 1, out);
	}
	fclose(out);
}
void outFileAud(char * path){
	FILE *out;
	if ((out = fopen(path,"wb")) == NULL) {
		cout << "Файл " << path << "не удалось открыть!" << endl;
		return;
	}
	struct AuditoriaTemp {
		int ID_Auditoria;
		bool TIP;
		int VMESTIMOST;
	};
	for (Auditoria *temp = aud.head; temp != NULL; temp = temp->next) {
		AuditoriaTemp head;
		head.ID_Auditoria = temp->ID_Auditoria;
		head.TIP = temp->TIP;
		head.VMESTIMOST = temp->VMESTIMOST;
		fwrite(&head, sizeof(head), 1, out);
	}
	fclose(out);
}
void outFileGr(char * path){
	FILE *out;
	if ((out = fopen(path,"wb")) == NULL) {
		cout << "Файл " << path << "не удалось открыть!" << endl;
		return;
	}
	struct GroupTemp {
		int ID_Group;
		char Name[80];
		int Quantity;
	};
	for (Group *temp = gr.head; temp != NULL; temp = temp->next) {
		GroupTemp head;
		head.ID_Group = temp->ID_Group;
		strcpy(head.Name, temp->Name);
		head.Quantity = temp->Quantity;
		fwrite(&head, sizeof(head), 1, out);
	}
	fclose(out);
}	
void outFileUch(char * path){
	FILE *out;
	if ((out = fopen(path,"wb")) == NULL) {
		cout << "Файл " << path << "не удалось открыть!" << endl;
		return;
	}
	struct UchplanTemp {
		int ID_Uchplan;
		int ID_Group;
		int ID_Less;
		int lekcii;
		int praktiki;
		int ID_Teach;
	};
	for (Uchplan *temp = uch.head; temp != NULL; temp = temp->next) {
		UchplanTemp head;
		head.ID_Uchplan = temp->ID_Uchplan;
		head.ID_Group = temp->ID_Group;
		head.ID_Less = temp->ID_Less;
		head.lekcii = temp->lekcii;
		head.praktiki = temp->praktiki;
		head.ID_Teach = temp->ID_Teach;
		fwrite(&head, sizeof(head), 1, out);
	}
	fclose(out);
}	
void outFileRasp(char * path){
	FILE *out;
	if ((out = fopen(path,"wb")) == NULL) {
		cout << "Файл " << path << "не удалось открыть!" << endl;
		return;
	}
	struct RaspisanieTemp {
		int ID_Raspisanie;
		int ID_Uchplan;
		bool week;
        char Day[80];
		int para;
		int ID_Auditoria;
	};
	for (Raspisanie *temp =rasp.head; temp != NULL; temp = temp->next) {
		RaspisanieTemp head;
		head.ID_Raspisanie = temp->ID_Raspisanie;
		head.ID_Uchplan = temp->ID_Uchplan;
		head.week = temp->week;
		strcpy(head.Day, temp->Day);
		head.para = temp->para;
		head.ID_Auditoria = temp->ID_Auditoria;
		fwrite(&head, sizeof(head), 1, out);
	}
	fclose(out);
}

void inFileTeach(char * path){
	FILE *in;
	if ((in = fopen(path,"rb")) == NULL) {
		cout << "Файл " << path << "не удалось открыть!" << endl;
		return;
	}
	clearTeach();
	struct TeacherTemp {
		int ID_Teacher;
		char FIO[80];
	};
	TeacherTemp head;
	while (fread(&head, sizeof(head), 1, in)) {
		char * tempStr = new char[];
		strcpy(tempStr, head.FIO);
		addTeach(head.ID_Teacher, tempStr);
	}
	fclose(in);
	printTeach();
}
void inFileLess(char * path){
FILE *in;
	if ((in = fopen(path,"rb")) == NULL) {
		cout << "Файл " << path << "не удалось открыть!" << endl;
		return;
	}
	clearLess();
	struct LessonTemp {
		int ID_Lesson;
		char Name[80];
	};
	LessonTemp head;
	while (fread(&head, sizeof(head), 1, in)) {
		char * tempStr = new char[];
		strcpy(tempStr, head.Name);
		addLess(head.ID_Lesson, tempStr);
	}
	fclose(in);
	printLess();
}	
void inFileAud(char * path){
			FILE *in;
	if ((in = fopen(path,"rb")) == NULL) {
		cout << "Файл " << path << "не удалось открыть!" << endl;
		return;
	}
	clearAud();
	struct AuditoriaTemp {
		int ID_Auditoria;
		bool TIP;
		int VMESTIMOST;
	};
	AuditoriaTemp head;
	while (fread(&head, sizeof(head), 1, in)) {
		addAud(head.ID_Auditoria,head.TIP,head.VMESTIMOST);
	}
	fclose(in);
	printAud();
}
void inFileGr(char * path){
	FILE *in;
	if ((in = fopen(path,"rb")) == NULL) {
		cout << "Файл " << path << "не удалось открыть!" << endl;
		return;
	}
	clearGr();
	struct GroupTemp {
		int ID_Group;
		char Name[80];
		int Quantity;
	};
	GroupTemp head;
	while (fread(&head, sizeof(head), 1, in)) {
		char * tempStr = new char[];
		strcpy(tempStr, head.Name);
		addGr(head.ID_Group, tempStr,head.Quantity);
	}
	fclose(in);
	printGr();
}
void inFileUch(char * path){
	 FILE *in;
	if ((in = fopen(path,"rb")) == NULL) {
		cout << "Файл " << path << "не удалось открыть!" << endl;
		return;
	}
	clearUch();
	struct UchplanTemp {
		int ID_Uchplan;
		int ID_Group;
		int ID_Less;
		int lekcii;
		int praktiki;
		int ID_Teach;
	};
	UchplanTemp head;
	while (fread(&head, sizeof(head), 1, in)) {
		addUch(head.ID_Uchplan,head.ID_Group,head.ID_Less,head.lekcii,head.praktiki,head.ID_Teach);
	}
	fclose(in);
	printUch();
} 
void inFileRasp(char * path){
			FILE *in;
	if ((in = fopen(path,"rb")) == NULL) {
		cout << "Файл " << path << "не удалось открыть!" << endl;
		return;
	}
	clearRasp();
	struct RaspisanieTemp {
		int ID_Raspisanie;
		int ID_Uchplan;
		bool week;
        char Day[80];
		int para;
		int ID_Auditoria;
	};
	RaspisanieTemp head;
	while (fread(&head, sizeof(head), 1, in)) {
		char * tempStr = new char[];
		strcpy(tempStr, head.Day);
		addRasp(head.ID_Raspisanie,head.ID_Uchplan,head.week, tempStr,head.para,head.ID_Auditoria);
	}
	fclose(in);
	printRasp();
}
void metod(int IDu,int IDa){
	int lek = 0;
	int prak = 0;
	bool tip;
	for (Uchplan *temp = uch.head; temp != NULL; temp = temp->next){
    for (Raspisanie *temp2 = rasp.head; temp2 != NULL; temp2 = temp2->next){
		if (IDu == temp2->ID_Uchplan) {
for (Auditoria *temp3 = aud.head; temp3 != NULL; temp3 = temp3->next){
 if(IDa == temp3->ID_Auditoria){
	 tip=temp3->TIP;
if(tip==true){
	lek++;}
else{
	prak++;}
 }}
lek == temp->lekcii;
prak == temp->praktiki;
if(lek < temp->lekcii){
	cout<<"Недогрузка лекций в учебном плане: "<<lek - (temp->lekcii)<<"ID Учебного плана: "<<temp->ID_Uchplan<<endl;}
if(lek > temp->lekcii){
cout<<"Перегрузка лекций в учебном плане: "<<(temp->lekcii) - lek<<"ID Учебного плана: "<<temp->ID_Uchplan<<endl;}
if(prak < temp->praktiki){
	cout<<"Недогрузка практик в учебном плане: "<<prak - (temp->praktiki)<<"ID Учебного плана: "<<temp->ID_Uchplan<<endl;}
if(prak > temp->praktiki){
cout<<"Перегрузка практик в учебном плане: "<<(temp->praktiki) - prak<<"ID Учебного плана: "<<temp->ID_Uchplan<<endl;}
		}}}}
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

int myAtoi (char * str) {
	int length = 0;
	while (str[length] != '\0') {
		if (!isdigit(str[length])) {
			return 0;
		}
		length++;
	}
	return atoi(str);
}
bool isExitFromCat;
		int ID;
		char*name;
		char *value;
		int a,b,c;
bool type;
int d;
int kolvo;

void menu(List &st) {
	do {
		isExitFromCat = false;
for (int i = 0; i<30; i++)
	cout << "-";	
cout << endl << "Главное меню" << endl;
for (int i = 0; i<30; i++)
	cout << "-";

cout << endl << "Дисциплины - 1" << endl;
cout << "Группа - 2" << endl;
cout << "Преподаватели - 3" << endl;
cout << "Учебный план - 4" << endl;
cout << "Аудитория - 5" << endl;
cout << "Расписание - 6" << endl;
cout << "Отчет - 7" << endl;
cout << "Выход - 8" << endl;
		
		do {
			inputStr(value);
			cout << endl;
			if ((myAtoi(value) >= 1) && (myAtoi(value) <= 8)) {
				break;
			}
			cout << endl << "Попытайтесь снова: " << endl;
		} while (true);
		if (myAtoi(value) == 7){
			system ("cls");
		}
		switch(myAtoi(value)) {
		case 1:
			cout << "Выбор - Дисциплина" << endl;

			do {
				isExitFromCat = false;
for (int i = 0; i<30; i++)
cout << "-";	
cout << endl << "Меню таблицы" << endl;
for (int i = 0; i<30; i++)
	cout << "-";
	 cout <<endl<< "Считать из файла - 1" << endl;
	 cout << "Добавить - 2" << endl;
	 cout << "Изменить - 3" << endl;
	 cout << "Удалить - 4" << endl;
	 cout << "Записать в файл - 5" << endl;
	 cout << "Вывести на экран - 6" << endl;
	 cout << "Назад - 7" << endl;
	 cout << endl << "Введите команду:";

				do {
					inputStr(value);
					cout << endl;
					if ((myAtoi(value) >= 1) && (myAtoi(value) <= 7)) {
						break;
					}
					cout << endl << "Попытайтесь снова: " << endl;
				} while (true);
				switch(myAtoi(value)) {
				case 1:
					cout << "Выбор - Считывание с файла" << endl;
					cout << "Ввести путь к файлу" << endl;
					inputStr(name);
					cout << endl;
					st.inFileLess(name);
					cout << endl;
					break;

				case 2:
					cout << "Выбор - Добавить элемент" << endl;
					do {
						srand(time(NULL));
						ID = rand() % 100 + 1;
						if (!st.existIDLess(ID)) {
							break;
						}
					} while(true);
					cout << "Ввод - Название" << endl;
					inputStr(name);
					cout << endl;
					st.addLess(ID, name);
					break;

				case 3:
					cout << "Выбор - Изменить элемент" << endl;
					cout << "Ввод ID" << endl;

					do {
						inputStr(value);
						cout << endl;
						if (!st.existIDLess(myAtoi(value))) {
							cout << "Ошибка ввода ID" << endl << "Попытайтесь снова: ";
						} else {
							break;
						}
					} while (true);
					cout << "Ввод - Новое название" << endl;
					inputStr(name);
					st.changeByIDLess(myAtoi(value), name);
					break;

				case 4:
					cout << "Выбор - Удалить элемент" << endl;
					cout << "Ввод ID" << endl;
					do {
						inputStr(value);
						cout << endl;
						if (!st.existIDLess(myAtoi(value))) {
							cout << "Ошибка ввода ID Дисциплины" << endl << "Попытайтесь снова: ";
						} else {
							break;
						}
					} while (true);
					st.delByValueLess(myAtoi(value));
					break;

				case 5:
					cout << "Выбор - Запись в файл" << endl;
					cout << "Ввод пути к файлу" << endl;
					inputStr(name);
					cout << endl;
					st.outFileLess(name);
					cout << endl;
					break;

				case 6:
					st.printLess();
					break;

				case 7:
					isExitFromCat = true;
					break;
				}
			} while (!isExitFromCat);

			isExitFromCat = false;
			cout << "Назад" << endl;
			break;

			case 2:
			cout << "Выбор - Группа" << endl;

			do {
				isExitFromCat = false;
for (int i = 0; i<30; i++)
cout << "-";	
cout << endl << "Меню таблицы" << endl;
for (int i = 0; i<30; i++)
	cout << "-";
	
	 cout <<endl<< "Считать из файла - 1" << endl;
	 cout << "Добавить - 2" << endl;
	 cout << "Изменить - 3" << endl;
	 cout << "Удалить - 4" << endl;
	 cout << "Записать в файл - 5" << endl;
	 cout << "Вывести на экран - 6" << endl;
	 cout << "Назад - 7" << endl;
	 cout << endl << "Введите команду:";

				do {
					inputStr(value);
					cout << endl;
					if ((myAtoi(value) >= 1) && (myAtoi(value) <= 7)) {
						break;
					}
					cout << endl << "Попытайтесь снова: " << endl;
				} while (true);
				switch(myAtoi(value)) {
				case 1:
					cout << "Выбор - Считывание с файла" << endl;
					cout << "Ввести путь к файлу" << endl;
					inputStr(name);
					cout << endl;
					st.inFileGr(name);
					cout << endl;
					break;
					
				case 2:
					cout << "Выбор - Добавить элемент" << endl;
					do {
						srand(time(NULL));
						ID = rand() % 100 + 1;
						if (!st.existIDGr(ID)){
							break;}
					}while(true);
					cout << "Ввод - Название" << endl;
					inputStr(name);
					cout << endl;
					cout << "Ввод - Количество студентов" << endl;
					do {
						inputStr(value);
						cout << endl;
						if (myAtoi(value) == 0) {
							cout << "Ошибка ввода Количество студентов" << endl << "Попытайтесь снова: ";
						} else {
							break;
						}
					} while (true);
					kolvo = myAtoi(value);
					st.addGr(ID, name, kolvo);
					break;
					
				case 3:
					cout << "Выбор - Изменить элемент" << endl;
					cout << "Ввод ID" << endl;

					do {
						inputStr(value);
						cout << endl;
						if (!st.existIDGr(myAtoi(value))) {
							cout << "Ошибка ввода ID Группы" << endl << "Попытайтесь снова: ";
						} else {
							break;
						}
					} while (true);
					ID = myAtoi(value);
					cout << "Ввод - Новое название" << endl;
					inputStr(name);
					cout << endl;
					cout << "Ввод - Количество студентов" << endl;
					do {
						inputStr(value);
						cout << endl;
						if (myAtoi(value) == 0) {
							cout << "Ошибка ввода количества студентов" << endl << "Попытайтесь снова: ";
						} else {
							break;
						}
					} while (true);
					kolvo = myAtoi(value);
					st.changeByIDGr(ID, name,kolvo);
					break;

				case 4:
					cout << "Выбор - Удалить элемент" << endl;
					cout << "Ввод ID" << endl;
					do {
						inputStr(value);
						cout << endl;
						if (!st.existIDGr(myAtoi(value))) {
							cout << "Ошибка ввода ID" << endl << "Попытайтесь снова: ";
						} else {
							break;
						}
					} while (true);
					st.delByValueGr(myAtoi(value));
					break;

				case 5:
					cout << "Выбор - Запись в файл" << endl;
					cout << "Ввести путь к файлу" << endl;
					inputStr(name);
					cout << endl;
					st.outFileGr(name);
					cout << endl;
					break;

				case 6:
					st.printGr();
					break;

				case 7:
					isExitFromCat = true;
					break;
				}
			} while (!isExitFromCat);

			isExitFromCat = false;
			cout << "Назад" << endl;
			break;


		case 3:
			cout << "Выбор - Преподаватель" << endl;

			do {
				isExitFromCat = false;
for (int i = 0; i<30; i++)
cout << "-";	
cout << endl << "Меню таблицы" << endl;
for (int i = 0; i<30; i++)
	cout << "-";
	
	 cout <<endl<< "Считать из файла - 1" << endl;
	 cout << "Добавить - 2" << endl;
	 cout << "Изменить - 3" << endl;
	 cout << "Удалить - 4" << endl;
	 cout << "Записать в файл - 5" << endl;
	 cout << "Вывести на экран - 6" << endl;
	 cout << "Назад - 7" << endl;
	 cout << endl << "Введите команду:";

				do {
					inputStr(value);
					cout << endl;
					if ((myAtoi(value) >= 1) && (myAtoi(value) <= 7)) {
						break;
					}
					cout << endl << "Попытайтесь снова: " << endl;
				} while (true);
				switch(myAtoi(value)) {

				case 1:
					cout << "Выбор - Считывание с файла" << endl;
					cout << "Ввести путь к файлу" << endl;
					inputStr(name);
					cout << endl;
					st.inFileTeach(name);
					cout << endl;
					break;
					
				case 2:
					cout << "Выбор - Добавить элемент" << endl;
						do {
						srand(time(NULL));
						ID = rand() % 100 + 1;
						if (!st.existIDTeach(ID)){
							break;}
					}while(true);
					cout << "Ввод ФИО" << endl;
					inputStr(name);
					cout << endl;
					st.addTeach(ID, name);
					break;
					
				case 3:
					cout << "Выбор - Изменить элемент" << endl;
					cout << "Ввод ID" << endl;

					do {
						inputStr(value);
						cout << endl;
						if (!st.existIDTeach(myAtoi(value))) {
							cout << "Ошибка ввода ID преподавателя" << endl << "Попытайтесь снова: ";
						} else {
							break;
						}
					} while (true);
					 ID = myAtoi(value);
					cout << "Ввод нового ФИО" << endl;
					inputStr(name);
					st.changeByIDTeach(ID, name);
					break;

				case 4:
					cout << "Выбор - Удалить элемент" << endl;
					cout << "Ввод ID" << endl;
					do {
						inputStr(value);
						cout << endl;
						if (!st.existIDTeach(myAtoi(value))) {
							cout << "Ошибка ввода ID" << endl << "Попытайтесь снова: ";
						} else {
							break;
						}
					} while (true);
					st.delByValueTeach(myAtoi(value));
					break;

				case 5:
					cout << "Выбор - Запись в файл" << endl;
					cout << "Ввести путь к файлу" << endl;
					inputStr(name);
					cout << endl;
					st.outFileTeach(name);
					cout << endl;
					break;

				case 6:
					st.printTeach();
					break;

				case 7:
					isExitFromCat = true;
					break;
				}
			} while (!isExitFromCat);

			isExitFromCat = false;
			cout << "Назад" << endl;
			break;

		case 4:
			cout << "Выбор - Учебный план" << endl;

			do {
				isExitFromCat = false;
for (int i = 0; i<30; i++)
cout << "-";	
cout << endl << "Меню таблицы" << endl;
for (int i = 0; i<30; i++)
	cout << "-";
	
	 cout <<endl<< "Считать из файла - 1" << endl;
	 cout << "Добавить - 2" << endl;
	 cout << "Изменить - 3" << endl;
	 cout << "Удалить - 4" << endl;
	 cout << "Записать в файл - 5" << endl;
	 cout << "Вывести на экран - 6" << endl;
	 cout << "Назад - 7" << endl;
	 cout << endl << "Введите команду:";

				do {
					inputStr(value);
					cout << endl;
					if ((myAtoi(value) >= 1) && (myAtoi(value) <= 7)) {
						break;
					}
					cout << endl << "Попытайтесь снова: " << endl;
				} while (true);
				switch(myAtoi(value)) {

				case 1:
					cout << "Выбор - Считывание с файла" << endl;
					cout << "Ввести путь к файлу" << endl;
					inputStr(name);
					cout << endl;
					st.inFileUch(name);
					cout << endl;
					break;
					
				case 2:
					cout << "Выбор - Добавить элемент" << endl;
					do {
						srand(time(NULL));
						ID = rand() % 100 + 1;
						if (!st.existIDUch(ID)){
							break;}
					}while(true);
					cout << "Ввод ID Группы" << endl;
					do {
						inputStr(value);
						cout << endl;
						if ((st.existIDGr(myAtoi(value)))) {
							break;
						}else {
							cout << "Ошибка ввода ID Группы" << endl << "Попытайтесь снова: "; 
						}
					} while (true);
					kolvo = myAtoi(value);
					cout << "Ввод ID Дисциплины" << endl;
					do {
						inputStr(value);
						cout << endl;
						if (!st.existIDLess(myAtoi(value))) {
							cout << "Ошибка ввода ID Дисциплины" << endl << "Попытайтесь снова: ";
						} else {
							break;
						}
					} while (true);
					a = myAtoi(value);
					cout << "Ввод - Количество лекций "<< endl;
					do {
						inputStr(value);
						cout << endl;
						if (myAtoi(value) == 0) {
							cout << "Ошибка ввода Количества лекций" << endl << "Попытайтесь снова: ";
						} else {
							break;
						}
					} while (true);
					b = myAtoi(value);
					cout << "Ввод - Количество практик" << endl;
					do {
						inputStr(value);
						cout << endl;
						if (myAtoi(value) == 0) {
							cout << "Ошибка ввода Количества практик" << endl << "Попытайтесь снова: ";
						} else {
							break;
						}
					} while (true);
					c = myAtoi(value);
					cout << "Ввод - ID преподавателя" << endl;
					do {
						inputStr(value);
						cout << endl;
						if ((st.existIDTeach(myAtoi(value)))) {
							break;
						}else {
							cout << "Ошибка ввода ID преподавателя" << endl << "Попытайтесь снова: "; 
						}
					} while (true);
					d = myAtoi(value);
					st.addUch(ID, kolvo, a, b, c, d);
					break;
					
				case 3:
					cout << "Выбор - Изменить элемент" << endl;
					cout << "Ввод ID Учебного плана" << endl;

					do {
						inputStr(value);
						cout << endl;
						if (!st.existIDUch(myAtoi(value))) {
							cout << "Ошибка ввода ID Учебного плана" << endl << "Попытайтесь снова: ";
						} else {
							break;
						}
					} while (true);
					 ID = myAtoi(value);
					cout << "Ввод ID Группы" << endl;
					do {
						inputStr(value);
						cout << endl;
						if ((st.existIDGr(myAtoi(value)))) {
							break;
						}else {
							cout << "Ошибка ввода ID Группы" << endl << "Попытайтесь снова: "; 
						}
					} while (true);
					kolvo = myAtoi(value);
					cout << "Ввод ID Дисциплины" << endl;
					do {
						inputStr(value);
						cout << endl;
						if (!st.existIDLess(myAtoi(value))) {
							cout << "Ошибка ввода ID Дисциплины" << endl << "Попытайтесь снова: ";
						} else {
							break;
						}
					} while (true);
					a = myAtoi(value);
					cout << "Ввод - Количество лекций" << endl;
					do {
						inputStr(value);
						cout << endl;
						if (myAtoi(value) == 0) {
							cout << "Ошибка ввода Количество лекций" << endl << "Попытайтесь снова: ";
						} else {
							break;
						}
					} while (true);
					b = myAtoi(value);
					cout << "Ввод - Количество практик" << endl;
					do {
						inputStr(value);
						cout << endl;
						if (myAtoi(value) == 0) {
							cout << "Ошибка ввода Количества практик" << endl << "Попытайтесь снова: ";
						} else {
							break;
						}
					} while (true);
					c = myAtoi(value);
					cout << "Ввод ID преподавателя" << endl;
					do {
						inputStr(value);
						cout << endl;
						if ((st.existIDTeach(myAtoi(value)))) {
							break;
						}else {
							cout << "Ошибка ввода ID преподавателя" << endl << "Попытайтесь снова: "; 
						}
					} while (true);
					d = myAtoi(value);
					st.changeByIDUch(ID, kolvo, a, b, c, d);
					break;

				case 4:
					cout << "Выбор - Удалить элемент" << endl;
					cout << "Ввод ID Учебного плана" << endl;
					do {
						inputStr(value);
						cout << endl;
						if (!st.existIDUch(myAtoi(value))) {
							cout << "Ошибка ввода ID Учебного плана" << endl << "Попытайтесь снова: ";
						} else {
							break;
						}
					} while (true);
					st.delByValueUch(myAtoi(value));
					break;

				case 5:
					cout << "Выбор - Запись в файл" << endl;
					cout << "Ввести путь к файлу" << endl;
					inputStr(name);
					cout << endl;
					st.outFileUch(name);
					cout << endl;
					break;

				case 6:
					st.printUch();
					break;

				case 7:
					isExitFromCat = true;
					break;
				}
			} while (!isExitFromCat);

			isExitFromCat = false;
			cout << "Назад" << endl;
			break;

		case 5:
			cout << "Выбор - Аудитория" << endl;

			do {
				isExitFromCat = false;
for (int i = 0; i<30; i++)
cout << "-";	
cout << endl << "Меню таблицы" << endl;
for (int i = 0; i<30; i++)
	cout << "-";
	
	 cout <<endl<< "Считать из файла - 1" << endl;
	 cout << "Добавить - 2" << endl;
	 cout << "Изменить - 3" << endl;
	 cout << "Удалить - 4" << endl;
	 cout << "Записать в файл - 5" << endl;
	 cout << "Вывести на экран - 6" << endl;
	 cout << "Назад - 7" << endl;
	 cout << endl << "Введите команду:";

				do {
					inputStr(value);
					cout << endl;
					if ((myAtoi(value) >= 1) && (myAtoi(value) <= 7)) {
						break;
					}
					cout << endl << "Попытайтесь снова: " << endl;
				} while (true);
				switch(myAtoi(value)) {

				case 1:
					cout << "Выбор - Считывание с файла" << endl;
					cout << "Ввести путь к файлу" << endl;
					inputStr(name);
					cout << endl;
					st.inFileAud(name);
					cout << endl;
					break;
					
				case 2:
					cout << "Выбор - Добавить элемент" << endl;
					do {
						srand(time(NULL));
						ID = rand() % 100 + 1;
						if (!st.existIDAud(ID)){
							break;}
					}while(true);
					cout << "Выберите - Тип Аудитории" << endl;
					cout << "1. Лекционная" << endl;
					cout << "2. Компьютерный класс" << endl;
				do {
					inputStr(value);
					cout << endl;
					if ((myAtoi(value) >= 1) && (myAtoi(value) <= 2)) {
						break;
					}
					cout << endl << "Попытайтесь снова: " << endl;
				} while (true);
					switch(myAtoi(value)) {
					case 1:
					type = false;
						break;
					case 2:
						type = true; 
						break;
				}
					cout << "Ввод - Вместимость" << endl;
					do {
						inputStr(value);
						cout << endl;
						if (myAtoi(value) == 0) {
							cout << "Ошибка ввода Вместимость" << endl << "Попытайтесь снова: ";
						} else {
							break;
						}
					} while (true);
					kolvo = myAtoi(value);
					st.addAud(ID, kolvo, type);
					break;

					
				case 3:
					cout << "Выбор - Изменить элемент" << endl;
					cout << "Ввод ID Аудитории" << endl;

					do {
						inputStr(value);
						cout << endl;
						if (!st.existIDAud(myAtoi(value))) {
							cout << "Ошибка ввода ID Аудитории" << endl << "Попытайтесь снова: ";
						} else {
							break;
						}
					} while (true);
					 ID = myAtoi(value);
					 					cout << "Выберите - Тип" << endl;
					cout << "1. Лекционная аудитория" << endl;
					cout << "2. Компьютерный класс" << endl;
				do {
					inputStr(value);
					cout << endl;
					if ((myAtoi(value) >= 1) && (myAtoi(value) <= 2)) {
						break;
					}
					cout << endl << "Попытайтесь снова " << endl;
				} while (true);

				switch(myAtoi(value)) {
					case 1:
					type = false;
						break;
					case 2:
						type = true; 
						break;
				}
					cout << "Ввод - Вместимость" << endl;
					do {
						inputStr(value);
						cout << endl;
						if (myAtoi(value) == 0) {
							cout << "Ошибка ввода Вместимость" << endl << "Попытайтесь снова: ";
						} else {
							break;
						}
					} while (true);
					kolvo = myAtoi(value);
					st.changeByIDAud(ID, kolvo, type);
					break;

				case 4:
					cout << "Выбор - Удалить элемент " << endl;
					cout << "Ввод ID" << endl;
					do {
						inputStr(value);
						cout << endl;
						if (!st.existIDAud(myAtoi(value))) {
							cout << "Ошибка ввода ID Аудитории" << endl << "Попытайтесь снова: ";
						} else {
							break;
						}
					} while (true);
					st.delByValueAud(myAtoi(value));
					break;

				case 5:
					cout << "Выбор - Запись в файл" << endl;
					cout << "Ввести путь к файлу" << endl;
					inputStr(name);
					cout << endl;
					st.outFileAud(name);
					cout << endl;
					break;

				case 6:
					st.printAud();
					break;

				case 7:
					isExitFromCat = true;
					break;
				}
			} while (!isExitFromCat);

			isExitFromCat = false;
			cout << "Назад" << endl;
			break;

	case 6:
			cout << "Выбор - Расписание" << endl;

			do {
				isExitFromCat = false;
for (int i = 0; i<30; i++)
cout << "-";	
cout << endl << "Меню таблицы" << endl;
for (int i = 0; i<30; i++)
	cout << "-";
	
	 cout <<endl<< "Считать из файла - 1" << endl;
	 cout << "Добавить - 2" << endl;
	 cout << "Изменить - 3" << endl;
	 cout << "Удалить - 4" << endl;
	 cout << "Записать в файл - 5" << endl;
	 cout << "Вывести на экран - 6" << endl;
	 cout << "Назад - 7" << endl;
	 cout << endl << "Введите команду:";

				do {
					inputStr(value);
					cout << endl;
					if ((myAtoi(value) >= 1) && (myAtoi(value) <= 7)) {
						break;
					}
					cout << endl << "Попытайтесь снова: " << endl;
				} while (true);
				switch(myAtoi(value)) {

				case 1:
					cout << "Выбор - Считывание с файла" << endl;
					cout << "Ввести путь к файлу" << endl;
					inputStr(name);
					cout << endl;
					st.inFileRasp(name);
					cout << endl;
					break;
					
				case 2:
					cout << "Выбор - Добавить элемент" << endl;
					do {
						srand(time(NULL));
						ID = rand() % 100 + 1;
						if (!st.existIDRasp(ID)){
							break;}
					}while(true);

					cout << "Ввод ID Учебного плана" << endl;
					do {
						inputStr(value);
						cout << endl;
						if ((st.existIDUch(myAtoi(value)))) {
							break;
						}else {
							cout << "Ошибка воода ID Учебного плана" << endl << "Попытайтесь снова: "; 
						}
					} while (true);
					d = myAtoi(value);
					cout << "Выбор - неделя" << endl;
					cout << "1. Первая" << endl;
					cout << "2. Вторая" << endl;
				do {
					inputStr(value);
					cout << endl;
					if ((myAtoi(value) >= 1) && (myAtoi(value) <= 2)) {
						break;
					}
					cout << endl << "Попытайтесь снова: " << endl;
				} while (true);
				
				switch(myAtoi(value)) {
					case 1:
						type = false;
						break;
					case 2:
						type = true; 
						break;
				}
				cout << "Ввод - День недели" << endl;
									inputStr(name);
									cout << endl;
									cout << "Ввод № пары" << endl;
					do {
						inputStr(value);
						cout << endl;
						if (myAtoi(value) == 0) {
							cout << "Ошибка ввода № пары" << endl << "Попытайтесь снова: ";
						} else {
							break;
						}
					} while (true);
					b = myAtoi(value);
					cout << "Ввод ID Аудитории" << endl;
					do {
						inputStr(value);
						cout << endl;
						if ((st.existIDAud(myAtoi(value)))) {
							break;
						}else {
							cout << "Ошибка ввода ID Аудитории" << endl << "Попытайтесь снова "; 
						}
					} while (true);
					c = myAtoi(value);
					st.addRasp(ID, d, type, name, b, c);
					break;

					
				case 3:
					cout << "Выбор - Изменить элемент" << endl;
					cout << "Ввод ID Расписания" << endl;

					do {
						inputStr(value);
						cout << endl;
						if (!st.existIDRasp(myAtoi(value))) {
							cout << "Ошибка ввода ID Расписания" << endl << "Попытайтесь снова: ";
						} else {
							break;
						}
					} while (true);
					 ID = myAtoi(value);
					cout << "Ввод ID Учебного плана" << endl;
					do {
						inputStr(value);
						cout << endl;
						if ((st.existIDUch(myAtoi(value)))) {
							break;
						}else {
							cout << "Ошибка ввода ID Учебного плана" << endl << "Попытайтесь снова: "; 
						}
					} while (true);
					d = myAtoi(value);
					cout << "Выбор - Неделя" << endl;
					cout << "1. первая" << endl;
					cout << "2. вторая" << endl;
				do {
					inputStr(value);
					cout << endl;
					if ((myAtoi(value) >= 1) && (myAtoi(value) <= 2)) {
						break;
					}
					cout << endl << "Попытайтесь снова: " << endl;
				} while (true);
				switch(myAtoi(value)) {
					case 1:
						type = false;
						break;
					case 2:
						type = true; 
						break;
				}
				cout << "Ввод Дня недели" << endl;
									inputStr(name);
									cout << endl;
									cout << "Ввод № пары" << endl;
					do {
						inputStr(value);
						cout << endl;
						if (myAtoi(value) == 0) {
							cout << "Ошибка ввода № пары" << endl << "Попытайтесь снова: ";
						} else {
							break;
						}
					} while (true);
					b = myAtoi(value);
					cout << "Ввод Аудитории" << endl;
					do {
						inputStr(value);
						cout << endl;
						if ((st.existIDAud(myAtoi(value)))) {
							break;
						}else {
							cout << "Ошибка ввода ID Аудитории" << endl << "Попытайтесь снова: "; 
						}
					} while (true);
					c = myAtoi(value);
					st.addRasp(ID, d, type, name, b, c);
					break;

				case 4:
					cout << "Выбор - Удалить элемент" << endl;
					cout << "Ввод ID" << endl;
					do {
						inputStr(value);
						cout << endl;
						if (!st.existIDRasp(myAtoi(value))) {
							cout << "Ошибка ввода ID" << endl << "Попытайтесь снова: ";
						} else {
							break;
						}
					} while (true);
					st.delByValueRasp(myAtoi(value));
					break;

				case 5:
					cout << "Выбор - Запись в файл" << endl;
					cout << "Ввести путь к файлу" << endl;
					inputStr(name);
					cout << endl;
					st.outFileRasp(name);
					cout << endl;
					break;

				case 6:
					st.printRasp();
					break;

				case 7:
					isExitFromCat = true;
					break;
				}
			} while (!isExitFromCat);

			isExitFromCat = false;
			cout << "Назад" << endl;
			break;

     case 7:
			cout << "Выбор - Отчет нагрузки расписания" << endl;
			cout<<"Ввод ID Учебного плана:"<<endl;
			int IDu,IDa;
			do {
					inputStr(value);
					cout << endl;
					if ((st.existIDUch(myAtoi(value)))) {
							break;
						}else {
							cout << "Ошибка ввода ID Учебного плана" << endl << "Попытайтесь снова: "; }
					} 
				while(true);
			cout<<"Ввод ID Aудитории:"<<endl;
					do {
					inputStr(value);
					cout << endl;
					if ((st.existIDAud(myAtoi(value)))) {
							break;
						}else {
							cout << "Ошибка ввода ID Аудитории" << endl << "Попытайтесь снова: "; }
				} while(true);				
					st.metod(IDu,IDa);
									
					
				
			

			isExitFromCat = false;
			cout << "Назад" << endl;
			break;
case 8:
			isExitFromCat = true;
			break;
		}
	} while (!isExitFromCat);
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	List st[5];
	bool flag = false;

	do {
		flag = false;
		cout << "Выбрать ВУЗ:" << endl;
		cout << "1. Ulianovsk State University" << endl;
		cout << "2. Yale University" << endl;
		cout << "3. Harvard University" << endl;
		cout << "4. Oxford University" << endl;
		cout << "5. Cambridge University" << endl;
		cout << "6. Exit" << endl;

		do {
			inputStr(value);
			cout << endl;
			if ((myAtoi(value) >= 1) && (myAtoi(value) <= 7)) {
				break;
			}
			cout << endl << "Попытайтесь снова: " << endl;
		} while (true);
		system ("cls");
		switch(myAtoi(value)) {	
		case 6:
			flag = true;
			break;
		default:
			menu(st[0]);
			break;
				
		}
	} while (!flag);
	return 0;
}

