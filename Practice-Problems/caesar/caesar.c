#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
string convertcipher(string plaintxt,int key);
int main(int argc, string argv[])
{

    int key = atoi(argv[2]);
    if (argc != 2)
    {
        printf("Usage: ./caesar KEY\n");
        return 1;
    }
    if(key < 0)
    {
        printf("KEY must be a non-negative integer\n");
        return 1;
    }
    key = key % 26;
    string plaintxt = get_string("Plaintext:  ");
    printf("Ciphertext:  %s", convertcipher(plaintxt, key));

}

string convertcipher(string plaintxt,int key)
{
    string ciphertxt = "";
    int len = strlen(plaintxt);
    for (int i = 0; i < len; i++)
    {
        ciphertxt += plaintxt[i] + key;
    }
    return ciphertxt;
}
