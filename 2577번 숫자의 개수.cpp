#include <bits/stdc++.h>
#define ll long long
using namespace std;

int arr[10] = { 0 };

int main(void)
{
	ios::sync_with_stdio(NULL);
	cout.tie(NULL), cin.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;
	int sum = a * b * c;

	string s = to_string(sum);
	
	int n = s.length();
	for (int i = 0; i < n; i++)
		arr[s[i] - '0' ]++;

	for (auto i : arr)
		cout << i << '\n';

	return 0;
}