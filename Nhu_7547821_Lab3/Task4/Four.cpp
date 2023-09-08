/*
Student Number: 7547821
Student Name: Gia Bach Nhu
Lab 3
Task 4
*/
#include "Library.h"
#include <iostream>

using namespace std;

int main() {
    Money money_1("Australia", "AUD", 1.0);
    Money money_2("Vietnam", "VND", 15.75);

    City city_1("Wollongong", "Australia", 12.312, 7583.123);
    City city_2("Sydney", "Australia", 23.650, 783.13);

    if (friendFunction(money_1, city_1))
    {
        cout << " a given city_1 and a given money_1 are associated with the same country." << endl;
    }
    else
    {
        cout << " a given city_1 and a given money_1 are not associated with the same country." << endl;
    }

    if (friendFunction(money_2, city_2))
    {
        cout << " a given city_2 and a given money_2 are associated with the same country." << endl;
    }
    else
    {
        cout << " a given city_2 and a given money_2 are not associated with the same country." << endl;
    }

    return 0;
}
