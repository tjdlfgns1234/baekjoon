#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(a) a.begin(),a.end()
using namespace std;

void solve();

int main(void)
{
	ios::sync_with_stdio(NULL);
	::cout.tie(NULL), ::cin.tie(NULL);

	solve();

	return 0;
}
void solve() {
	int n;
	cin >> n;

	vector<int> arr(n);

	for (auto& i : arr)
		cin >> i;

	int l = arr[0], r = arr[1];

	for (int i = 2; i < n; i++)
		if (l == r)
			l += arr[i];
		else
			if (l < r)
				l += arr[i];
			else
				r += arr[i];

	int weight = abs(l - r);
	
	if (weight == 0) {
		cout << 0;
		return;
	}
	
	int ans = 0;
	int w[7] = { 100, 50, 20, 10, 5, 2, 1 };

	for (int i = 0; i < 6; i++) {
		ans += weight / w[i];
		weight = weight % w[i];
	}
	ans += weight;
	cout << ans;
}