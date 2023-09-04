#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int red_value = image[i][j].rgbtRed;
            int green_value = image[i][j].rgbtGreen;
            int blue_value = image[i][j].rgbtBlue;

            float avereage = (red_value + green_value + blue_value)/3.0;
            avereage = avereage + 0.5;

            image[i][j].rgbtRed = avereage;
            image[i][j].rgbtGreen = avereage;
            image[i][j].rgbtBlue = avereage;
        }
    }
}








// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepia[3];
    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            sepia[0] = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            sepia[1] = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            sepia[2] = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;

            sepia[0] = sepia[0] + 0.5;
            sepia[1] = sepia[1] + 0.5;
            sepia[2] = sepia[2] + 0.5;

            for(int k = 0; k < 3; k++)
            {
                if (sepia[k] > 255)
                {
                    sepia[k] = 255;
                }
            }

            image[i][j].rgbtRed = sepia[0];
            image[i][j].rgbtGreen = sepia[1];
            image[i][j].rgbtBlue = sepia[2];

        }
    }
}






// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width/2; j++)
        {
            RGBTRIPLE *p1 = &image[i][j];
            RGBTRIPLE *p2 = &image[i][width - 1 -j];
            RGBTRIPLE tmp = *p1;
            *p1 = *p2;
            *p2 = tmp;

        }
    }
}







// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }



    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int avereage_red = 0;
            int avereage_green = 0;
            int avereage_blue = 0;

            int height_index = i - 1;
            int width_index = j - 1;

            for(int k = 0; k < 3; k++)
            {
                height_index++;
                for(int g = 0; g < 3; g++)
                {
                    width_index++;

                    int red = copy[height_index][width_index].rgbtRed;
                    int green = copy[height_index][width_index].rgbtGreen;
                    int blue = copy[height_index][width_index].rgbtBlue;

                    avereage_red = avereage_red + red;
                    avereage_green = avereage_green + green;
                    avereage_blue = avereage_blue + blue;

                }
            }

            image[i][j].rgbtRed = avereage_red;
            image[i][j].rgbtGreen = avereage_green;
            image[i][j].rgbtBlue = avereage_blue;
        }
    }
}
