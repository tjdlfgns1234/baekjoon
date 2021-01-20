#include <bits/stdc++.h>
#define ll long long

using namespace std;
void solve();
int arr[15][15] = { 0 };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int t;
	cin >> t;
	solve();
	while (t--)
	{
		int k,n;
		cin >> k >> n;
		cout << arr[k][n] << '\n';
	}
	return 0;
}
void solve()
{
	int sum = 0;
	for (int i = 1; i < 15; i++)
		arr[0][i] = i;
	for (int i = 1; i < 15; i++)
	{
		sum = 0;
		for (int j = 1; j < 15; j++)
		{
			sum += arr[i - 1][j];
			arr[i][j] = sum;
		}
	}
}