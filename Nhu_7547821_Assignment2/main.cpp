#include "Person.h"
#include "Candidate.h"
#include "PoliticalParty.h"
#include "APE.h"
#include "Electorate.h"
#include "Event.h"

int main(int argc, char* argv[])
{
    // Get the number of electorates and days from command line arguments
    int electorates = atoi(argv[1]);
    int days = atoi(argv[2]);

    // Check if the input values are within valid ranges
    if (electorates >= 1 && electorates <= 10 && days >= 1 && days <= 30) {
        createIssues();
        createParties(electorates);
        createElectorates(electorates);
        createEvents();

        runCampaign(electorates, days);
        runElection();
    }
    else {
        // Print an error message if input values are not within valid ranges
        std::cout << "Error: Please ensure that the number of electorates falls within the range of 1 to 10, and that the number of days is between 1 and 30." << std::endl;
    }
    return 0;
}
