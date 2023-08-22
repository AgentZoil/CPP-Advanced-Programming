/*
Student Name: Gia Bach Nhu
Student Number: 7547821
Lab 1
Task 2
*/

#include <iostream>
#include <limits>

using namespace std;
int main()
{
  double m, n;
  double output = 1;
  bool valid = false;

  do
    {
        cout << "Enter m value: ";
        cin >> m;
        cout << "Enter n value: ";
        cin >> n;
        //Checking the user input thats only accept integer and n > 1
        if (cin.good() && n > 1)
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

    cout << "The output m mutiplied by the values 1 to n: " ;
    for (int i=1; i <= n; i++)
    {
        output = i * m;

    cout << output << ", " ;
    }
  return 0;
}


