c#include <stdio.h>
#include <math.h>
#include <cs50.h>

long digit_split(long c_num, int
                 i); //i is the digits place. The digits are numbered 1 to 16 from the right to left of the number.
void companyName(long c_num, int cs); //Determines the company of the credit card

int main(void)
{
    const int c_lim = 16; // credit card digits limit
    int cs = 0; //Checksum value
    bool ab = 0; //bool to alternate digits
    long ird = 0; // tenths place digit in second digit split
    long irf = 0; //firsts place digit in second digit split

    const long c_num = get_long("Enter Credit Card number: "); //User inputs credit card number
    for (int i = 1; i <= c_lim; i++)
    {
        int y = ab;
        int x = digit_split(c_num, i);
        irf = digit_split((x * 2), 1);
        ird = digit_split((x * 2), 2);

        if (ab == 0)
        {
            cs = cs + x; //Add with cs
            ab = 1;
        }
        else if (ab == 1)
        {
            ab = 0;
            cs = ird + irf + cs;//Multiply by 2 and split digits and add with cs
        }
    }
    cs = digit_split(cs, 1);
    companyName(c_num, cs);
}









void companyName(long c_num, int cs)
{
    string reply = "INVALID";           // Set to Invalid by default
    int init1 = digit_split(c_num, 16); //Digit order from Left to right side with variables in descending order order
    int init2 = digit_split(c_num, 15);
    int init3 = digit_split(c_num, 14);
    int init4 = digit_split(c_num, 13);
    if (cs == 0)
    {
        if (init1 == 5 && (init2 == 1 || init2 == 2 || init2 == 3 || init2 == 4 || init2 == 5))
        {
            reply = "MASTERCARD";
        }
        else if (init1 == 4)
        {
            reply = "VISA";
        }
        else if (init1 == 0 && init2 == 0 && init4 == 4)
        {
            reply = "VISA";
        }
        else if (init1 == 0 && init2 == 3 && (init3 == 7 || init3 == 4))
        {
            reply = "AMEX";
        }
    }
    printf("%s\n", reply);
}













long digit_split(long c_num, int
                 i) //Function splits the number into singular digits. The position of the digits is in descending, The first place  digit being 1
{
    int t = i - 1;                  //Variable t will be used in truncating the credit card number to get the individual digits.

    long z = pow(10, i);
    long y = pow(10, t);

    long digit = (c_num % z) / y;
    return digit;
}
