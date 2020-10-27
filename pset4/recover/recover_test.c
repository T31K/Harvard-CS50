 #include <stdio.h>
 #include <stdint.h>
 
 const int BLOCK = 512;
 
 int main(int argc, char *agrv[])
 {
    //open file f
    FILE *f;
    f = fopen("card.raw", "r");
    
    if (f == NULL)
    {
        printf("Error opening the file \"ecard.raw\"...");
        return 1;
    }
    
    
    uint8_t buf[512];
    
    int counter = 0;
    FILE *fw = NULL;
    
    // Iterate over file 
    while (fread(buf, BLOCK, 1, f))
    {
        // Check if the first four bytes are a JPEG 
        if (buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff
            && (buf[3] == 0xe0 || buf[3] == 0xe1))
        {
            // Close the file, if it is opened
            if (fw != NULL)
                fclose(fw);
                
            
            char filename[8];
            sprintf(filename, "%03d.jpg", counter);
                
            // Open a new JPEG file for writing
            fw = fopen(filename, "w");
            
            counter++;
        }
        
        if (fw != NULL)
            fwrite(buf, BLOCK, 1, fw);
    }
    
    if (fw != NULL)
        fclose(fw);
    
    fclose(f);
 
    return 0;
 } 