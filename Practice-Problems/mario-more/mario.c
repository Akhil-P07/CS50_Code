#include <cs50.h>
#include <stdio.h>

int main(void)
{

	int h = get_int("Enter height of pyramid: ");
	for (int i = 0; i < h; i++)
	{
		// Spaces before pound/hash
		for (int j = 1; j < (h - i);j++)
		{
			printf(" ");
		}
		for (int k = 0; k <= i; k++)
		{
			printf("#");
		}
		printf("  ");
		for (int k = 0; k <= i; k++)
		{
			printf("#");
		}
		printf("\n");
	}


}