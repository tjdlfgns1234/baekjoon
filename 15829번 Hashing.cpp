#include <bits/stdc++.h>
#define ll long long
#define mod 1234567891

using namespace std;

void solve();

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	solve();

	return 0;
}
void solve()
{
	string s;
	int l;
	cin >> l;
	cin >> s;

	ll sum = 1;
	ll tmp;
	ll ans = 0;
	for (int i = 0; i < l; i++)
	{
		tmp = s[i] - 'a' + 1;
		ans += (sum * tmp)%mod;
		sum = (31 * sum) % mod;
	}
	cout << ans%mod;
}