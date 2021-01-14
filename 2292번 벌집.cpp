#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	int s = 6;
	int ans = 1;

	while (1)
	{
		if (n <= 3*ans*ans - 3*ans + 1)
			break;
		ans++;
	}
	if (n == 1)
		cout << 1;
	else
		cout << ans;

	return 0;
}