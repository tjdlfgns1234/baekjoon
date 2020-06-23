#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 10

int main(void)
{
	int N;
	int tmp = 0, sum = 10, Max = INT_MIN,Max2=0;
	int count[10] = { 0 }, num[SIZE] = { 0 };

	scanf("%d", &N);
	if (N <10)
	{
		printf("1");
		return 0;
	}
	num[0] = N % 10;
	
	for (int i = 1; i < SIZE; i++)
	{
		num[i]=(N / sum) % (10);
		sum = sum * 10;
	}

	for (int i = SIZE-1; i > 0; i--)
	{
		if (num[i] != 0)
		{
			tmp = i + 1;
			break;
		}
	}

	for (int i=0;i<tmp;i++)
	{
		count[num[i]]++;
		sum = sum * 10;
	}
	for (int i =0; i < SIZE; i++)
	{
		if (i != 6 && i != 9)
		{
			if (count[i] > Max)
			{
				Max = count[i];
			}
		}
	};

	Max2 = count[6] + count[9];
	if (Max >= Max2 / 2 + Max2 % 2)
	{
		printf("%d", Max);
	}
	else
	{
		printf("%d", Max2 / 2 + Max2 % 2);
	}

	return 0;
}