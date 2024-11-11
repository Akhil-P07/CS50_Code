#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Prompts user for name
    string name = get_string("Enter your name: ");

    //Outputs message with users name
    printf("Hello, %s\n", name);
}