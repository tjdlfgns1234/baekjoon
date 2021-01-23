#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mod 987654321
using namespace std;

ll dp[5001] = { 0 };

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
	while (tmp != 5001)
	{
		if (!dp[tmp])
			for (int i = 0; i < tmp; i++)
				dp[tmp] = (dp[tmp] + (dp[i] * dp[tmp - i - 1]) % mod) % mod;
		tmp++;
	}

	if (t % 2 == 0)
		cout << dp[t / 2];
	else
		cout << 0;

	return 0;
}