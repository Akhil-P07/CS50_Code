#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score(string word);

int main(void)
{
    //inputs words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");


    //Score of both words

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    //Prints the winner

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("tie\n");
    }
}

int compute_score(string word)  //Converts alphabet ASCII value to array POINTS index to access the value of the alphabet in POINTS.
{
    //Computes and returns score for string
    int score = 0;
    int L_ASCIIV = 90; //Largest Character by ASCII value
    int S_ASCIIV = 65; //Smallest Character by ASCII value
    for (int i = 0; i < strlen(word); i++)
    {
        int convert = toupper(word[i]) -
                      65; //Converts all given letters into uppercase then Subtracts 65 from each character to recieve the the position in the POINTS Array
        if (convert < (S_ASCIIV - 65))
        {
            break;                           //Doesn't add value of character if its ASCII value is below 65
        }
        else if (convert > (L_ASCIIV - 65))
        {
            break;                           //Doesn't add value of character if its ASCII value is above 90
        }
        else
        {
            score = score + POINTS[convert]; // Adds value of character in POINTS to score
        }

    }
    return score;

}