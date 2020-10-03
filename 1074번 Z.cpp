#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int r, c;
int cnt = 0;
void Z(int n,int x, int y);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int tmp = 1;
	cin >> n >> r>>c;

	for (int i = 0; i < n; i++)
	{
		tmp *=2;
	}
	Z(tmp, 0, 0);

	return 0;
}
void Z(int n, int x, int y)
{
	if (n <= 2)
	{
		if (x == c && y == r)
		{
			cout << cnt;
			return;
		}
		cnt++;
		if ((x + 1) == c && y == r)
		{
			cout << cnt;
			return;
		}
		cnt++;
		if (x == c && (y + 1) == r)
		{
			cout << cnt;
			return;
		}
		cnt++;
		if ((x + 1) == c && (y + 1) == r)
		{
			cout << cnt;
			return;
		}
		cnt++;
		return;
	}
	Z(n / 2, x, y);
	Z(n / 2, x + n/2, y );
	Z(n / 2, x, y + n/2 );
	Z(n / 2, x + n/2, y + n/2);

	return;
}