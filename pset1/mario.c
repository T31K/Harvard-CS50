#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Insert height: \n");
    }
    while (height < 1 || height > 8);

    for (int row = 1; row <= height; row++)
    {
        for (int spaces = height - row ; spaces > 0; spaces--)
        {
            printf(" ");
        }
        for (int hash = 1; hash <= row; hash++)
        {
            printf("#");
        }
        printf("  ");
        for (int hash = 1; hash <= row; hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}





