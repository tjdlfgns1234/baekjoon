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
	int n, m;
	cin >> n >> m;

	vector<int> arr(n);
	for (auto& i : arr)
		cin >> i;

	sort(all(arr));

	int l = 0, r = 0;
	int sum = 0, ans = INT_MAX;
	while (1) {
		if (l >= n || r>= n )
			break;
		sum = abs(arr[l] - arr[r]);

		if (sum > m) {
			ans = min(sum, ans);
			r++;
		}
		else if (sum < m)
			l++;
		else {
			ans = sum;
			break;
		}
	}

	cout << ans;
}