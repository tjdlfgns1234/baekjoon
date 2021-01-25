#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int arr[500][500];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// BOJ 18111번 마인 크래프트
	// 최댓값 설정에 유의하자!
	int n, m, b;
	cin >> n >> m >> b;
	int one= 0, two = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	int t= 1934567890,h = 0;

	for (int k = 0; k < 256+1; k++)
	{
		one = 0, two = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (arr[i][j] < k)
					two += k - arr[i][j];
				else if (arr[i][j] > k)
					one += arr[i][j] - k;
				else
					continue;
		if (two <= b + one)
		{
			if (t > 2*one + two)
				t = 2*one +two, h = k;
			else if (t == one * 2 + two)
				h = max(h, k);
		}
	}

	cout << t << ' ' << h;

	return 0;
}