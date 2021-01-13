#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		string n;
		cin >> n;
		int size = n.length();
		if (size % 2 == 1)
			cout << "NO" << "\n";
		else if (n[size - 1] == '(' || n[0] == ')')
			cout << "NO" << "\n";
		else
		{
			int cnt = 0;
			int a = 0, b = 0;
			for (auto i : n)
			{
				if (i == '(')
					a++, cnt++;
				else if (i == ')')
					b++, cnt--;

				if (cnt < 0)
					break;
			}
			if (a != b)
				cnt = -1;
			if (cnt < 0)
				cout << "NO" << '\n';
			else
				cout << "YES" << "\n";
		}
	}
	return 0;
}