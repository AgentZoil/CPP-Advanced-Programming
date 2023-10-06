#include "Person.h"
#include "Candidate.h"
#include <iostream>

Person::Person(std::string name, int stance) :
name(name), stance(stance) {}

Person::Person(){}

void Person::setName(std::string n)
{
	name = n;
}

std::string Person::getName()
{
	return name;
}

void Person::setStance(int stance)
{
	stance = stance;
}

int Person::getStance()
{
	return stance;
}

void Person::printObj()
{
	std::cout << "Name: " << " | " << "Stance: " << this->stance << std::endl;
}
