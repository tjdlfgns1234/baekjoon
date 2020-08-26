#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int check_prime(long long n);
int result;

int main(void)
{
	int t;
	long long n;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		scanf("%lld", &n);
		for (long long j = n;; j++)
		{
			if (check_prime(j))
			{
				printf("%lld\n", j);
				break;
			}
		}
	}
	return 0;
}
int check_prime(long long n)
{
	if (n == 1)
	{
		return 0;
	}
	else if (n == 2)
	{
		return 1;
	}
	else if (n % 2 == 0)
	{
		return 0;
	}

	for (long long i = 3LL; i*i <= n; i = i + 2LL)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	// 여기까지 왔으면 소수이다.
	return 1;
}