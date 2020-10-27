#include <cs50.h>
#include <stdio.h>
#include <string.h>

// max number
#define MAX 9

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX];

int candidate_count;
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    //check if command line argument was inputted
    if (argc < 2)
    {
        printf("Usage: ./plurality [candidate...]\n");
        return 1;
    }
    
    //-1 bcos argv[0] is ./plurality
    candidate_count = argc - 1 ;
    
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i \n", MAX);
        return 2;
    }
    
    //add names into list
    
    for (int i = 0 ; i < candidate_count ; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }
    
    //get number of votes from user
    int vote_count = get_int("Number of votes: ");
   
    // for every int vote_count, get a vote 
    for (int i = 0 ; i < vote_count ; i++)
    {
        //get vote from user
        string name = get_string("Vote: ");
        
        //wrong input
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }
    //print the winner/(s)
    print_winner();
}  
bool vote(string name)
{   
    for (int i = 0; i < candidate_count; i++)
    {   
        //compare strings
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}
    
void print_winner(void)
{
    int maxvotes = 0;
    
    // find highest number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > maxvotes)
        {
            maxvotes = candidates[i].votes;
        }
    }
    // print winners
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == maxvotes)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    // TODO end
    return;
}
    