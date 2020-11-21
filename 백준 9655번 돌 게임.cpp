#include <iostream>
#include <algorithm>
#define SIZE 1000
using namespace std;

bool dp[SIZE + 1] = { false };
bool rockgame(long long n);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n;

	if (!rockgame(n))	// 선공 승
		cout << "SK";
	else
		cout << "CY";

	return 0;
}
bool rockgame(long long n)
{
	dp[1] = false;
	dp[2] = true;
	dp[3] = false; 
	bool result = true;
	for (long long i = 4; i < n + 1; i++)
		if (dp[i - 1] != false || dp[i - 3] != false)
			dp[i] = false;
		else
			dp[i] = true;
	return dp[n];
}