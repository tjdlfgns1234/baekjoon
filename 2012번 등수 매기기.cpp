#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void)
{
	ios::sync_with_stdio(NULL);
	cout.tie(NULL), cin.tie(NULL);

	int n;
	cin >> n;
	vector <int> angry(n);
	ll sum = 0;
	for (int i = 0;i<n;i++)
		cin >> angry[i];

	sort(angry.begin(), angry.end());
	for (int i = 0; i < n; i++)
		sum += abs(angry[i] - (i + 1));

	cout << sum;

	return 0;
}