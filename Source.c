#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int prime(int x)
/*
This function checks out if the integer number x
is a prime number or not.
*/
{
	int d, ok;
	d = 2;
	ok = 0;
	while (d <= x / 2 && ok == 0)
	{
		if (x % d == 0)
		{
			ok = 1;
		}
		else
		{
			d = d + 1;
		}
	}
	return ok;
}

void findPrimeNumbers(int x)
/*
This procedure prints out on the screen all the prime numbers
that are smaller than a given number x
*/
{
	int i;
	for (i = 2; i < x; i++)
	{
		if (prime(i) == 0)
		{
			printf("%d ", i);
		}
	}
}

void biggestLength()
/*
This procedure check the biggest length of 
consecutive numbers in the vector in the given vector
*/
{
	int vector[100];
	printf("    How many numbers you want to read: ");
	int len;
	scanf("%d \n", &len);
	int i;
	for (i = 0; i < len; i++)
	{
		printf("    Number %d", i+1);
		printf(": ");
		int nr = 0;
		scanf("%d", &nr);
		vector[i] = nr;
	}
	printf("    The vector is: ");
	for (i = 0; i < len; i++)
	{
		printf("%d ", vector[i]);
	}
	int max = 0;
	int poz = 0;
	int j = 0;
	int k = 1;
	i = 0;
	while (i < sizeof(vector) / sizeof(vector[0]))
	{
		if (vector[i] < vector[i + 1])
		{
			k = k + 1;
		}
		else
		{
			if (k > max)
			{
				max = k;
				poz = i - k + 1;
			}
			k = 1;
		}
		i = i + 1;
	}
	printf("\n    Maximum length: %d", max);
	printf("\n    The sequence: ");
	for (i = poz; i < poz + max; i++)
	{
		printf("%d ", vector[i]);
	}
}

int main()
/*
This is the main function
It prints out the menu, and allows the user
to choose what he will use.
*/
{
	printf("\n      Choose: \n \n");
	printf("      a) Generate all the prime numbers smaller than a given natural number n. \n");
	printf("      b) Given a vector of numbers, find the longest increasing contiguous subsequence. \n");
	printf("                           Your command: ");
	char cmd;
	scanf("%c", &cmd);
	if (cmd == 'a')
	{
		printf("    Number: ");
		int number;
		scanf("%d", &number);
		if (number == 2)
		{
			printf("    The prime number: %d", number);
		}
		else if (number > 2)
		{
			printf("    The prime numbers: ");
			findPrimeNumbers(number);
		}
		else
		{
			printf("    There are no prime numbers !");
		}
	}
	else if (cmd == 'b')
	{
		biggestLength();
	}
	else
	{
		printf("\n");
		printf("    Invalid command !");
	}

	printf("\n \n");
	system("pause");
	return 0;
}