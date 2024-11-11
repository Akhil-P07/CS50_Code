// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool upper_l, lower_l, num, symb = false;
    for (int i = 0;i < strlen(password); i++)
    {
        if( isalpha(password[i]) != 0)
        {
            if(isupper(password[i]) != 0)
            {
                upper_l = true;
            }
            else
            {
                lower_l = true;
            }
        }
        else if(isdigit(password[i]) != 0)
        {
            num = true;
        }
        else
        {
            symb = true;
        }
    }
    if (upper_l && lower_l && num && symb == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
