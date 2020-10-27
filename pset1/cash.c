#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //quarter 25, dime 10, nickel 5, penny 1
    int Q;
    int D;
    int N;
    int P;
    int total_coins = 0;

    int total_Q = 0;
    int total_D = 0;
    int total_N = 0;
    int total_P = 0;
    
    float input;
    do
    {
        input = get_float("Change required?: \n");    
    }
    while (input < 0);
    
    int cents = round(input * 100);
    for (Q = 1; cents >= 25 ; Q++)
    {
        //calculate quarters needed
        cents -= 25  ;
        total_coins ++ ;
        total_Q ++;
    }
    for (D = 1; cents >= 10 ; Q++)
    {
        //calculate dimes needed
        cents -= 10  ;
        total_coins ++ ;
        total_D ++;
    }
    for (N = 1; cents >= 5 ; Q++)
    {   
        //calculate nickels needed
        cents -= 5  ;
        total_coins ++ ;
        total_N ++;
    }
    for (P = 1; cents >= 1 ; Q++)
    {
        //calculate pennies needed
        cents -= 1  ;
        total_coins ++ ;
        total_P ++;
    }
    printf("The machine will output a total of %i coin(s) \n", total_coins);
    //additional print function to distinguish how many coins of each to output (additional)
    printf("The machine will output %i quarter(s), %i dime(s), %i nickel(s), %i penny(ies) \n", total_Q, total_D, total_N, total_P);
} 