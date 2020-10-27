#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{   
    //check if caesar is given 2 arg (caesar, #)
    if (argc != 2)
    {
        printf("./caesar key");
        return 1;
    }
    
   
    int argv_count = atoi(argv[1]);
    string cmp = "2x";
    int compare_h = strcmp(argv[1], cmp);
    
    if (argv_count == 0 || compare_h == 0)
    {
        printf("./caesar key");
        return 1;
    }

    //get user input
    string input = get_string("Insert plain text: ");
    int n = strlen(input);
    //print cipher text
    printf("ciphertext: ");
    for (int i = 0 ; i < n ; i++)
    {   
        //check is input is alpha
        if (isalpha(input[i]))
        {
            //if input is alpha, then check if it upper
            if (isupper(input[i]))
            {   
                //the input is alpha, apply formula
                printf("%c", ((input[i] - 'A' + argv_count) % 26) + 'A');
            }
            else if (islower(input[i]))
            {   
                //the in put is lower, apply formula
                printf("%c", ((input[i] - 'a' + argv_count) % 26) + 'a');
            }
        }
        else
        {
            printf("%c", input[i]) ;
        }
    } 
    printf("\n");
  
}