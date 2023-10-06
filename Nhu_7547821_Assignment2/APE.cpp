#include "APE.h"
#include "Person.h"
#include "Candidate.h"
#include "PoliticalParty.h"
#include "Electorate.h"
#include "Event.h"

// Lists of electorates, parties, events and issues.
std::vector<Electorate> electorates;
std::vector<PoliticalParty> parties;
std::vector<Event> events;
std::vector<Event> issues;

// Names for candidates and leaders
std::vector<std::string> names = {
    "Optimus Prime", "Megatron", "Bumblebee", "Starscream", "Grimlock", "Soundwave", "Arcee", "Shockwave",
    "Ironhide", "Rumble", "Jazz", "Scorponok", "Sideswipe", "Thundercracker", "Rodimus Prime", "Devastator",
    "Hot Rod", "Cyclonus", "Omega Supreme", "Blitzwing", "Sludge", "Ravage", "Hound", "Frenzy",
    "Cliffjumper", "Blackout", "Slingshot", "Bonecrusher", "Mirage", "Ramjet", "Prowl", "Ratbat",
    "Trailbreaker", "Thrust", "Smokescreen", "Laserbeak", "Beachcomber", "Divebomb", "Tracks", "Rampage",
    "Bluestreak", "Sinnertwin"
};
// Cybertron city names
std::vector<std::string> electorateNames = {
    "Iacon", "Kaon", "Polyhex", "Vos", "Tarn", "Praxus", "Crystal City", "Helex",
    "Altihex", "Kalis", "Garrus-9"
};

// Method to create parties and establish their candidates and leaders
void createParties(int n)
{
	std::cout << "         [ POLITICAL PARTY ] "<< std::endl;
	std::cout << "--------------------------------------\n" << std::endl;

    // Create three political parties
    PoliticalParty party1("Autobot", 3, randomUniform(1, 10));
    parties.push_back(party1);

    PoliticalParty party2("Decepticon", 4, randomUniform(1, 10));
    parties.push_back(party2);

    PoliticalParty party3("Terrorcon", 5, randomUniform(1, 10));
    parties.push_back(party3);

    // Iterate through each party
    int rand = 0;
    for (int i = 0; i < 3; ++i)
    {
        // Iterate and add 'n' candidates to each party
        for (int j = 0; j < n; ++j)
        {
            // Create a candidate
            rand = randomUniform(0, names.size() - 1);
            std::string tempName = names[rand];
            Candidate newCan(tempName, 1, 1);
            names.erase(names.begin()+rand);
            // Add the new candidate to the party
            parties[i].pushCandidate(newCan);
        }
    }

    // Assign leaders to each party
    rand = randomUniform(0, names.size() - 1);
    Candidate leader1(names[rand], 1, 1);

    rand = randomUniform(0, names.size() - 1);
    Candidate leader2(names[rand], 1, 1);

    rand = randomUniform(0, names.size() - 1);
    Candidate leader3(names[rand], 1, 1);

    // Set a leader for each party
    parties[0].leader = leader1;
    parties[1].leader = leader2;
    parties[2].leader = leader3;

    // Iterate through the list of parties
    for (int i = 0; i < parties.size(); ++i)
    {
        // Print out information for each party (Name, Leader, Candidates)
        std::cout << "Party: " << parties[i].pName << std::endl;
        std::cout << "Leader: " + parties[i].leader.name << std::endl;
        // Iterate through each candidate
        std::cout << "The candidates:" << std::endl;
        for (int j = 0; j < parties[i].candidates.size(); ++j)
        {
            // Print the name of each candidate
            std::cout << "   - " << parties[i].candidates[j].name << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Generate electorates
void createElectorates(int n)
{
	std::cout << "            [ ELECTORATES ] "<< std::endl;
	std::cout << "--------------------------------------\n" << std::endl;

	// Looping through and creating 'n' amount of electorates
	for (int i = 0; i < n; ++i)
	{
		// Establishing a random number for each electorate's stance
		int stanceHigh, stanceLow, temp;
		stanceLow = randomUniform(1,8);
		stanceHigh = randomUniform(1,8);

		// If the value for stanceLow is greater than the value of stanceHigh, swap
		if(stanceLow > stanceHigh)
		{
			temp = stanceLow;
			stanceLow = stanceHigh;
			stanceHigh = temp;
		}

		// Establishing a new Electorate with a random population
		Electorate newElec(electorateNames[i], stanceLow, stanceHigh, randomUniform(3000, 10000));


		// Printing out the new Electorate's information
		std::cout << newElec.getName() << std::endl << "Stance: " <<  newElec.getLowStance() << "-" << newElec.getHighStance() << std::endl << "Population: " << newElec.getPopulation() << std::endl;
		std::cout << "Representatives:" << std::endl;

		// Adding candidates to represent their party for each Electorate
		for (int j = 0; j < parties.size(); ++j)
		{
			Candidate can = parties[j].getCandidate(i);
			newElec.pushCandidate(can);
			std::cout << "   - " << can.name << " of The " << parties[j].pName << std::endl;
		}
		// Adding the new Electorate to the list of Electorates
		electorates.push_back(newElec);
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// Method to establish events
void createEvents()
{
	// Creating events
	Event event1("Debate", " is having a debate between candidates.", 100);

    Event cybertronCandidateEvent1("Candidate Scandal", " is involved in a scandal, damaging their popularity.", -300);
    Event cybertronCandidateEvent2("Candidate Rally", " hosts a massive rally, gaining support from their loyal followers.", 250);

    Event cybertronLeaderEvent1("Leadership Crisis", " have rumors of leadership instability circulate, affecting the confidence in Cybertron's leaders.", -200);
    Event cybertronLeaderEvent2("Peace Treaty", "have a historic peace treaty, boosting their approval ratings.", 300);

	Event cybertronIssueEvent1("Energon Shortage", "The Energon reserves are critically low, causing energy scarcity across Cybertron.", -200);
    Event cybertronIssueEvent2("Tech Advancement", "A breakthrough in technology leads to increased efficiency and energy production on Cybertron.", 300);


	// Adding the new events to the events list
	events.push_back(event1);
	events.push_back(cybertronCandidateEvent1);
	events.push_back(cybertronCandidateEvent2);
	events.push_back(cybertronLeaderEvent1);
	events.push_back(cybertronLeaderEvent2);
	events.push_back(cybertronIssueEvent1);
	events.push_back(cybertronIssueEvent2);
}

// Method to establish issues
void createIssues()
{
	// Creating issues
	Event cybertronIssue1("Energon Shortage", "There has been a severe depletion of Energon reserves, causing energy shortages across Cybertron.", 300);
    Event cybertronIssue2("Interstellar Conflict", "Cybertronian factions are engaged in intense interstellar conflicts. It is up to the leaders to seek peaceful solutions and protect our homeworld.", 300);
    Event cybertronIssue3("Cyber Intrusions", "Malevolent entities from other worlds have launched cyber-attacks on our vital systems, resulting in disruptions in our networks and data. We must enhance our cyber defenses.", 300);
    Event cybertronIssue4("Energy Crisis", "Cybertron's energy resources are dwindling rapidly, leading to a critical energy crisis. It is crucial for leaders to find sustainable energy solutions.", 300);
    Event cybertronIssue5("Judicial Debates", "The debate rages on about the appropriate punishment for heinous acts. Should we retain our current system of justice or explore alternative methods for dealing with grave crimes?", 300);

	// Adding the new issues to the issues list
	issues.push_back(cybertronIssue1);
	issues.push_back(cybertronIssue2);
	issues.push_back(cybertronIssue3);
	issues.push_back(cybertronIssue4);
	issues.push_back(cybertronIssue5);

	// Print out each Issue's information
	std::cout << "            [ FIVE ISSUES ] "<< std::endl;
	std::cout << "--------------------------------------\n" << std::endl;
	for (Event i : issues){
		std::cout <<"- "<< i.getName() <<":"<< std::endl << i.getDescription() << std::endl << std::endl;
	}
	std::cout << std::endl;
}

// Method to run the Campaign
void runCampaign(int n, int m)
{
	std::cout << "            [ CAMPAIGN ] "<< std::endl;
	std::cout << "--------------------------------------\n" << std::endl;

	// Looping through each day
	for (int i = m; i > 0; --i)
	{
		if (i != 1){
			std::cout << " " << i << " days left until the election!" << std::endl;
		}
		else{
			std::cout << " " << i << " day left until the election!" << std::endl;
		}

		// Picking a random event
		int eventNum = randomUniform(1,20);

		Electorate currentElec;
		PoliticalParty currentParty;
		Candidate currentLeader;
		Candidate currentCan;
		Event currentEvent;

		// 50% Chance of an event occuring
		if(eventNum < 9)
		{
			std::cout << "No event occur today" << std::endl;
			std::cout << std::endl;
		}

		// Different outcomes for each event
		else if(eventNum > 8 && eventNum < 15)
		{
			currentEvent = events[0];

			// Choosing a random Electorate
			currentElec = electorates[randomUniform(0,electorates.size()-1)];
			std::cout << currentElec.getName() << currentEvent.getDescription() << std::endl;

			// Choosing a random Candidate
			currentCan = currentElec.getCandidate(randomUniform(0,2));
			std::cout << currentCan.name << " has won the debate. Their popularity has increased." << std::endl;
			// Increasing the Candidate's popularity
			currentCan.setPopularity(currentEvent.getEffect());

			std::cout << std::endl;
		}
		else if(eventNum == 15)
		{
			currentEvent = events[1];

			// Choosing a random Electorate
			currentElec = electorates[randomUniform(0,electorates.size()-1)];

			// Choosing a random Candidate
			currentCan = currentElec.getCandidate(randomUniform(0,2));
			std::cout << currentCan.name << " from the " << currentElec.getName() << " electorate" << currentEvent.getDescription() << std::endl;
			std::cout << currentCan.name << " popularity has decreased." << std::endl;

			// Decreasing the Candidate's popularity
			currentCan.setPopularity(currentEvent.getEffect());

			std::cout << std::endl;
		}
		else if(eventNum == 16)
		{
			currentEvent = events[2];

			// Choosing a random Electorate
			currentElec = electorates[randomUniform(0,electorates.size()-1)];

			// Choosing a random Candidate
			currentCan = currentElec.getCandidate(randomUniform(0,2));
			std::cout << currentCan.name << " from the " << currentElec.getName() << " electorate" << currentEvent.getDescription() << std::endl;
			std::cout << currentCan.name << " popularity has increased." << std::endl;

			// Increasing the Candidate's popularity
			currentCan.setPopularity(currentEvent.getEffect());

			std::cout << std::endl;
		}
		else if(eventNum == 17)
		{
			currentEvent = events[3];

			// Choosing a random Electorate
			currentElec = electorates[randomUniform(0,electorates.size()-1)];

			// Choosing a random Candidate
			currentCan = currentElec.getCandidate(randomUniform(0,2));
			std::cout << currentCan.name << " from the " << currentElec.getName() << " electorate" << currentEvent.getDescription() << std::endl;
			std::cout << currentCan.name << " popularity has decreased." << std::endl;

			// Decreasing the Candidate's popularity
			currentCan.setPopularity(currentEvent.getEffect());

			std::cout << std::endl;
		}
		else if(eventNum == 18)
		{
			currentEvent = events[4];

			// Choosing a random Electorate
			currentElec = electorates[randomUniform(0,electorates.size()-1)];

			// Choosing a random Candidate
			currentCan = currentElec.getCandidate(randomUniform(0,2));
			std::cout << currentCan.name << " from the " << currentElec.getName() << " electorate" << currentEvent.getDescription() << std::endl;
			std::cout << currentCan.name << " popularity has increased." << std::endl;

			// Decreasing the Candidate's popularity
			currentCan.setPopularity(currentEvent.getEffect());

			std::cout << std::endl;
		}
		else if(eventNum == 19)
		{
			currentEvent = events[5];

			// Choosing a random Electorate
			currentElec = electorates[randomUniform(0,electorates.size()-1)];

			// Choosing a random Candidate
			std::cout << currentEvent.getDescription() << " in " << currentElec.getName() << "." << std::endl;

			// Altering the Candidate's popularity
			currentElec.setPopulation(currentEvent.getEffect());

			std::cout << std::endl;
		}
		else if(eventNum == 20)
		{
			currentEvent = events[6];

			// Choosing a random Electorate
			currentElec = electorates[randomUniform(0,electorates.size()-1)];

			// Choosing a random Candidate
			std::cout << currentEvent.getDescription() << " in " << currentElec.getName() << "." << std::endl;

			// Altering the Candidate's popularity
			currentElec.setPopulation(currentEvent.getEffect());

			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

// Run the Election
void runElection()
{
	std::cout << "           [ ELECTION DAY ] "<< std::endl;
	std::cout << "--------------------------------------\n" << std::endl;
	parties[0].setVotes(0);
	parties[1].setVotes(0);
	parties[2].setVotes(0);

	// Looping through each Electorate
	for (int i = 0; i < electorates.size(); ++i)
	{
		// Establishing variables to count each party's votes
		int p1Votes = 0, p2Votes = 0, p3Votes = 0;

		// Looping through each voter in an Electorate
		for (int j = 0; j < electorates[i].getPopulation(); ++j)
		{
			// Establishing a random value for each voter's stance
			int voterStance = randomUniform(electorates[i].getLowStance(), electorates[i].getHighStance());

			// Switch Case for each voter and adding their vote to the appropriate party
			switch(voterStance)
			{
				case 1 ... 3:
					p1Votes++;
					break;
				case 4 ... 6:
					p2Votes++;
					break;
				case 7 ... 9:
					p3Votes++;
					break;
			}
		}

		std::cout << "The " << electorates[i].getName() << " electorate has finished voting." << std::endl << std::endl;
		std::cout << "The results:" << std::endl;

		// Adding the votes to each party
		parties[0].addVotes(p1Votes);
		parties[1].addVotes(p2Votes);
		parties[2].addVotes(p3Votes);

		// Printing each party's votes
		for (int k = 0; k < 3; ++k)
		{
			std::cout << "   The " << parties[k].pName << " currently have " << parties[k].getVotes() << " votes." << std::endl;
		}

		// If the Autobot have more votes than the other parties
		if(p1Votes >= p2Votes && p1Votes >= p3Votes)
		{
			std::cout << std::endl << "The Autobot have won this electorate." << std::endl << std::endl;
			parties[0].addEWins();
		}
		// If the Decepticon have more votes than the other parties
		else if(p2Votes >= p1Votes && p2Votes >= p3Votes)
		{
			std::cout << std::endl << "The Decepticon have won this electorate." << std::endl << std::endl;
			parties[1].addEWins();
		}
		// If the Terrocon
		else if(p3Votes >= p1Votes && p3Votes >= p2Votes)
		{
			std::cout << std::endl << "The Terrocon have won this electorate." << std::endl << std::endl;
			parties[2].addEWins();
		}
		std::cout << "--------------------------------------" << std::endl ;
	}

	std::cout << "            [ OVERRALL ] "<< std::endl;
	std::cout << "--------------------------------------\n" << std::endl;
	// Printing out each party's total votes and the electorates they've won
	for (int k = 0; k < 3; ++k)
	{
		std::cout << "The " << parties[k].pName << " recieved a total of " << parties[k].getVotes() << " votes and won " << parties[k].getEWins() << " electorates." << std::endl;
	}
	std::cout << std::endl;

	// Printing out the appropriate party if they've won the Campaign
	if(((double)parties[0].getEWins() / electorates.size()) > 0.5)
	{
		std::cout << "The Autobot have won the election by winning more than 50% of the votes and won in " << parties[0].getEWins() << "/" << electorates.size() << " electorates." << std::endl;
		std::cout << parties[0].leader.name << " is our new leader of Cybertron."<< std::endl;
	}
	else if(((double)parties[1].getEWins() / electorates.size()) > 0.5)
	{
		std::cout << "The Decepticon have won the election by winning more than 50% of the votes and won in " << parties[1].getEWins() << "/" << electorates.size() << " electorates." << std::endl;
		std::cout << parties[1].leader.name << " is our new leader of Cybertron."<< std::endl;
	}
	else if(((double)parties[2].getEWins() / electorates.size()) > 0.5)
	{
		std::cout << "The Terrocon have won the election by winning more than 50% of the votes and won in " << parties[2].getEWins() << "/" << electorates.size() << " electorates." << std::endl;
		std::cout << parties[2].leader.name << " is our new leader of Cybertron."<< std::endl;
	}

	else
    {
		std::cout << "No party has won over 50% of the votes.\nSo it is now a hung parliament." << std::endl;
	}
}

// Random engine
int randomUniform(int num1, int num2)
{
	static std::random_device rd;
	static std::mt19937 mt(rd());
	std::uniform_int_distribution<> distr(num1, num2);
	return distr(mt);
}
