#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mod 1000000007
using namespace std;

ll dp[2501] = { 0 };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int t;
	cin >> t;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 5;

	ll tmp = 4;
	while (tmp != 2501)
	{
		if (!dp[tmp])
			for (int i = 0; i < tmp; i++)
				dp[tmp] =(dp[tmp] + (dp[i] * dp[tmp - i - 1]) % mod) % mod;
		tmp++;
	}


	while (t--)
	{
		int l;
		cin >> l;
		if (l % 2 == 1)
			cout << 0 << '\n';
		else
			cout << dp[l / 2] << '\n';
	}


	return 0;
}