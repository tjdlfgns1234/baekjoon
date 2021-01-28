#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int q;
	cin >> q;
	while (q--)
	{
		int n;
		cin >> n;
		bool chk = false;
		if (n != 1)
		{
			while (1)
			{
				int remain = n % 2;
				n = n / 2;
				if (remain != 0)
					break;
				else if (n == 1)
				{
					chk = true;
					break;
				}
			}
		}
		else
			chk = true;
		cout << chk << '\n';

	}
	return 0;
}