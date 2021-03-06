﻿#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int t;
	cin >> t;
	int idx = 1;
	while (t--)
	{
		int n,k;
		cin >> n >> k;
		vector <int> arr(n);
		for (auto& i : arr)
			cin >> i;
		sort(arr.begin(), arr.end());
		int ans = 0;
		int uidx = n-1;
		int lidx = 0;
		int low = arr[lidx];
		int upp = arr[uidx];

		while (1)
		{
			if (lidx >= uidx)
				break;
			if (low + upp == k)
			{
				ans++;
				lidx++;
				low = arr[lidx];
				uidx--;
				upp = arr[uidx];
			}
			else if (low + upp < k)
			{
				// 합 증가
				lidx++;
				low = arr[lidx];
			}
			else if(low + upp > k)
			{
				// 합 감소
				uidx--;
				upp = arr[uidx];
			}
		}
		cout <<"Case #" << idx << ": " <<ans << '\n';
		idx++;
	}

	return 0;
}