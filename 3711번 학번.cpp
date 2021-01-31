#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int ans = 1;
		int arr[300];
		map <int, int> mp;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		while (1)
		{
			for (int i = 0; i < n; i++)
				if (mp.count(arr[i] % ans) == 0)
					mp.insert({ arr[i]%ans,1 });
				else
					break;
			if (mp.size() == n)
			{
				break;
			}
			mp.clear();
			ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}