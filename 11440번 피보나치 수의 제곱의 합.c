#include <stdio.h>
#include <stdlib.h>
#define mod 1000000007LL
#define SIZE 1000

int count = 0;
long long fibo[3];

struct dp {		// for memoization
	long long key;
	long long value;
};

typedef struct dp dp;

dp memo[SIZE];
int memoization(long long n);
long long formula(long long n);

int main(void)
{
	long long n;
	fibo[0] = 0;
	fibo[1] = 1;
	fibo[2] = 1;
	scanf("%lld",&n);

	printf("%lld",(formula(n)*formula(n+1)%mod));
	

	return 0;
}
long long formula(long long n)
{
	if (n < 3)	//brute force
	{
		return fibo[n]%mod;
	}
	else if (memoization(n))  // memoization
	{
		return memo[memoization(n)].value;
	}
	long long tmp, tmp2;
	

	if (n % 2LL == 1LL)
	{
		tmp = formula(((n) / 2LL) + 1LL);
		tmp2 = formula(((n) / 2LL));
		memo[count].value=(((tmp * tmp)) + (tmp2 * tmp2)) % mod;
		memo[count].key = n;
		count++;
		return memo[count-1].value;
	}
	else
	{
		tmp = formula((n / 2LL) - 1LL);
		tmp2 = formula((n / 2LL));
		memo[count].value=(((2*tmp+tmp2)) *tmp2)%mod;
		memo[count].key = n;
		count++;
		return memo[count-1].value;
	}
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