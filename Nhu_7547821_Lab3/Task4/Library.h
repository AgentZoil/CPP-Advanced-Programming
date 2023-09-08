/*
Student Number: 7547821
Student Name: Gia Bach Nhu
Lab 3
Task 4
*/
#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#include <string>

using namespace std;

class City;

class Money
{
    string countryName;
    string dollarUnits;
    double exchangeRate;
public:
    Money(string country, string units, double rate);
    friend bool friendFunction(const Money& money, const City& city);
};

class City
{
    string cityName;
    string countryName;
    double latitude;
    double longitude;
public:
    City(string name, string country, double lat, double lon);
    friend bool friendFunction(const Money& money, const City& city);
};

#endif // LIBRARY_H_INCLUDED
