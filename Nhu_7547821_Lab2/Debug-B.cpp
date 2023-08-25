/*
Student Name: Gia Bach Nhu
Student Number: 7547821
Lab 2
Task 1
*/
#include <iostream>
#include <cmath>

using namespace std;


int main(int argc, char* argv[])
{

	if (argc != 3 )
	{
		cout << "Enter two integers after the program name please!" << endl;
	}

    int a = atoi(argv[1]);
	int b = atoi(argv[2]);


	// c is the Lower input of (a, b)
    int c = min(a,b);
    double e = 2.718;


	cout << "log10(10) should be 1 : " << log10(10) << endl;
	cout << "log(e) should be 1    : " << log(e) << endl;
	cout << "log of lower input is : " << log(c) << endl;


	return 0;
}


