#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define maxVal 100000
using namespace std;

int main(void)
{
	ios::sync_with_stdio(NULL);
	cout.tie(NULL), cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	if (n == k)
		cout << 0;
	else if (n > k)
		cout << n - k;
	else if (n < k)
	{
		int* arr = new int[2 * maxVal + 1];
		for (int i = 0; i < 2 * maxVal + 1; i++)
			arr[i] = 0;
		for (int i = 0; i < n; i++)
			arr[i] = n - i;
		int tmp = n;
		int cnt = 0;
		int cnt2 = 0;
		while (1)
		{
			cnt = cnt2;

			for (int i = min(2 * tmp, 2 * maxVal); i > tmp; i--)
				arr[i] = ++cnt;
			if (tmp == 0 || tmp * 2 > 2 * maxVal)
				break;
			tmp = 2 * tmp;
			cnt2++;

		}
		if (n == 0)
			for (int i = 0; i < 2 * maxVal + 1; i++)
				arr[i] = i;
		tmp = 21;
		while (tmp--)
		{
			for (int i = 1; i < 2 * maxVal + 1; i++)
				arr[i] = min(min(min(arr[i - 1] + 1, arr[i / 2] + 1 + i % 2), arr[i]), arr[min((i + 1), 2 * maxVal)] + 1);
		}
		cout << arr[k];
	}

	return 0;
}