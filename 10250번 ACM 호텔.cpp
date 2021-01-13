#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int h, w, n;
		cin >> h >> w >> n;
		if(n%h !=0)
			cout << (n / h + 1) + (n % h) * 100 << '\n';
		else
			cout << (n / h) + h*100 << '\n';
	}
	return 0;
}