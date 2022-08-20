#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define INF 987654321
using namespace std;

// min max값에 유의하자

void solve();

int main(void)
{
	ios::sync_with_stdio(NULL);
	::cout.tie(NULL), ::cin.tie(NULL);

	solve();

	return 0;
}
void solve() {

	int n;
	cin >> n;

	vector<int> cost(n + 1);
	vector<int> memo(n + 1);
	queue<int> q;

	for (int i = 0; i < n + 1; i++)
		cost[i] = INF, memo[i] = INF;

	cost[n] = 0;
	q.push(n);

	while (!q.empty()) {

		int s = q.front();
		q.pop();

		if (s == 1)
			continue;
		else if (s == 0)
			continue;

		if (s % 3 == 0)
			if (s/3 != 0)
				if( cost[s] + 1 < cost[s / 3])
					q.push(s / 3), cost[s / 3] = cost[s] + 1, memo[s/3]=s;

		if (s % 2 == 0)
			if (s/2 != 0)
				if (cost[s] + 1 < cost[s / 2])
					q.push(s / 2), cost[s / 2] = cost[s] + 1, memo[s / 2] = s;

		if (s - 1 != 0)
			if (cost[s] + 1 < cost[s - 1])
				q.push(s - 1), cost[s - 1] = cost[s] + 1, memo[s-1] = s;
	}

	::cout << cost[1] << "\n";

	stack <int> ans;
	int s = 1;

	if (cost[1] != 0) {
		while (1) {

			if (memo[s] != n)
				ans.push(s), s = memo[s];
			else {
				ans.push(s), ans.push(n);
				break;
			}
		}
	}
	else {
		ans.push(1);
	}

	while (!ans.empty())
		::cout << ans.top() << " ", ans.pop();
}