#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void)
{
	ios::sync_with_stdio(NULL);
	cout.tie(NULL), cin.tie(NULL);

	int n;
	cin >> n;
	vector <int> house(n);
	int sum = 0;
	for (int i = 0;i<n;i++)
		cin >> house[i],sum+=house[i];

	sort(house.begin(), house.end());
	cout << house[(n-1)/2];

	return 0;
}