// created by Zekeriyya Demirci
// bunu furkan de�i�tirir kii 

#include <iostream>
#include "Lesson.h"
#include "Student.h"
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

vector <Student> students;   // global deg�skenler   ogrenc�ler �c�n
vector <Lesson> lessons;   // global deg�skenler    dersler �c�n
long int s_id=15212000;	
int l_id=1000;


bool AddStudent(string name,string surname)
{
	try
	{
	Student s1(name,surname,s_id);  // ogrenc� ekl�yor
	students.push_back(s1);
	s_id++;
	return true;
	}
	catch(int i)
	{
		cout<<"AddStudent catch !!";
		return false;
	}
}

void AddLesson(string name,string day,int startHour,int duration)
{
	try
	{
	Lesson l1(l_id,name,day,startHour,duration);  // ders ekl�yor
	lessons.push_back(l1);
	l_id++;
	}
	catch(int i)
	{
		cout<<"AddLesson catch !!";
	}
}

void printLessons()
{
	for(int i=0;i<lessons.size();i++)
	{
		cout<<"Lesson ID : "<<lessons[i].getID();
		cout<<" Name : "<<lessons[i].getName();
		cout<<" Day : "<<lessons[i].getDay();
		cout<<" Start Hour : "<<lessons[i].getStartHour();
		cout<<" Duration : "<<lessons[i].getDuration();
		cout<<endl;
	}
	cout<<endl;
}

void printStudents()
{
	for(int i=0;i<students.size();i++)
	{
		cout<<setw( -30 )<<"Students ID : "<<students[i].getID();
		cout<<setw( -30 )<<" Name : "<<students[i].getName();
		cout<<setw( -60 )<<" Surname : "<<students[i].getSurname();
		cout<<endl;
		vector<int>courses;  // dersler�n� yazd�rmak �c�n
		courses=students[i].getCourses();
		for(int i=0;i<courses.size();i++)
		{
			// detayland�r�lab�l�r.
			cout<<i<<". lesson: "<<courses[i]<<"  ";
		}
		cout<<endl;
		cout<<"------------------------------------\n";
	}
}

Student getStudent(int s_id)  // id si verilen ogtenc�n� hesab�n� ger� donduruyor. ad� dersler� vs. er�smek �c�n
{
	for(int i=0;i<students.size();i++)  // tum ogrenc�ler
	{
		if(students[i].getID()==s_id)  // student bulundu
		{
			return students[i];// dogrenc� yoksa default �d = -1 olur.
			break;
		}
	}
	Student s; // ogrenc� yoksa default �d = -1 olur.
	return s;
}

Lesson getLesson(int id)  // id si verilen ders� hesab�n� ger� donduruor. 
{
	for(int i=0;i<lessons.size();i++)  // ders var m� d�ye kontrol ed�yor
	{
		if(id==lessons[i].getID())
		{
			return lessons[i];  // ders yoksa default �d = -1 olur.
			break;
		}
	}
	Lesson l; // ders yoksa default �d = -1 olur.
	return l;
}

bool checkCourse(int s_id,int l_id)  //  studen �d ,  almak �sted�g� ders�n �d si
{
	Student s;
	Lesson l;
	vector<int> course;
	int flag=1; // dersi seceb�l�r 
	s=getStudent(s_id); // ogrenc�
	l=getLesson(l_id);  // ders
	
	
	course=s.getCourses();  // ogrenc�n�n ald�g� derslerin id si.  ne kar� bee !
	
	for(int i=0;i<course.size();i++) // ogrenc�n�n ald�g� dersler
	{
		Lesson lesson=getLesson(course[i]); // dersin id si ile beraber ders� bulduk. s�md� ad�na gun zaman�na er�s�leb�l�r.
		// lesson : daha once ald�g� derslerden b�r�
		// l : yen� almak �sted�g� ders
		if(course[i]==l.getID())  // id ler ayn�
		{
			flag=0;  // ders cak�st� ayn� ders� daha �nceden ald�
		}
		else  // day ve hour a bak�lacak
		{
			if(lesson.getDay()==l.getDay())  // gunler es�t
			{
				// saate bak�lacak
				for(int i=0;i<lesson.getDuration();i++)  // ders�n sures� kadar d�ner 
				{
					// ders�n sures� kadar baslang�c saat�n� �lerlet�cem. 
					// sonra al�nmak �stenen ders�n baslag�c saat� �le cak�sm�yorsa ders al�nab�l�r�r.
					if(l.getStartHour()==lesson.getStartHour()+i)
					{
						// ders�n basllang�c saat� 9 �c�n;
						// 9+0  9+1   9+2  sekl�nde k�yaslayacak. eger cak�sma varsa flag =0 yan� ders� alamaz.
						flag=0;
						break;			// �nnaya sevg�ler		
					}// end if					
				}// end for durat�on
			}// end �f check day
		}// end else
	} // end for
	
	if(flag==0)
	{
		return false;  // ders al�namaz
	}
	else
	{
		// ders� ekle
		return true;  // ders alnab�l�r
	}
	
}


int main(int argc, char** argv) 
{	   
	AddStudent("zekeriyya","demirci");
	AddStudent("furkan","citilci");
	AddStudent("talha","hayla");
	
	students[0].AddCourse(1000);
	students[0].AddCourse(1006);
	students[0].AddCourse(1002);
	
	AddLesson("oop","pazartesi",9,3); 				// 12 e kadar
	AddLesson("programming","pazartesi",9,3);
	AddLesson("digital","sali",9,3);
	AddLesson("circuit","sali",9,3);
	AddLesson("control","carsamba",9,3);
	AddLesson("signal","carsamba",9,3);
	AddLesson("calculus","carsamba",13,3);
	AddLesson("healty","persembe",9,3);
	AddLesson("pyhsic","cuma",10,3);
	AddLesson("chemist","cuma",12,2);
	
	int c;
	string s_name,s_surname;
	
	while(true)   // genel d�s dongu
	{

		cout<<"------------------------------------\n";
		cout<<"Create Student Account (1)\n";
		cout<<"Show Students Account  (2)\n";
		cout<<"Show Lessons           (3)\n";
		cout<<"Choose Lesson          (4)\n";
		cout<<"Quit                   (0)\n";
		cout<<"------------------------------------\n";
		cout<<"Enter Keyword : ";
		cin>>c;
		
		system("CLS");
		
		if(c==1)   // ogrenc� kayd� eklemek
		{
			cout<<"Write student name: ";
			cin>>s_name;
			cout<<"Write student surname: ";
			cin>>s_surname;
			
			if(AddStudent(s_name,s_surname))  // eklend�yse basar�l�
			{
				cout<<"\nStudent created succesfully !! \n\n";
			}

		}
		else if(c==2)  // ogren�cler� yazd�rma
		{
			printStudents();
		}
		else if(c==3)  // dersler� yazd�rma
		{
			printLessons();
		}
		else if(c==4)  // ogrenc�ye ders ekleme
		{
			int s_id,l_id;
			
			printStudents();  // ogrenc�ler� yaz�rma
			
			while(true)  // ogrenc� car m� yok mu kontrolu
			{
				cout<<"\nEnter Student ID : ";
				cin>>s_id;
				Student temp=getStudent(s_id);
				if(temp.getID()!=-1)  // ogrenc�n�n varl�g�n� sorguluyor.  eger ogrenc� varsa true doner ve �f e g�rer
				{
					break;  // ogrenc� var
				}
				else
				{ // ogrenc� yok
					cout<<"There is any student that have same ID\n";
				}	
			}

			// hang� ogrenc� oldugu yaz�lacak...
			
			printLessons();  // dersler� yaz�dmra

			while(true)
			{
				cout<<"\nEnter Lesson ID : ";
				cin>>l_id;
				Lesson temp=getLesson(l_id);
				if(temp.getID()!=-1)  // lesson varl�g�n� sorguluyor.  eger leson varsa true doner ve �f e g�rer
				{  // ders var
					break;
				}
				else
				{  // ders yok
					cout<<"There is any lesson that have same ID\n";
				}	
			}
			// ogrenc�n hal�haz�rda ald�g� derseler s�ralanacak

			bool check=checkCourse(s_id,l_id);  // ders �e ogrenc�n� dersler� kars�last�r�l�yor. 
			
			if(check)  // true ise �c�ne g�rer yan� ders� alab�l�r
			{
				// ders� alab�l�r.
				for(int i=0;i<students.size();i++)  // tum ogrenc�ler
				{
					if(students[i].getID()==s_id)  // student bulundu
					{
						students[i].AddCourse(l_id);  // ders� ekl�yor
						cout<<"Lesson added successfully\n"; 
						break;
					}
				}			
			}
			else
			{ // ders eklenemez
				cout<<"The selected lesson intersect the other.\n";
			}
			

					
		} // end else
		
		
		if(c==0) { break;	}  // qu�t 
		
		
	}
	 
	
	return 0;
}
