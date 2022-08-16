#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(a) a.begin(),a.end()
using namespace std;

void ans();
void bfs(int start);

vector<vector<int>> adj;
vector <bool> visit;
vector <int> cost;

int main(void)
{
	ios::sync_with_stdio(NULL);
	cout.tie(NULL), cin.tie(NULL);

	ans();

	return 0;
}
void ans() {
	
	int n, m;
	cin >> n >> m;

	::adj.resize(n + 1);
	::visit.resize(n + 1);
	::cost.resize(n + 1);

	for (auto& i : ::cost)
		i = 0;

	for (int i = 0; i < n +1; i ++)
		::visit[i] = false;

	int x, y;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int start = 1;
	bfs(start);
}
void bfs(int start)
{
	queue<int> q;
	q.push(start);
	int front;
	while (1) {
		if (q.empty()) // 탐색이 필요없다면 반복문 탈출
			break;
		front = q.front(), q.pop(); // 다음 도착지
		  
		if (::visit[front])  // 이미 방문을 헀다면 pass
			continue;

		::visit[front] = true; // 방문 처리
		for (unsigned int i = 0; i < adj[front].size(); i++)
		{
			if (!::visit[adj[front][i]]) { // 방문안했다면
				q.push(::adj[front][i]); // 다음 도착지를 q에 넣음
				if(::cost[::adj[front][i]]== 0) // 값의 업데이트 확인
					::cost[::adj[front][i]] = cost[front] + 1;
			}
		}
	}

	int ans1 = 0, cur = 0, num = 0;

	for (int i = 1; i < ::cost.size(); i++) {
		if (cur < ::cost[i])
			ans1 = i, cur = ::cost[i];
	}
	for (int i = 1; i < ::cost.size(); i++) {
		if (cur == ::cost[i])
			num++;
	}

	cout << ans1 << " " << cur<< " " << num;
}