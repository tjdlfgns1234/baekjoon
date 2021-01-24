#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n,m;
		cin >> n >> m;
		int ans = 0;
		int* arr = new int[n];
		priority_queue <int, vector<int>> pq;
		queue <int> q;
		for (int i = 0; i < n; i++)
			cin >> arr[i],pq.push(arr[i]),q.push(i);

		while (!pq.empty())
		{
			if (pq.top() == arr[q.front()])
				if (q.front() == m)
				{
					ans++;
					break;
				}
				else
					pq.pop(), q.pop(),ans++;
			else
				q.push(q.front()), q.pop();
		}
		cout << ans << '\n';
	}
	return 0;
}