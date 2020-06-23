#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int check_prime(int N);

int main(void)
{
	int N, M, check = 0;

	scanf("%d %d", &M,&N);
	for (int i = M; i < N+1; i++)
	{
		if (i == 2)
		{
			printf("%d\n", 2);
		}
		if ((i % 2) == 1)
		{
			check = check_prime(i);
			if (check == 1)
			{
				printf("%d\n", i);
			}
		}
	}
	return 0;
}
int check_prime(int N)
{
	int remains = -1;
	double to = 0.0;
	if (N == 1)
	{
		return 0;
	}
	if (N == 2)
	{
		return 1;
	}
	to = sqrt(N);
	for (int i = 3; i <=to; i++)
	{
		remains = N % i;
		if (remains == 0)
		{
			return 0;
		}
	}
	return 1;
}