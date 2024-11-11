#include <stdio.h>
#include <cs50.h>

string main(void)
{
    int liszt = {3,2,1,12,131}
    arlen = 5
    n = get_int("Number: ");
    for(int i = 0; i < 5; i++)
    {
        if (n == liszt[i])
        {
            return Found;
        }
    }
    return Not Found;
}
