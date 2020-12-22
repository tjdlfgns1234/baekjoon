#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map <unsigned long long, unsigned long long>mp;
unsigned long long mul(unsigned long long a, unsigned long long b, unsigned long long mod);
unsigned long long multi(unsigned long long a, unsigned long long b, unsigned long long mod);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	unsigned long long a, b, c;
	cin >> a >> b >> c;
	cout << multi(a%c, b, c);

	return 0;
}
unsigned long long multi(unsigned long long a, unsigned long long b, unsigned long long mod)
{
	if (b == 1)
		return mp[1] = a % mod;
	else if (b == 0)
		return 1;
	else if (mp.find(b) != mp.end())
		return mp[b];
	else if ((b % 2) == 1)
		return mp[b] = mul(multi(a%mod, (b / 2) + 1, mod), multi(a % mod, (b / 2), mod),mod)% mod;
	else
		return mp[b] = mul(multi(a% mod, b / 2, mod), multi(a% mod, b / 2, mod),mod) % mod;
}
unsigned long long mul(unsigned long long a, unsigned long long b, unsigned long long mod)
{
	// a la russe 방식
	unsigned long long sum = 0;
	while (a > 0)
	{
		if (a & 1)
			sum += b, sum %= mod;
		a >>= 1, a %= mod;
		b <<= 1, b %= mod;
	}
	return sum % mod;
}