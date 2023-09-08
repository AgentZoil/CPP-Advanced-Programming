/*
Student Number: 7547821
Student Name: Gia Bach Nhu
Lab 3
Task 2
*/
#include<iostream>
#include<string>
using namespace std;

class Cat
{
private:
   string name;
   string breed;
   int age;
   static constexpr double licenseFee = 10;
public:
   void setCatData(string, string, int);
   void showCat();
   Cat();
   ~Cat();
   Cat(const Cat& test);

};
//const double Cat::licenseFee = 10;
//constructor
Cat::Cat()
{
    cout << "Just a constructor" << endl;
    cout << this << endl;

}

//destructor
Cat::~Cat()
{
    cout << " " << endl;
    cout << "Just a destructor" << endl;
    cout << this << endl;
}

//copy constructor
Cat::Cat(const Cat& test)
{
    name = test.name;
    breed = test.breed;
    age = test.age;
    cout <<this<< endl;
}


void Cat::setCatData(string catName, string catBreed, int catAge)
{
   name = catName;
   breed = catBreed;
   age = catAge;
}

void Cat::showCat()
{
    cout  <<" " << endl;
  cout << "Cat: " << name << " is a " << breed << endl;
  cout << "The cat's age is " << age << endl;
  cout << "License fee: $" << licenseFee << endl;
cout << this << endl;

}

int main()
{
     Cat myCat;
     myCat.setCatData("Tigger", "Fluffy unit", 3);

     Cat mytestCat = myCat;
     myCat.showCat();
     mytestCat.showCat();

}

