#include <iostream>
#include <algorithm>
#define SIZE 100000

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	
	int n,m;
	int dp[SIZE + 1];
	dp[0] = 0;
	cin >> n >> m;
	int v;
	for (int i = 1; i < n + 1; i++)
		cin >> v, dp[i] = dp[i - 1] + v;
	int a, b;
	for (int i = 0; i < m; i++)
		cin >> a>> b, cout << dp[b]-dp[a-1]<<'\n';

	return 0;
}