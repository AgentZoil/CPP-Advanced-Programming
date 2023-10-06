#include "APE.h"
#include "Person.h"
#include "Candidate.h"
#include "PoliticalParty.h"

// Constructor
Candidate::Candidate(std::string name, int stance, int popularity) :
    Person(name, stance), popularity(popularity) {}

// Default constructor
Candidate::Candidate() {}

// Set the popularity of a candidate
void Candidate::setPopularity(int p)
{
    popularity += p; // Increase the popularity by the specified amount
}

// Get the popularity of a candidate
int Candidate::getPopularity()
{
    return popularity;
}


