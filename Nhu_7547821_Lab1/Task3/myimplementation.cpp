/*
Student Name: Gia Bach Nhu
Student Number: 7547821
Lab 1
Task 3
*/

#include <iostream>
#include "myheader.h"
#include <limits>

using namespace std;

//This function is to get the user input to choose between w,c or b
char getMaterialType()
{
    char m;

    cout << "Enter the material type (w for wooden, c for concrete, b for brick): ";
    cin >> m;

    //if its not w,b,c then wrong input
    while (m != 'w' && m != 'c' && m != 'b')
    {
        cout << "Invalid input. Please enter w, c, or b: ";
        cin >> m;
    }

    return m;
}

//This function is to get the user input for width, height and depth
void functionOne(int &width, int &height, int &depth)
{
    bool valid = false;
	 do
    {
        cout << "Enter the width : ";
	    cin >> width;

	    cout << "Enter the height : ";
	    cin >> height;

	    cout << "Enter the depth : ";
	    cin >> depth;
        //Checking the user input thats only accept integer and n > 1
        if (cin.good() && width >= 1 && height >= 1 && depth >= 1)
        {
            //If everything went through, we'll get out of the loop and return the value
            valid = true;
        }
        else
        {
            //If something went wrong, we reset the buffer's state to good
            cin.clear();
            //and empty it
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            cout << "" << endl;
            cout << "Invalid input, please re-enter!" << endl;
        }
    } while (!valid);
}

//This function is to calculate the price
int functionTwo(int width, int height, int depth, char m)
{
    int mCost = 0;

    if (m == 'w')
        mCost = 75;  // The cost of wooden
    else if (m == 'c')
        mCost = 150; // The cost of concrete
    else if (m == 'b')
        mCost = 175;  // The cost of brick

	return mCost * (width * height * depth) + 200;
}
