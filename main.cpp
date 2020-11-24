// created by Zekeriyya Demirci
// bunu furkan deðiþtirir kii 

#include <iostream>
#include "Lesson.h"
#include "Student.h"
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

vector <Student> students;   // global degýskenler   ogrencýler ýcýn
vector <Lesson> lessons;   // global degýskenler    dersler ýcýn
long int s_id=15212000;	
int l_id=1000;


bool AddStudent(string name,string surname)
{
	try
	{
	Student s1(name,surname,s_id);  // ogrencý eklýyor
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
	Lesson l1(l_id,name,day,startHour,duration);  // ders eklýyor
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
		vector<int>courses;  // derslerýný yazdýrmak ýcýn
		courses=students[i].getCourses();
		for(int i=0;i<courses.size();i++)
		{
			// detaylandýrýlabýlýr.
			cout<<i<<". lesson: "<<courses[i]<<"  ";
		}
		cout<<endl;
		cout<<"------------------------------------\n";
	}
}

Student getStudent(int s_id)  // id si verilen ogtencýný hesabýný gerý donduruyor. adý derslerý vs. erýsmek ýcýn
{
	for(int i=0;i<students.size();i++)  // tum ogrencýler
	{
		if(students[i].getID()==s_id)  // student bulundu
		{
			return students[i];// dogrencý yoksa default ýd = -1 olur.
			break;
		}
	}
	Student s; // ogrencý yoksa default ýd = -1 olur.
	return s;
}

Lesson getLesson(int id)  // id si verilen dersý hesabýný gerý donduruor. 
{
	for(int i=0;i<lessons.size();i++)  // ders var mý dýye kontrol edýyor
	{
		if(id==lessons[i].getID())
		{
			return lessons[i];  // ders yoksa default ýd = -1 olur.
			break;
		}
	}
	Lesson l; // ders yoksa default ýd = -1 olur.
	return l;
}

bool checkCourse(int s_id,int l_id)  //  studen ýd ,  almak ýstedýgý dersýn ýd si
{
	Student s;
	Lesson l;
	vector<int> course;
	int flag=1; // dersi secebýlýr 
	s=getStudent(s_id); // ogrencý
	l=getLesson(l_id);  // ders
	
	
	course=s.getCourses();  // ogrencýnýn aldýgý derslerin id si.  ne karý bee !
	
	for(int i=0;i<course.size();i++) // ogrencýnýn aldýgý dersler
	{
		Lesson lesson=getLesson(course[i]); // dersin id si ile beraber dersý bulduk. sýmdý adýna gun zamanýna erýsýlebýlýr.
		// lesson : daha once aldýgý derslerden býrý
		// l : yený almak ýstedýgý ders
		if(course[i]==l.getID())  // id ler ayný
		{
			flag=0;  // ders cakýstý ayný dersý daha önceden aldý
		}
		else  // day ve hour a bakýlacak
		{
			if(lesson.getDay()==l.getDay())  // gunler esýt
			{
				// saate bakýlacak
				for(int i=0;i<lesson.getDuration();i++)  // dersýn suresý kadar döner 
				{
					// dersýn suresý kadar baslangýc saatýný ýlerletýcem. 
					// sonra alýnmak ýstenen dersýn baslagýc saatý ýle cakýsmýyorsa ders alýnabýlýrýr.
					if(l.getStartHour()==lesson.getStartHour()+i)
					{
						// dersýn basllangýc saatý 9 ýcýn;
						// 9+0  9+1   9+2  seklýnde kýyaslayacak. eger cakýsma varsa flag =0 yaný dersý alamaz.
						flag=0;
						break;			// ýnnaya sevgýler		
					}// end if					
				}// end for duratýon
			}// end ýf check day
		}// end else
	} // end for
	
	if(flag==0)
	{
		return false;  // ders alýnamaz
	}
	else
	{
		// dersý ekle
		return true;  // ders alnabýlýr
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
	
	while(true)   // genel dýs dongu
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
		
		if(c==1)   // ogrencý kaydý eklemek
		{
			cout<<"Write student name: ";
			cin>>s_name;
			cout<<"Write student surname: ";
			cin>>s_surname;
			
			if(AddStudent(s_name,s_surname))  // eklendýyse basarýlý
			{
				cout<<"\nStudent created succesfully !! \n\n";
			}

		}
		else if(c==2)  // ogrenýclerý yazdýrma
		{
			printStudents();
		}
		else if(c==3)  // derslerý yazdýrma
		{
			printLessons();
		}
		else if(c==4)  // ogrencýye ders ekleme
		{
			int s_id,l_id;
			
			printStudents();  // ogrencýlerý yazýrma
			
			while(true)  // ogrencý car mý yok mu kontrolu
			{
				cout<<"\nEnter Student ID : ";
				cin>>s_id;
				Student temp=getStudent(s_id);
				if(temp.getID()!=-1)  // ogrencýnýn varlýgýný sorguluyor.  eger ogrencý varsa true doner ve ýf e gýrer
				{
					break;  // ogrencý var
				}
				else
				{ // ogrencý yok
					cout<<"There is any student that have same ID\n";
				}	
			}

			// hangý ogrencý oldugu yazýlacak...
			
			printLessons();  // derslerý yazýdmra

			while(true)
			{
				cout<<"\nEnter Lesson ID : ";
				cin>>l_id;
				Lesson temp=getLesson(l_id);
				if(temp.getID()!=-1)  // lesson varlýgýný sorguluyor.  eger leson varsa true doner ve ýf e gýrer
				{  // ders var
					break;
				}
				else
				{  // ders yok
					cout<<"There is any lesson that have same ID\n";
				}	
			}
			// ogrencýn halýhazýrda aldýgý derseler sýralanacak

			bool check=checkCourse(s_id,l_id);  // ders ýe ogrencýný derslerý karsýlastýrýlýyor. 
			
			if(check)  // true ise ýcýne gýrer yaný dersý alabýlýr
			{
				// dersý alabýlýr.
				for(int i=0;i<students.size();i++)  // tum ogrencýler
				{
					if(students[i].getID()==s_id)  // student bulundu
					{
						students[i].AddCourse(l_id);  // dersý eklýyor
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
		
		
		if(c==0) { break;	}  // quýt 
		
		
	}
	 
	
	return 0;
}
