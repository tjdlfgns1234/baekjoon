#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(a) a.begin(),a.end()
using namespace std;

void solve();

int main(void)
{
	ios::sync_with_stdio(NULL);
	::cout.tie(NULL), cin.tie(NULL);

	solve();

	return 0;
}
void solve() {
	int n, s;
	cin >> n >> s;

	vector <int> arr(n);

	for (auto& i : arr)
		cin >> i;

	int ans = INT_MAX;
	int l = 0, r = 1; 
	int sum = arr[l]+arr[r];

	for (auto i : arr)
		if (i >= s) {
			cout << 1;
			return;
		}

	while (1) {
		if (l >= r)
			break;

		if (sum >= s) {
			ans = min(ans, r-l + 1);
			sum -= arr[l], l++;
		}
		else if (sum < s) {
			if (r == n - 1)
				break;
			r++, sum += arr[r];
		}
	}
	if (ans == INT_MAX)
		cout << 0;
	else
		cout << ans;
}