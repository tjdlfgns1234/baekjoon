#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	/*int t;
	cin >> t;
	while (t--)
	{

	}*/

	ll n,k;
	cin >> n >> k;
	vector <ll> arr(n);
	for (auto& i : arr)
		cin >> i;

	ll left = arr[0];
	ll right = arr[0];
	int lidx = 0;
	int ridx = 0;
	ll ans = 0;
	ll sum = left;
	if (sum == k)
	{
		ans++;
		ridx++;
		if (ridx == n)
		{
			cout << ans;
			return 0;
		}
		right = arr[ridx];
		sum += right;
	}
	while (1)
	{
		if (sum == k)
		{
			sum -= left;
			ans++;
			lidx++;
			if (lidx >= n)
				break;
			left = arr[lidx];
		}
		else if (sum < k)
		{
			if (ridx < n - 1)
			{
				ridx++;
				right = arr[ridx];
				sum += right;
			}
			else
			{
				break;
			}
		}
		else
		{
			sum -= left;
			lidx++;
			if (lidx >= n)
				break;
			left = arr[lidx];
		}
		
	}
	cout << ans;

	return 0;
}