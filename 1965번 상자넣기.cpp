#include <algorithm>
#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int* arr;
	int* dp;
	int result = 0;
	cin >> n;
	arr = new int[n];
	dp = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i],dp[i] = 1;

	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < j; i++)
		{
			if (arr[i] < arr[j] && dp[j] < dp[i]+1)
			{
				dp[j] = dp[i] + 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (dp[i] > result)
			result = dp[i];
	}

	cout << result;

	return 0;
}