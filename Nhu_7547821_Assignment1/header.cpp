/*
Student Name: Gia Bach Nhu
Student Number: 7547821
Assignment 1
*/
#include "header.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <random>

using namespace std;

//load worker data from a file
int loadWorkers(const string& filename, Worker workers[])
{
    ifstream workersFile(filename);
    if (!workersFile)
    {
        cerr << "Error opening Workers.txt" << endl;
        return 0;
    }

    int numWorkers = 0;
    string workerLine;
    while (getline(workersFile, workerLine) && numWorkers < 20)
    {
        istringstream iss(workerLine);
        char comma;
        int id, variability, ability;
        string name;

        // parse worker information from each line
        iss >> id >> comma;
        getline(iss, name, ','); // read the name using getline
        iss >> variability >> comma >> ability;

        // store worker data
        workers[numWorkers].id = id;
        workers[numWorkers].name = name;
        workers[numWorkers].variability = variability;
        workers[numWorkers].ability = ability;

        ++numWorkers;
    }

    workersFile.close();
    return numWorkers;
}

// load task data from a file
int loadTasks(const string& filename, Task tasks[])
{
    ifstream tasksFile(filename);
    if (!tasksFile)
    {
        cerr << "Error opening " << filename << endl;
        return 0;
    }

    int numTasks = 0;
    string taskLine;
    while (getline(tasksFile, taskLine) && numTasks < 20)
    {
        istringstream iss(taskLine);
        char comma;
        iss >> tasks[numTasks].id >> comma;

        // parse the description field
        getline(iss, tasks[numTasks].description, ',');

        iss >> tasks[numTasks].uncertainty >> comma >> tasks[numTasks].difficulty;

        // find the position of "workers:" in the task line
        size_t workersPos = taskLine.find("workers:");
        if (workersPos != string::npos)
        {
            // extract and ignore the "workers:" part
            string workerIDsStr = taskLine.substr(workersPos + 8);
            istringstream workerIDsStream(workerIDsStr);

            int workerID;
            int i = 0;
            while (workerIDsStream >> workerID && i < 20)
            {
                tasks[numTasks].workerIDs[i] = workerID;
                ++i;
                if (workerIDsStream.peek() == ',')
                {
                    workerIDsStream.ignore(); // ignore the comma
                }
            }
            tasks[numTasks].workerIDs[i] = -1;
        }

        ++numTasks;
    }

    tasksFile.close();
    return numTasks;
}

// generate a performance score from a normal distribution
double performanceScore(int mean, int sd)
{
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<> dist(mean, sd);
    return dist(gen);
}

// check if a worker is successful based on average performance
bool successfulCondition(double averagePerformance)
{
    return averagePerformance > 50.0;
}

// crowdsourcing stystem
void crowdsourcingSystem(const Worker workers[], int numWorkers, Task tasks[], int numTasks)
{
    ofstream outputFile("Output.txt");

    for (int i = 0; i < numTasks; ++i)
    {
        outputFile << "===================================================================" << endl;
        outputFile << "processing taskId: " << tasks[i].id << endl;
        outputFile << "description      : " << tasks[i].description << endl;
        outputFile << "uncertainty      : " << tasks[i].uncertainty << endl;
        outputFile << "difficulty       : " << tasks[i].difficulty << endl;
        outputFile << "workers          : ";

        // print worker IDs without the last comma
        for (int k = 0; k < 20 && tasks[i].workerIDs[k] >= 0; ++k)
        {
            outputFile << tasks[i].workerIDs[k];
            if (tasks[i].workerIDs[k + 1] >= 0)
            {
                outputFile << ",";
            }
        }
        outputFile << endl;

        for (int k = 0; k < 20 && tasks[i].workerIDs[k] >= 0; ++k)
        {
            int workerID = tasks[i].workerIDs[k];
            outputFile << " " << endl;
            outputFile << "-------------------------------------------------------------------" << endl;
            outputFile << "Trial: workers   : " << workerID << endl;
            outputFile << "-------------------------------------------------------------------" << endl;
            outputFile << " " << endl;
            double averagePerformance = 0.0;
            for (int attempt = 0; attempt < 5; ++attempt)
            {
                double trialPerformance = performanceScore(workers[workerID].ability - tasks[i].difficulty, tasks[i].uncertainty + workers[workerID].variability);
                averagePerformance += trialPerformance;
            }

            double finalAvgPerformance = averagePerformance / 5.0;
            outputFile << "The average performance is " << finalAvgPerformance << endl;

            if (successfulCondition(finalAvgPerformance))
            {
                outputFile << "Assignment of Task " << tasks[i].id << " to worker " << workerID << " succeeds" << endl;
            }
            else
            {
                outputFile << "Assignment of Task " << tasks[i].id << " to worker " << workerID << " fails" << endl;
            }
            outputFile << " " << endl;
        }
    }

    outputFile.close();
}
