/*
Student Name: Gia Bach Nhu
Student Number: 7547821
Lab 2
Task 1
*/
#include<iostream>

using namespace std;

void countDown(int highest, int lowest);

// Prints integers from highest to lowest, inclusive.



int main()
{
   int high, low, temp;

   cout << "Enter an integer ";
   cin >> high;

   cout << "Enter another integer ";
   cin >> low;

   if (high < low)
   {
       temp = low;
       high = low;
       low = temp;
   }

   countDown(high, low);
   return 0;
}

void countDown(int highest, int lowest)
{
    for (int x = highest; x >= lowest; x--)
     cout << x << " " << endl;
}
