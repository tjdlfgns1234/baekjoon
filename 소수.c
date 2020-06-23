#include <stdio.h>
#include <stdlib.h>

int check_prime(int N);
int count = 0;

int main(void)
{
	int N, M, check = 0, sum = 0,min = 10001;

	scanf("%d %d", &M,&N);
	for (int i = M; i < N+1; i++)
	{
		check=check_prime(i);
		if (check == 1)
		{
			sum += i;
			if (min > i)
			{
				min = i;
			}
		}
	}
	if (sum== 0)
	{
		printf("-1");
		return 0;
	}
	printf("%d\n", sum);
	printf("%d", min);

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