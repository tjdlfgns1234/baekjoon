#include <stdio.h>
#include <stdlib.h>

int check_prime(int N);
int count = 0;

int main(void)
{
	int N, check = 0;
	int* num;

	scanf("%d", &N);
	num = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
		check=check_prime(num[i]);
		if (check == 1)
		{
			count++;
		}
	}
	printf("%d", count);

	return 0;
}
int check_prime(int N)
{
	int remains = -1;
	if (N == 1)
	{
		return 0;
	}
	for (int i = 2; i < N / 2 + 1; i++)
	{
		remains = N % i;
		if (remains == 0)
		{
			return 0;
		}
	}
	return 1;
}