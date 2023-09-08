/*
Student Number: 7547821
Student Name: Gia Bach Nhu
Lab 3
Task 4
*/
#include "Library.h"


Money::Money(string country, string units, double rate)
    : countryName(country), dollarUnits(units), exchangeRate(rate) {}

City::City(string name, string country, double lat, double lon)
    : cityName(name), countryName(country), latitude(lat), longitude(lon) {}

bool friendFunction(const Money& money, const City& city)
{
    return money.countryName == city.countryName;
}

