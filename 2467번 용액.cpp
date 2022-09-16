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
	int n;
	cin >> n;

	vector<int> arr(n);

	int a, b;

	for (auto& i : arr)
		cin >> i;

	int l = 0, r = n - 1;
	int sum = INT_MAX, tmp;
	while (1) {
		if (l >= r)
			break;
		tmp = arr[l] + arr[r];
		if (abs(tmp) < abs(sum)) {
			sum = tmp;
			a = arr[l], b = arr[r];
			if (tmp < 0)
				l++;
			else
				r--;
		}
		else if (abs(tmp) >= abs(sum))
			if (tmp < 0)
				l++;
			else
				r--;
		else if (abs(tmp) == 0) {
			a = arr[l], b = arr[r];
			break;
		}
	}

	cout << a << " " << b;
}