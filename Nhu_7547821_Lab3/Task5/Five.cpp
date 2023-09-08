/*
Student Number: 7547821
Student Name: Gia Bach Nhu
Lab 3
Task 5
*/
#include "LibraryC.h"
#include <iostream>

using namespace std;

int main() {
    City city_1("Wollongong", "Australia", 12.312, 7583.123, 4.27, 1.0);
    City city_2("Hanoi", "Vietnam", 23.650, 783.13, 7.2323, 15.75);


    city_1.display();

    cout << " " << endl;

    city_2.display();
    cout << " " << endl;

    if (friendFunction(city_1.cityMoney, city_2))
    {
        cout << " a given city_1 and a given city_2 are associated with the same country." << endl;
    }
    else
    {
        cout << " a given city_1 and a given city_2 are not associated with the same country." << endl;
    }

    return 0;
}

