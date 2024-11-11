#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start_p;
    int ending_p;
    // Variable z is used to calculate population in each year
    int z = 0;
    //Tracks year
    int i;



    // TODO: Prompt for start size
    do
    {
        start_p = get_int("Enter starting population size: ");
    }
    while (start_p < 9);

    // TODO: Prompt for end size
    do
    {
        ending_p = get_int("Enter ending population size: ");
    }
    while (ending_p < start_p);



    // TODO: Calculate number of years until we reach threshold
    if (start_p == ending_p)
    {
        i = 0;
    }
    else
    {
        for (i = 0; z < ending_p; i++)
        {
            z = start_p + (start_p / 3) - (start_p / 4);
            start_p = z;
        }
    }

    // TODO: Print number of years
    printf("Years: %i\n", i);
}
