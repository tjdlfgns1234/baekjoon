#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

// Beware of MAX & MIN value!


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector <int> arr(n);
	for (auto& i : arr)
		cin >> i;

	int ans = -10001;
	int sum = 0;
	int idx = 0;
	for (int i = 0; i < k; i++)
		sum += arr[i];
	while (1)
	{
		ans = max(ans, sum);

		if (idx + k >= n)
			break;
		sum -= arr[idx];
		sum += arr[idx + k];
		idx++;
	}
	cout << ans;

	return 0;
}