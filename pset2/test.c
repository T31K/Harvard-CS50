#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string y[])
{   
    int number = argc;
    string key = y;


    if (argc != 2)
    {

        return 0;
    }

    else 
    {
        int numberkey = atoi(key);
        if (numberkey > 0)
        {
            return numberkey;
        }
        else
        {
            return 0;
        }
    }


}
