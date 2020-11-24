#include "Student.h"
#include <iostream>
#include "Lesson.h"
using namespace std;
Student::Student()
{
	setID(-1);
}
Student::Student(string name_,string surname_,int ID_)
{
	setName(name_);
	setSurname(surname_);
	setID(ID_);
}
Student::setName(string name_)
{
	name=name_;
}
Student::setID(int ID_)
{
	ID=ID_;
}
Student::setSurname(string surname_)
{
	surname=surname_;
}
string Student::getName()
{
	return name;
}
string Student::getSurname()
{
	return surname;
}
int Student::getID()
{
	return ID;
}
Student::~Student()
{
}
vector<int> Student::getCourses()
{
	return lesson_IDs;
}
void Student::AddCourse(int lesson_id)
{
	lesson_IDs.push_back(lesson_id);
}
void Student::RemoveCourse(int lesson_id)
{
	// todo remove
}
