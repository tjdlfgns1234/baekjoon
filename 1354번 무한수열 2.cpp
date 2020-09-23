#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int count = 0;
long long arr[1] = { 1 };

unordered_map<long long, long long> dp;

long long formula(long long n, long long p, long long q, long long x, long long y);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	long long p, q;
	long long x, y;

	cin >> n;
	cin >> p;
	cin >> q;
	cin >> x;
	cin >> y;
	cout << formula(n, p, q, x, y);

	return 0;
}
long long formula(long long n, long long p, long long q, long long x, long long y)
{
	if (n <= 0)	//brute force
	{
		return arr[0];
	}
	else if (dp[n])
	{
		return dp[n];
	}
	long long tmp, tmp2;

	tmp = formula((n / p) - x, p, q, x, y);
	tmp2 = formula((n / q) - y, p, q, x, y);
	dp[n] = tmp + tmp2;
	return dp[n];
}