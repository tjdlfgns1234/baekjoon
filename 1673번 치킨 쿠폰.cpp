#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(NULL);
	cout.tie(NULL), cin.tie(NULL);

	int n, k;
	while (1)
	{
		cin >> n >> k;
		if (cin.eof())
			break;
		long long voucher = 0;
		long long ans = 0;
		while (1)
		{
			ans += n;
			voucher += n;
			n = voucher / k;
			voucher = voucher % k;
			if (n == 0)
				break;
		}
		cout << ans << '\n';
	}

	return 0;
}