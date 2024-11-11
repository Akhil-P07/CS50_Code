#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int check_key(string argv);
string encrypt(string argv, string plaintext);

int main(int argc, const string argv[])
{
    if (argc != 2) //Shows the error if Key is not entered or if more than one Key is entered.
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    else
    {
        int check = check_key(argv[1]);
        if (check == 1)
        {
            string plaintext = get_string("Plain text:  "); //Text to be converted to cipher text is obtained from user.
            printf("ciphertext: %s\n", encrypt(argv[1], plaintext)); //Prints the Encrypted text.
            return 0;
        }
        else if (check == 2)
        {
            printf("Key must contain 26 characters.\n");
        }
        else if (check == 3)
        {
            printf("Key must contain only alphabets.\n");
        }
        else if (check == 4)
        {
            printf("Characters in the key must not repeat.\n");
        }
        return 1;
    }
}


int check_key(string argv)
{
    int check = 1; //default which will be returned if all condititions are met.
    for (int i = 0; i < 26; i++)
    {
        if (strlen(argv) != 26) //Checks that key is of 26 characters.
        {
            check = 2;
            return check;
            break;
        }
        char c = argv[i];
        if (isalpha(c) == 0) //Checks that the key only contains alphabets.
        {
            check = 3;
            return check;
            break;
        }
        else
        {
            //All characters in the key will be cycled through except the character being verified in variable check.
            for (int j = 0; j < 26; j++) //Checks the key for repeated alphabets case Inclusive.

            {
                if (i == j)
                {
                }
                else if (argv[j] == c)
                {
                    check = 4;
                    return check;
                    break;
                }
            }
        }
    }
    return check; //Return values 1, 2, 3 and 4 serve as error codes for main().

}

//Entered Key  replaces the normal alphabets and must not change the case of the outputted Cipher text.
string encrypt(string argv, string plaintext)
{
    int iterate_lim = strlen(plaintext);
    string cipher = plaintext;
    for (int i = 0; i < iterate_lim; i++) //Loops through all characters in plaintext string.
    {
        int c = 0;
        if (isalpha(cipher[i]) != 0)
        {
            if (isupper(cipher[i]) != 0)
            {
                c = cipher[i] - 65;
                cipher[i] = toupper(argv[c]);
            }
            else
            {
                c = cipher[i] - 97;
                cipher[i] = tolower(argv[c]);
            }
        }
    }
    return cipher;
}
