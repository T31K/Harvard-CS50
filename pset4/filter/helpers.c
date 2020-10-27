#include "helpers.h"
#include <math.h>
#include <string.h>

//function prototype
void swap(void);
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{   
    //loop for height (rows)
    float greyscale;
    for (int i = 0 ; i < height ; i++)
    {
        //nested loops for width (columns) -___- 
        for (int j = 0 ; j < width ; j++)
        {
            greyscale = round((image[i][j].rgbtRed + image[i][j].rgbtGreen +  image[i][j].rgbtBlue )/ 3.0000);
            image[i][j].rgbtRed = greyscale;
            image[i][j].rgbtGreen = greyscale;
            image[i][j].rgbtBlue = greyscale;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //loop for height
    float sepiaRed, sepiaGreen, sepiaBlue;
    for (int i = 0 ; i < height ; i++)
    {
        //nested loops for width
        for (int j = 0 ; j < width ; j++)
        {
            sepiaRed = round((image[i][j].rgbtRed * .393) + (image[i][j].rgbtGreen * .769) + (image[i][j].rgbtBlue * .189));
            sepiaGreen = round((image[i][j].rgbtRed * .349) + (image[i][j].rgbtGreen * .686) + (image[i][j].rgbtBlue * .168));
            sepiaBlue = round((image[i][j].rgbtRed * .272) + (image[i][j].rgbtGreen * .534) + (image[i][j].rgbtBlue * .131));
            
            //check if Red is more than 255 after algorithm
            if (sepiaRed >= 255)
            {
                image[i][j].rgbtRed = 255 ;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }   
            //check if Green is more than 255 after algorithm  
            if (sepiaGreen >= 255)
            {
                image[i][j].rgbtGreen = 255 ;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            
            //check if Blue is more than 255 after algorithm
            if (sepiaBlue >= 255)
            {
                image[i][j].rgbtBlue = 255 ;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height ; i++)
    {
        //loop for columns
        for (int j = 0 ; j < width / 2 ; j++)
        {
            RGBTRIPLE temp =  image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp ;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{   
    //temp storage
    RGBTRIPLE temp[height][width];
    
    //copy image to keep
    memcpy(temp, image, sizeof(RGBTRIPLE) * height * width);
    
    //loop rows
    for (int i = 0 ; i < height ; i++)
    {
        //nested loop columns
        for (int j = 0 ; j < width ; j++)
        {
            float average = 0.0 ;
            
            int R = 0;
            int G = 0;
            int B = 0;
            
            //iterate over rows of current row
            for (int k = -1 ; k <= 1 ; k++)
            {
                //iterate over culmns of current col
                for (int l = -1 ; l <= 1 ; l++)
                {
                    if (i + k != height &&
                        i + k != -1 &&
                        j + l != width &&
                        j + l != -1 )
                    {
                        //update RGB values
                        R += temp[i + k][j + l].rgbtRed;
                        G += temp[i + k][j + l].rgbtGreen;
                        B += temp[i + k][j + l].rgbtBlue;
                        
                        average++;
                        
                    }
                }
            }
            //set blur values
            image[i][j].rgbtRed = round(R / average) ;
            image[i][j].rgbtGreen = round(G / average) ;
            image[i][j].rgbtBlue = round(B / average) ;

        }
    }
}
