#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Student
{
	public:
		Student(string,string,int );
		Student();
		setName(string );
		setSurname(string );
		setID(int ID_);
		string getName();
		string getSurname();
		int getID();
		vector<int> getCourses();
		void AddCourse(int lesson_id);
		void RemoveCourse(int lesson_id);
		
		~Student();
	private:
		string name,surname;
		int ID;
		vector<int> lesson_IDs;
};

#endif
