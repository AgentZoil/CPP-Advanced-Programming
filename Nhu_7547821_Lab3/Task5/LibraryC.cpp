/*
Student Number: 7547821
Student Name: Gia Bach Nhu
Lab 3
Task 5
*/
#include "LibraryC.h"
#include <iostream>

Money::Money(string country, double units, double rate)
    : countryName(country), dollarUnits(units), exchangeRate(rate) {}

void Money::display() const
{
    cout << "Country: " << countryName << " \nUnits: " << dollarUnits << " \nExchange Rate: " << exchangeRate << endl;
}

City::City(string name, string country, double lat, double lon, double units, double rate)
    : cityName(name), cityMoney(country, units, rate), latitude(lat), longitude(lon) {}

void City::display() const
{
    cout << "City: " << cityName << endl;
    // display money information inside city
    cityMoney.display();
}

bool friendFunction(const Money& money, const City& city)
{
    return money.countryName == city.cityMoney.countryName;
}
