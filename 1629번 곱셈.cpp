#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map <long long, long long>mp;
long long multi(long long a, long long b, long long mod);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long a, b, c;
	cin >> a >> b >> c;
	cout << multi(a, b, c);

	return 0;
}
long long multi(long long a, long long b, long long mod)
{
	if (b == 1)
		return mp[1] = a%mod;
	else if (b == 0)
		return 1;
	else if (mp.find(b) != mp.end())
		return mp[b];
	else if ((b%2) == 1)
		return mp[b] = (multi(a, (b / 2)+1, mod) * multi(a, (b / 2), mod)) % mod;
	else 
		return mp[b] = (multi(a, b / 2, mod) * multi(a, b / 2, mod))%mod;
}