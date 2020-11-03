﻿#include <iostream>
#include <algorithm>
#define SIZE 10000
using namespace std;
int dp[1001][SIZE + 1] = { 0 };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, t;

	cin >> t >> n;
	int* w = new int[n + 1];
	int* v = new int[n + 1];

	for (int i = 1; i < n + 1; i++)
		cin >> v[i] >> w[i];


	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < t + 1; j++)
			if (j - w[i] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			else
				dp[i][j] = dp[i - 1][j];

	cout << dp[n][t];

	return 0;
}