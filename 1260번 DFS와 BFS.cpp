#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<bool> visit;

void dfs(int start);
void bfs(int start);


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, start;
	int s, e;
	cin >> n >> m >> start;

	adj.resize(n + 1);
	visit.resize(n + 1);

	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	dfs(start);


	bfs(start);

	return 0;
}
void dfs(int start)
{
	int key = start;
	stack <int> s;
	s.push(key);

	while (!s.empty())
	{
		int key = s.top();
		s.pop();
		if (visit[key])
			continue;

		visit[key] = true;
		cout <<  key << " ";

		sort(adj[key].begin(), adj[key].end(), greater<int>());
		for (unsigned int i = 0; i < adj[key].size(); i++)
		{
			if (!visit[adj[key][i]])
				s.push(adj[key][i]);
		}
	}
	cout << endl;
}
void bfs(int start)
{
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		if (!visit[front])
			continue;

		visit[front] = false;
		cout << front << " ";

		sort(adj[front].begin(), adj[front].end());
		for (unsigned int i = 0; i < adj[front].size(); i++)
		{
			q.push(adj[front][i]);
		}
	}
}