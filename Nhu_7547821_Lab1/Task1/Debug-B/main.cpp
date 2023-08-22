/*
Student Name: Gia Bach Nhu
Student Number: 7547821
Lab 1
Task 1.2
*/

#include <iostream>
#include "mylibrary.h"

using namespace std;
int main()
{
    // These comments reflect what the program should do.
    // functionOne should take 3 integers from the user.
    // functionTwo should calculate the sum of those 3 integers.

    int one, two, three, sum;
    functionOne(one, two, three);
    sum = functionTwo(one, two, three);

    cout<<"The sum of "<< one << "," << two << "," << three <<" is "<< sum << endl;

    return 0;
}
