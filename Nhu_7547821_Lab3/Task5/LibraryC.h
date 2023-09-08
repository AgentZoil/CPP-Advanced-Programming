/*
Student Number: 7547821
Student Name: Gia Bach Nhu
Lab 3
Task 5
*/
#ifndef LIBRARYC_H_INCLUDED
#define LIBRARYC_H_INCLUDED

#include <string>

using namespace std;

class Money
{
    string countryName;
    double dollarUnits;
    double exchangeRate;

public:
    Money(string country, double units, double rate);
    void display() const;
    friend bool friendFunction(const Money& money, const class City& city);
};

class City
{
    string cityName;
    double latitude;
    double longitude;
public:
    // money object inside City class
    Money cityMoney;
    City(string name, string country, double lat, double lon, double units, double rate);
    void display() const;
    friend bool friendFunction(const Money& money, const City& city);
};

#endif // LIBRARYC_H_INCLUDED
