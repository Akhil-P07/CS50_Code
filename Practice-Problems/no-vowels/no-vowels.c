// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
string replace (string argv);

int main(int argc, string argv[])
{
    printf("%s\n",replace(argv[1]));
}
string replace (string argv)
{
    //Iterates through letters and finds vowels to then replace
    for (int i = 0; i < strlen(argv); i++)
    {
        switch(argv[i])
        {
            case (65|92):
                argv[i] = 6;
                break;
            case (69|101):
                argv[i] = 3;
                break;
            case (73|105):
                argv[i] = 1;
                break;
            case (79|111):
                argv[i] = 0;
                break;
        }

    }
    return argv;
}
