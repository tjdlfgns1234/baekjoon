#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> adj;
vector<bool> visit;

int dfs(int start);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count = 0;
	int n, m;
	int s, e;
	cin >> n >> m;

	adj.resize(n + 1);
	visit.resize(n + 1);

	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}
	for (int i = 1; i < n + 1; i++) {
		if(!visit[i])
			count += dfs(i);
	}
	cout << count;

	return 0;
}
int dfs(int start)
{
	stack <int> s;
	s.push(start);

	while (!s.empty())
	{
		int key = s.top();
		s.pop();
		if (visit[key])
			continue;

		visit[key] = true;

		for (unsigned int i = 0; i < adj[key].size(); i++)
		{
			if (!visit[adj[key][i]])
			{
				s.push(adj[key][i]);
			}
		}
	}
	return 1;
}