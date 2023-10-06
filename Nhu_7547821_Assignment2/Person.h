#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
	public:
		std::string name;
		int stance;
		Person(std::string name, int stance);
		Person();
		void setName(std::string n);
		std::string getName();
		void setStance(int stance);
		int getStance();
		void printObj();
};

#endif
