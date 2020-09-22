#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

int count = 0;
long long arr[3] = { 1 };
struct dp {
	long long key;
	long long value;
};

typedef struct dp dp;

dp memo[SIZE];
int memoization(long long n);
long long formula(long long n,long long p,long long q);

int main(void)
{
	long long n;
	long long p,q;

	scanf("%lld %lld %lld", &n,&p, &q);
	printf("%lld",formula(n,p,q));
	
	return 0;
}
long long formula(long long n, long long p, long long q)
{
	if (n <= 0)	//brute force
	{
		return arr[n];
	}
	else if (memoization(n))
	{
		return memo[memoization(n)].value;
	}
	long long tmp, tmp2;

	tmp = formula((n/p),p,q);
	tmp2 = formula((n/q) ,p,q);
	memo[count].value = tmp + tmp2;
	memo[count].key = n;
	count++;
	return memo[count - 1].value;
}
int memoization(long long n)
{
	for (int i = 0; i < count; i++)
	{
		if (n == memo[i].key)
		{
			return i;
		}
	}
	return 0;
}