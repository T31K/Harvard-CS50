#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    long long cc;

    //get input from user
    do
    {
        cc = get_long_long("Insert C/C number: ");
    }
    while (cc <= 0);

    int cc_length_count = 0;
    long long cc_length_check = cc;

    while (cc_length_check > 0)
    {
        cc_length_check = cc_length_check / 10 ;
        cc_length_count++;
    }
    
    //check if input is less than 13 or more than 17 which is invalid
    if (cc_length_count < 13 || cc_length_count > 17)
    {
        //printf("Your credit card number is %i number(s) long\n", cc_length_count);
        printf("INVALID\n");
        return 0;
    }
    
    // check every other number and multiply 2
    int checksum_1 = 0;
    for (long long i = 10 ; i < 10000000000000000 ; i *= 100)
    {
        //first check and then multiplty 2
        long long cc_1 = ((cc % (i * 10)) / i) * 2 ;

        if (cc_1 < 10)
        {
            checksum_1 += cc_1;
        }
        else
        {
            checksum_1 += (cc_1 % 10 + (cc_1 % 100 / 10));
        }
    }

    //check every other number from index 0 and + to checksum_1
    int checksum_2 = 0;
    for (long long j = 1 ; j < 1000000000000000 ; j *= 100)
    {
        long long cc_2 = ((cc % (j * 10)) / j) ;
        checksum_2 += cc_2;
    }
    
    int checksum_final = checksum_1 + checksum_2 ;
    //printf("%i %i %i\n", checksum_1,checksum_2,checksum_final);
    int first_digit_check_sum = checksum_final % 10 ;
    
    // get first two digits
    while (cc >= 100)
    
        cc /= 10;
    
    // use the first_digit to determine which type of card
    
    if ((cc == 34 || cc == 37) && first_digit_check_sum == 0)
    {
        printf("AMEX\n") ;
    }
    else if ((cc == 41 || cc == 40) && first_digit_check_sum == 0)
    {
        printf("VISA\n") ;
    }
    else if ((cc == 51 || cc == 52 || cc == 53 || cc == 54 || cc == 55)  && first_digit_check_sum == 0)
    {
        printf("MASTERCARD\n") ;
    }
    else
    {
        printf("INVALID\n") ;
    }

}




