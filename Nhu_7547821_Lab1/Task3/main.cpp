/*
Student Name: Gia Bach Nhu
Student Number: 7547821
Lab 1
Task 3
*/

#include <iostream>
#include "myheader.h"

using namespace std;
int main()
{
    //Declare variables
    int width, height, depth, pricesum;
    char m;

    m = getMaterialType();
    functionOne(width, height, depth);
    pricesum = functionTwo(width, height, depth, m);

    cout<<"The total price is "<< pricesum << endl;

    return 0;
}
