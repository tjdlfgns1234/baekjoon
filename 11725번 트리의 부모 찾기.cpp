#include <algorithm>
#include <iostream>
#include <list>
#include <stack>

#define SIZE 100000

using namespace std;
int ans[SIZE + 1] = { 0 };
bool visit[SIZE + 1] = { 0 };
list <int> *graph;
void dfs(int n);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);

	int n;
	int x, y;
	cin >> n;
	graph = new list<int>[n + 1];
	for (int i = 0; i < n-1; i++)
	{
		cin >> x >> y;
		graph[x].push_front(y);
		graph[y].push_front(x);
	}
	dfs(n);
	for (int i = 2; i < n + 1; i++)
		cout << ans[i] << "\n";

	return 0;
}
void dfs(int n)
{
	stack <int> s;
	list<int>::iterator it;
	s.push(1);
	visit[1] = true;
	int now;
	while (!s.empty())
	{
		now = s.top();
		s.pop();
		for (it = graph[now].begin(); it != graph[now].end(); it++)
			if (!visit[*it])
				visit[*it] = true,ans[*it]=now,s.push(*it);
	}
}