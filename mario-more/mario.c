#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    int j;
    int k;
    int i;

    //User is prompted for height of pyramid
    do
    {
        h = get_int("Enter height between 0 and 9: ");  //stores user input for required height
    }
    while (h > 8 || h <= 0);


    //Pyramid of given height is printed

    for (j = 1; j <= h; j++) //height of pyramid
    {
        for (k = h - 1; k >= j; k--)  //alignment left pyramid
        {
            printf(" ");
        }
        for (i = 1; i <= j; i++) //horizontal length of left pyramid
        {
            printf("#");
        }

        printf("  "); //space beween pyramids

        for (i = 1; i <= j; i++) //horizontal length of right pyramid
        {
            printf("#");
        }

        printf("\n");
    }
}