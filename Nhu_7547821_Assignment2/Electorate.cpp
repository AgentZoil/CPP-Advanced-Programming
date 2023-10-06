#include "Person.h"
#include "Candidate.h"
#include "Electorate.h"

// Default constructor
Electorate::Electorate() {}

// Constructor
Electorate::Electorate(std::string eName, int low, int high, int pop) :
    eName(eName), stanceLow(low), stanceHigh(high), population(pop) {}

// Set the name of the electorate
void Electorate::setName(std::string eName)
{
    this->eName = eName;
}

// Get the name of the electorate
std::string Electorate::getName()
{
    return eName;
}

// Set the high stance of the electorate
void Electorate::setHighStance(int stanceHigh)
{
    this->stanceHigh = stanceHigh;
}

// Get the high stance of the electorate
int Electorate::getHighStance()
{
    return stanceHigh;
}

// Set the low stance of the electorate
void Electorate::setLowStance(int stanceLow)
{
    this->stanceLow = stanceLow;
}

// Get the low stance of the electorate
int Electorate::getLowStance()
{
    return stanceLow;
}

// Set the population of the electorate
void Electorate::setPopulation(int population)
{
    this->population += population;
}

// Get the population of the electorate
int Electorate::getPopulation()
{
    return population;
}

// Add a candidate to the list of candidates in the electorate
void Electorate::pushCandidate(Candidate newCan)
{
    eCandidates.push_back(newCan);
}

// Get a candidate at a specific index from the list of candidates in the electorate
Candidate Electorate::getCandidate(int index)
{
    return eCandidates[index];
}
