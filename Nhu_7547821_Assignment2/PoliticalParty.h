#ifndef POLITICALPARTY_H
#define POLITICALPARTY_H

#include <vector>

class PoliticalParty
{
	public:
		std::string pName;
		int campaignManager;
		int stance, numVotes, electoratesWon;
		Candidate leader;
		std::vector<Candidate> candidates;
		PoliticalParty();
		int getStance();
		void setVotes(int votes);
		void addVotes(int votes);
		int getVotes();
		void addEWins();
		int getEWins();
		void pushCandidate(Candidate newCan);
		Candidate getCandidate(int pos);
		PoliticalParty(std::string pName, int stance, int campaignManagerSkill);


};

#endif
