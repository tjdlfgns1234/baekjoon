#include <iostream>
#include <algorithm>
#include <map>
#define mod 1000000007
using namespace std;

map <long long, long long> memo;
long long formula(long long n);
long long gcd(long long a, long long b);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long a, b;

	cin >> a >> b;
	memo[0] = 0;
	memo[1] = 1;
	memo[2] = 1;
	cout << formula(gcd(a, b));


	return 0;
}
long long formula(long long n)
{
	if (memo.find(n) != memo.end())  
	{
		return memo[n];
	}
	long long tmp, tmp2;


	if (n % 2LL == 1LL)
	{
		tmp = formula(((n) / 2LL) + 1LL);
		tmp2 = formula(((n) / 2LL));
		memo[n] = (((tmp * tmp) % mod) + (tmp2 * tmp2) % mod) % mod;
		return memo[n];
	}
	else
	{
		tmp = formula((n / 2LL) - 1LL);
		tmp2 = formula((n / 2LL));
		memo[n]= (((2 * tmp + tmp2) % mod) * tmp2) % mod;
		return memo[n];
	}
}
long long gcd(long long a, long long b)
{
	long long n = -1;
	long long tmp = max(a, b);
	long long tmp2 = min(a, b);

	while (1)
	{
		n = tmp % tmp2;
		tmp = tmp2;
		tmp2 = n;
		if (n == 0)
			break;
	}
	return tmp;
}