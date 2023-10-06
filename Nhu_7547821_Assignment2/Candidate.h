#ifndef CANDIDATE_H
#define CANDIDATE_H

class Candidate : public Person
{
    public:
    	int popularity;
        void setName(std::string n);
        std::string getName();
        void setPopularity(int p);
        int getPopularity();
        Candidate(std::string name, int stance, int popularity);
        Candidate();
};

#endif
