/*
Student Name: Gia Bach Nhu
Student Number: 7547821
Assignment 1
*/
#ifndef HEADER_H
#define HEADER_H

#include <string>

using namespace std;

//Use structs to store information for tasks and workers
struct Worker
{
    int id;
    string name;
    int variability;
    int ability;
};

struct Task
{
    int id;
    string description;
    int uncertainty;
    int difficulty;
    int workerIDs[20]; // asuming no more than 20 workers per task
};

int loadWorkers(const string& filename, Worker workers[]);
int loadTasks(const string& filename, Task tasks[]);
double performanceScore(int mean, int stdDev);
bool successfulCondition(double averagePerformance);
void crowdsourcingSystem(const Worker workers[], int numWorkers, Task tasks[], int numTasks);

#endif // HEADER_H
