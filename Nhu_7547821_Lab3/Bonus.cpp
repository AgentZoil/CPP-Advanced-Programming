/*
Student Number: 7547821
Student Name: Gia Bach Nhu
Lab 3
Task 3
*/
#include <iostream>
using namespace std;

class Staff
{
    int staffNum;
    string firstName;
    string lastName;
    double baseSalary;
    int salesMade;
    char staffClass;
    double bonus;

    static const double bonusRates[][3];  // static array for bonus rates

    int getStaffClass();  // determine the staff class

public:
    static void displayTable()
    {
    cout << "-------------------------------------------" << endl;
    cout << "Sales       Class A     Class B     Class C" << endl;
    cout << "0 - 20       0.03        0.02        0.005" << endl;
    cout << "21 - 50      0.05        0.035       0.015" << endl;
    cout << "51+          0.075       0.055       0.04" << endl;
    cout << "-------------------------------------------" << endl;
    };

    void setFields(int staffn, string last, string first, double base, int sales, char sclass);
    void computeBonus();
    void display();
};

const double Staff::bonusRates[][3] = {{0.03, 0.05, 0.075},  {0.02, 0.035, 0.055}, {0.005, 0.015, 0.04}};

void Staff::setFields(int staffn, string last, string first, double base, int sales, char sclass) {
    staffNum = staffn;
    firstName = first;
    lastName = last;
    baseSalary = base;
    salesMade = sales;
    staffClass = sclass;
    computeBonus();
}

void Staff::computeBonus() {
    int grade = staffClass - 'A'; // convert staff class to an index (0 for A, 1 for B, 2 for C)
    double rate = bonusRates[grade][getStaffClass()];  // get the appropriate bonus rate
    // calculate bonus
    bonus = baseSalary * rate * salesMade ;
}

int Staff::getStaffClass() {
    if (salesMade >= 0 && salesMade <= 20) {
        return 0;
    } else if (salesMade <= 50) {
        return 1;
    } else {
        return 2;
    }
}

void Staff::display() {
    cout << "Name: " << firstName << " " << lastName << endl;
    cout << "Grade: " << staffClass << "     Staff Number # " << staffNum << endl;
    cout << "Salary: $" << baseSalary << "     Sales Made: " << salesMade << endl;
    cout << "Bonus: $" << bonus << endl;
    cout << endl;
}

int main() {
    Staff::displayTable();
    Staff staff_1, staff_2;

    staff_1.setFields(1001, "the Tank Engine", "Thomas", 10000.0, 21, 'A');
    staff_2.setFields(1002, "the Builder", "Bob", 5000.0, 56, 'C');

    staff_1.display();
    staff_2.display();

    return 0;
}
