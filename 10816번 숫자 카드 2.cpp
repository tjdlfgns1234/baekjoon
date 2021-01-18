#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> arr(n);
	int tmp;
	for (int i = 0; i < n; i++)
		cin >> tmp, arr[i] = tmp;
	sort(arr.begin(), arr.end());
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> tmp, cout << upper_bound(arr.begin(), arr.end(), tmp) - lower_bound(arr.begin(), arr.end(), tmp) << ' ';

	return 0;
}
