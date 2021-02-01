#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	ll n;
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		ll tmp;
		cin >> tmp;
		sum += tmp;
	}
	sum = sum - ((n) * (n-1)) / 2;

	cout << sum;

	return 0;
}