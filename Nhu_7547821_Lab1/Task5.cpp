/*
Student Name: Gia Bach Nhu
Student Number: 7547821
Lab 1
Task 5
*/

#include <iostream>
using namespace std;


int size=5;
int arr[5];

//Function swap 2 integer using pointer
void swap(int *ptr1, int *ptr2){
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main()
{
    //user input
    cout<<"Enter array elements: "<< endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    // call the swap function
    swap(&arr[3], &arr[4]);

    // display the final array
    cout << "" << endl;
    cout << "Array after swapping:" << endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
        cout<<endl;
    }
}
