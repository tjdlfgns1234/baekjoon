#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#define MAX 50000
using namespace std;
list<int>* graph;
int Lca(int v, int w);
int depth[MAX + 1] = { 0 };
bool visit[MAX + 1] = { false };
void bfs(); // depth 확인

/*
1) DFS를 이용하여 각 정점들의 깊이를 구한다.
2) 두 노드의 깊이가 같도록 한다음 두노드가 만나면 답이고 아니면 두 노드중 아무거나 깊이를 올려서 다시 앞의 과정을 반복한다.
*/


int main(void)
{
	ios::sync_with_stdio(NULL);
	cout.tie(NULL), cin.tie(NULL);
	int n, m;
	cin >> n;
	graph = new list<int>[n + 1];
	depth[1] = 1;
	for (int i = 0; i < n - 1; i++)
	{
		int v, w;
		cin >> v >> w;
		graph[v].push_front(w);
		graph[w].push_front(v);
	}
	bfs();
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int v, w;
		cin >> v >> w;
		cout << Lca(v, w) << '\n';
	}

	return 0;
}
void bfs() // depth 확인
{
	list<int>::iterator it;
	stack <int> s;
	s.push(1);
	while (!s.empty())
	{
		int start = s.top();
		s.pop();
		visit[start] = true;
		for (it = graph[start].begin(); it != graph[start].end(); it++)
		{
			if (!visit[*it])
			{
				depth[*it] = depth[start] + 1;
				s.push(*it);
			}
		}
	}
}
int Lca(int v, int w)
{
	list<int>::iterator it;
	int st1 = v, st2 = w;
	while (1)
	{
		if (depth[st1] > depth[st2])
		{
			while (depth[st1] != depth[st2])
			{
				for (it = graph[st1].begin(); it != graph[st1].end(); it++)
				{
					if (depth[*it] < depth[st1])
					{
						st1 = *it;
						break;
					}
				}
			}
		}
		else if (depth[st1] > depth[st2])
		{
			while (depth[st1] != depth[st2])
			{
				for (it = graph[st2].begin(); it != graph[st2].end(); it++)
				{
					if (depth[*it] < depth[st2])
					{
						st2 = *it;
						break;
					}
				}
			}
		}
		else
			if (st1 == st2)
				return st2;
			else if (st1 == 1 || st2 == 1)
			{
				return 1;
			}
			else
			{
				for (it = graph[st2].begin(); it != graph[st2].end(); it++)
				{
					if (depth[*it] < depth[st2])
					{
						st2 = *it;
						break;
					}
				}
			}
	}
}