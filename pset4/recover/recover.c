#include <stdio.h>
#include <stdint.h>

//GLOBAL variables
const int BLOCK = 512;
uint8_t BUFFER[512];
FILE *f;
FILE *n;
int counter = 0;
char filename[8];

int main(int argc, char *argv[])
{
    //simple check if usage is correct with 2 argc
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    
    //remember filename
    char *input = argv[1];
    //1 open file
    f = fopen(input, "r");
    
    //if nothing to open
    if (f == NULL)
    {
        printf("Error opening the file %s \n", input);
        return 2;
    }
    
    //iterate over files, fopen all
    while (fread(BUFFER, BLOCK, 1, f))
    {
        if (BUFFER[0] == 0xff && BUFFER[1] == 0xd8 && BUFFER[2] == 0xff && (BUFFER[3] == 0xe0 || BUFFER[3] == 0xe1))
        {
            //close new file if opened
            if (n != NULL)
            {
                fclose(n);
            }
        
            //if found, save to new file
            sprintf(filename, "%03d.jpg", counter);
            
            n = fopen(filename, "w");
            
            counter++;
        }       
        
        if (n != NULL)
        {
            fwrite(BUFFER, BLOCK, 1, n);
        }
        
    }
    
    if (n != NULL)
    {
        fclose(n);
    }
    
    fclose(f);
    return 0;
}
    

