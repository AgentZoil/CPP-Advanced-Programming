#ifndef ELECTORATE_H
#define ELECTORATE_H
#include <vector>
#include <string>

class Electorate
{
    public:
    	std::string eName;
        int population,stanceLow,stanceHigh;
        std::vector<Candidate> eCandidates;
        Electorate(std::string eName, int low, int high, int pop);
        Electorate();

        void setName(std::string eName);
        std::string getName();
        void setHighStance(int stanceHigh);
        int getHighStance();
        void setLowStance(int stanceLow);
        int getLowStance();
        void setPopulation(int population);
        int getPopulation();
        void pushCandidate(Candidate newCan);
        Candidate getCandidate(int pos);
};

#endif
