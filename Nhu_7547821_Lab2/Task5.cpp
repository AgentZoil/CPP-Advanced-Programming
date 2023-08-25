/*
Student Name: Gia Bach Nhu
Student Number: 7547821
Lab 2
Task 5
*/
#include <iostream>

using namespace std;

class MyException : public exception
{
public:
    const char* what() const throw()
    {
        return "Attempted to divide by zero! \n";
    }
};

int main()
{
    int x, y;
    double result;

    cout << "Enter the numbers of x and y: " << endl;
    cin >> x >> y;

    // Transform the result data type
    result = static_cast<double>(x) / y;

    //Check if y = 0 to throw exception
    if (y == 0)
    {
        throw MyException();
    }

    cout << "x/y = " << result << endl;

    return 0;
}
