/*
Student Name: Gia Bach Nhu
Student Number: 7547821
Lab 2
Task 3
*/

#include <iostream>

using namespace std;

struct Cat
{
    //Data fields (at least) for name, breed and age.
    string name;
    string breed;
    int age;

    const static double insuranceFee;


    void setCat(string catName, string catBreed, int catAge)
    {
        name = catName;
        breed = catBreed;
        age = catAge;
    }

    void showCat()
    {
        cout << "Cat: " << name << " is a " << breed << endl;
        cout << "Its age is " << age << endl;
        cout << "Insurance fee: $" << insuranceFee << endl;
    }

    //For a cat, its owning cost, for simplicity, is calculated as age*1.5 + insurance.
    void calculatePrice()
    {
        double owningCost = age * 1.5 + insuranceFee;
        cout << "Owning cost is: $" << owningCost << endl;
    }
};

// A constant static field for the insurance, which is AUD $99.9.
const double Cat::insuranceFee = 99.9;

int main()
{
    Cat myCat;
    myCat.setCat("Tiger", "British Shorthair", 1);
    myCat.showCat();
    myCat.calculatePrice();
}
