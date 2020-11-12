#include <algorithm>
#include <iostream>

#define SIZE 1000

using namespace std;

int dp[3][SIZE] = { 0 };
int rgb[3][SIZE]{ 0 };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> rgb[0][i] >> rgb[1][i] >> rgb[2][i];

	// 초기값 각 색에서 출발
	dp[0][0] = rgb[0][0];
	dp[1][0] = rgb[1][0];
	dp[2][0] = rgb[2][0];

	for (int i = 1; i < n; i++)
	{
		dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + rgb[0][i];
		dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + rgb[1][i];
		dp[2][i] = min(dp[1][i - 1], dp[0][i - 1]) + rgb[2][i];
	}

	cout << min(min(dp[0][n - 1], dp[1][n - 1]), dp[2][n - 1]);

	return 0;
}