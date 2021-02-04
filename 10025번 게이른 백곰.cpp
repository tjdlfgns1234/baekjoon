#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int xcnt[1000001] = { 0 }; // 양동이의 모든 위치는 다름.

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);


	int n, k;
	cin >> n >> k;
	int x, g;
	for (int i = 0; i < n; i++)
		cin >> g >> x, xcnt[x] = g;

	int ans = 0;
	if (k < 500000)
	{
		int sum = 0;
		for (int i = 0; i < 2*k+1; i++)
		{
			sum += xcnt[i];
		}
		ans = max(ans, sum);
		for (int i = k+1; i+k+1< 1000000+1; i++)
		{
			sum -= xcnt[i - k -1];
			sum += xcnt[i + k];
			ans = max(ans,sum);
		}
	}
	else
	{
		for (int i = 0; i < 1000000 + 1; i++)
			ans += xcnt[i];
	}
	cout << ans;

	return 0;
}