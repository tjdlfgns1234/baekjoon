#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> adj;
vector<bool> visit;

void dfs(int start);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

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

	dfs(1);

	return 0;
}
void dfs(int start)
{
	int count = 0;
	stack <int> s;
	s.push(start);

	while (!s.empty())
	{
		int key = s.top();
		s.pop();
		if (visit[key])
			continue;

		visit[key] = true;
		count++;

		for (unsigned int i = 0; i < adj[key].size(); i++)
		{
			if (!visit[adj[key][i]])
			{
				s.push(adj[key][i]);
			}
		}
	}
	if (count != 0)
		cout << count - 1;
	else
		cout << count;
}