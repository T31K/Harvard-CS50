#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    string name;
    int votes;
}
candidate;

#define MAX 9

candidate candidates[MAX];
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        
    }
}