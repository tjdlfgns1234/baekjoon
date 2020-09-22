#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

int count = 0;
long long fibo[3] = { 0,1,1 };
struct dp {
	long long key;
	long long value;
};

typedef struct dp dp;

dp memo[SIZE];
int memoization(long long n);
long long formula(long long p,long long mod);

int main(void)
{
	int n;
	long long p,mod;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%lld %lld", &p, &mod);
		count = 0;
		printf("Case #%d: %lld\n", i+1,formula(p, mod));
	}

	
	return 0;
}
long long formula(long long p, long long mod)
{
	if (p <= 2)	//brute force
	{
		return fibo[p] % mod;
	}
	else if (memoization(p))
	{
		return memo[memoization(p)].value;
	}
	long long tmp, tmp2;


	if (p % 2LL == 1LL)
	{
		tmp = formula(((p) / 2LL) + 1LL,mod);
		tmp2 = formula(((p) / 2LL),mod);
		memo[count].value = (((tmp * tmp)) + (tmp2 * tmp2)) % mod;
		memo[count].key = p;
		count++;
		return memo[count - 1].value;
	}
	else
	{
		tmp = formula((p / 2LL) - 1LL,mod);
		tmp2 = formula((p / 2LL),mod);
		memo[count].value = (((2 * tmp + tmp2)%mod) * tmp2) % mod;
		memo[count].key = p;
		count++;
		return memo[count - 1].value;
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