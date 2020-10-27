#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string input = get_string("Text: \n");


    float letters = 0 ;
    float words = 1 ;
    float sentences = 0 ;
    float index;
    float L;
    float S;

    char space = ' ' ;
    char p = '.' ;
    char ex = '!' ; 
    char apos = '\'' ;
    char ques = '?' ;
    char apos_2 = '\"';
    char comma = ',' ;

    for (int i = 0 ; input[i] ; i++)
    {
        // count letters
    if (input[i] != space && input[i] != p && input[i] != ex && input[i] != apos && input[i] != ques && input[i] != apos_2 && input[i] != comma)
        {
            letters++ ;
        }

        // count sentences
        if (input[i] == p || input[i] == ex || (input[i] == ques && input[i+1] == apos_2) || input[i] == ques)
        {
            sentences++ ;
        }

        // count words
        if (input[i] == space && input[i+1] != '\0')
        {
            words++ ;
        }
    }
    
    //letters per 100 words
    L = (letters / words) * 100 ;

    //sentence per 100 words
    S = (sentences / words) * 100 ;

    // total
    index = (0.0588 * L) - (0.296 * S) - 15.8 ;
    int f_index = round(index);
    printf("%f \n", index) ;
    printf("%i \n", f_index) ;

    if (f_index >= 1 && f_index <= 16)
    {
        printf("Grade %i\n", f_index) ;
    }
    else
    {
        if (index < 1)
        {
            printf("Before Grade 1\n") ;
        }
        if (f_index > 16)
        {
            printf("Grade 16+\n") ;
        }
    }


//printf("Letter(s): %f \n", letters);
//printf("Words(s): %f \n", words);
//printf("Sentence(s): %f \n", sentences);
}