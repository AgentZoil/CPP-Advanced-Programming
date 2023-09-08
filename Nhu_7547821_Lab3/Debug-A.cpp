/*
Student Number: 7547821
Student Name: Gia Bach Nhu
Lab 3
Task 1.1
*/
#include <iostream>
#include <string>
using namespace std;

class Worker
{
public:
    double salary;
   int idNum;
   string lastName;
   string firstName;
   double celery;
   void setIdNum(int);
   void setLastName(string);
   void setFirstName(string);
   void setSalary(double);
   void displayWorker();
};

void Worker::setIdNum(int id)
{
   const int LOWID = 0;
   const int HIGHID = 999;
   if(id < LOWID && id > HIGHID)
     idNum = LOWID;
   else
     idNum = id;
}

void Worker::setLastName(string last)
{
   lastName = last;
}
void Worker::setFirstName(string first)
{
   firstName = first;
}
void Worker::setSalary(double payRate)
{
   const double LOWPAY = 5.75;
   const double HIGHPAY = 99.99;

   if (payRate < LOWPAY || payRate > HIGHPAY)
     salary = LOWPAY;
   else
     salary = payRate;
 }

void Worker::displayWorker()
{
   cout<<"ID # "<<idNum<< "\n"<<"Name: "<<firstName<<" "<<lastName<<"\nSalary: $"<<salary<<endl;
}

int main()
{
     Worker aWorker;
     aWorker.setIdNum(111);
     aWorker.setLastName("Anteater");
     aWorker.setFirstName("Alice");
     aWorker.setSalary(23.45);
     aWorker.displayWorker();
}
