/*
Student Name: Gia Bach Nhu
Student Number: 7547821
Lab 1
Task 4
*/

#include <iostream>
using namespace std;

int main()
{
    //Declare variables
    double r, s, v;

    //User Input
    cout << "Input the radius: " ;
    cin >> r;

    //Calculation
    s = 3.14 * r * r;
    v = 2 * 3.14 * r;

    //Print out results
    cout << "The area of this circle is: " ;
    cout << s << endl;
    cout << "The circumference of this circle is: " ;
    cout << v << endl;
    return 0;
}

