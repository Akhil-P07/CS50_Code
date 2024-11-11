#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

double Count(string paragraph);
int main(void)
{
    //Gets user input
    string text = get_string("Enter text: ");
    int Index = round(Count(text));
    if (Index > 16) //The Grade level is shown for only between inclusive of 1 and 16.
    {
        printf("Grade 16+");
    }
    else if (Index < 1)
    {
        printf("Before Grade 1");
    }
    else
    {
        printf("Grade %i", Index);
    }
    printf("\n");

}

double Count(string paragraph)
{
    int letter = 0;
    int word = 1;
    int sentence = 0;
    for (int i = 0; i <= strlen(paragraph); i++)
    {
        paragraph[i] = toupper(paragraph[i]);
        if (paragraph[i] > 64 && paragraph[i] < 91)
        {
            letter++;        //Counts the no. of letters in the inputted text by cycling through each character to filter out the non-alphanumeric characters
        }
        else if (paragraph[i] == ' ')
        {
            word++;         //Counts the no. of words by finding the number of spaces in the text. The word counter starts at one as a singular word will not have a space
        }
        else if (paragraph[i] == '!') //Searches for termination marks to find the number of sentences
        {
            sentence++;
        }
        else if (paragraph[i] == '?')
        {
            sentence++;
        }
        else if (paragraph[i] == '.')
        {
            sentence++;
        }
    }
    double L = ((double)letter / word) * 100.00;    //No. of letters per 100 words
    double S = ((double)sentence / word) * 100.00;  //No. of sentence per 100 words
    double index = 0.0588 * L - 0.296 * S - 15.8; //Coleman-Liau Index
    return index;
}

