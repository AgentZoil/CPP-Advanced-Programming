/*
Student Name: Gia Bach Nhu
Student Number: 7547821
Assignment 1
*/
#include <iostream>
#include "header.h"

int main()
{
    Worker workers[20];
    Task tasks[20];

    int numWorkers = loadWorkers("Workers.txt", workers);
    int numTasks = loadTasks("Tasks.txt", tasks);

    crowdsourcingSystem(workers, numWorkers, tasks, numTasks);

    return 0;
}
