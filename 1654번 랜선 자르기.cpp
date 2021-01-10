#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void)
{
	ios::sync_with_stdio(NULL);
	cout.tie(NULL), cin.tie(NULL);

	int k, n;
	cin >> k >> n;

	ll* arr = new ll[k];
	ll sum = 0LL;
	for (int i = 0; i < k; i++)
		cin >> arr[i], sum +=arr[i];

	ll upper = sum / ((ll)n) + 1;
	ll lower = 0;
	ll mid = (upper + lower)/2;
	int ans = 0;
	ll Max = 0;
	while (1)
	{
		ans = 0;
		for (int i = 0; i < k; i++)
			if (arr[i] >= mid)
				ans += arr[i] / mid;
			else
				ans += 0;

		if (ans >= n)
			lower = mid, Max = max(mid, Max);
		else if (ans < n)
			upper = mid;
		
		if (upper - lower <= 1)
			break;

		mid = (upper + lower) / 2;
	}

	cout << Max;
	return 0;
}