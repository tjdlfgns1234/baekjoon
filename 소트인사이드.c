#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 10

int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}


int main(void)
{
	int n, num[SIZE] = { 0 },sum=10,sum2=1;
	scanf("%d", &n);

	num[0] = n % 10;
	for (int i = 1; i < SIZE; i++)
	{
		sum2 = sum2 * 10;
		sum = sum * 10;
		num[i] = (n - (n / sum) * sum) / sum2;
	}

	for (int i = 0; i < SIZE; i++)
	{
		if (num[SIZE-i-1] == 0)
		{
			num[SIZE - i - 1] = INT_MIN;
		}
		else
		{
			break;
		}
	}

	qsort((void*)num, SIZE, sizeof(int), compare);

	for (int i = 0; i < SIZE; i++)
	{
		if (num[SIZE - 1 - i] >-1)
		{
			printf("%d", num[SIZE - 1 - i]);
		}
	}

	return 0;
}