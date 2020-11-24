#ifndef LESSON_H
#define LESSON_H
#include <iostream>
#include <string>
using namespace std;
class Lesson
{
	public:
		Lesson();
		Lesson(int ,string,string ,int ,int  );
        setID(int );
        int getID();
        setName(string);
        string getName();
        setDay(string );
		setStarthour(int );
		setDuration(int );
		string getDay();
		int getStartHour();
		int getDuration();
		~Lesson();
	private:
		int ID;
		string day,name;
		int startHour,duration;
		
		
};

#endif
