#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }




    // Display winner of election
    print_winner();


}









bool vote(string name)
{
    for(int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return 1;


        }

    }

    return 0;
}









void print_winner(void)
{
    int winner_count = 0;
    int votes = candidates[0].votes;
    for(int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > votes)
        {
            votes = candidates[i].votes;
            winner_count = i;
        }
    }
    printf("winner_count: %i", winner_count);
    for(int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes == candidates[winner_count].votes)
        {
            printf("%s", candidates[j].name);
            printf("%s", candidates[winner_count].name);

        }
    }
}