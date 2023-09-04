driver.cpp
First I include C++ standard library and then defines the main function, which is the starting point of the program.
Inside the main function, I initialize arrays of Worker and Task objects.
It calls the loadWorkers and loadTasks functions to load data from external files into these arrays.
Finally, it calls the crowdsourcingSystem function to process and write the results to an output file.

header.h
First I define the struct Worker and Task. 
After that i declare various functions such as loadWorkers, loadTasks, performanceScore, successfulCondition, crowdsourcingSystem

header.cpp
First I include standard C++ headers (<iostream>, <fstream>, <sstream>, <random>)
Then I define the following functions:
- int loadWorkers(const string& filename, Worker workers[]): Loads worker data from a file into an array of Worker objects.
- int loadTasks(const string& filename, Task tasks[]): Loads task data from a file into an array of Task objects.
- double performanceScore(int mean, int sd): Generates a performance score based on a normal distribution.
- bool successfulCondition(double averagePerformance): Checks if a worker is successful based on average performance.
- void crowdsourcingSystem(const Worker workers[], int numWorkers, Task tasks[], int numTasks): Implements the crowdsourcing system, processing tasks and workers' performance.