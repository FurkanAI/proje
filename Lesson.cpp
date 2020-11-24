#include "Lesson.h"
#include <iostream>

using namespace std;
Lesson::Lesson()
{
	setID(-1);
}
Lesson::Lesson(int ID_,string name_,string day_,int startHour_,int duration_)
{
    setID(ID_);
    setDay(day_);
    setStarthour(startHour_);
    setDuration(duration_);
    setName(name_);
}
Lesson::setID(int ID_) 
{
    ID=ID_;
}
int Lesson::getID()
{
    return ID;
}
Lesson::setName(string name_)
{
	name=name_;
}
string Lesson::getName()
{
	return name;
}
Lesson::setDay(string day_)
{
	day=day_;
}
Lesson::setStarthour(int startHour_)
{
	startHour=startHour_;
}
Lesson::setDuration(int duration_)
{
	duration=duration_;
}
string Lesson::getDay()
{
	return day;
}
int Lesson::getStartHour()
{
	return startHour;
}
int Lesson::getDuration()
{
	return duration;
}
Lesson::~Lesson()
{
}
