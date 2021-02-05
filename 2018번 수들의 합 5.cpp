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

	int n;
	cin >> n;
	int idx = 1;

	int left = 1;
	int right = 1;
	int ans = 0;
	int sum = left;
	while (1)
	{
		if (left == n)
		{
			ans++;
			break;
		}
		else if (sum == n)
		{
			ans++;
			right++;
			sum += right;
		}
		else if (sum < n)
		{
			right++;
			sum += right;
		}
		else
		{
			sum -= left;
			left++;
		}
		
	}
	cout << ans;

	return 0;
}