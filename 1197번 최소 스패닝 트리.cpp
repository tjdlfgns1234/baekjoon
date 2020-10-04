#include <iostream>
#include <algorithm>
#include <vector>

#define SIZE 10000

using namespace std;

struct  EDGE {
	int x, y, w;
};

typedef struct EDGE Edge;
bool compare(Edge a, Edge b)
{
	return a.w < b.w;
}

int parent[SIZE + 1];
vector <Edge> edges;
long long result = 0;
void kruskal();
void init();
int _parent(int x);
bool _union(int x, int y);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int v, e;
	int x, y, w;
	cin >> v >> e;
	// edge을 입력 받을때마다 정렬 O(eloge)

	for (int i = 0; i < e; i++)
	{
		cin >> x >> y >> w;
		edges.push_back({x,y,w});
	}

	init();
	sort(edges.begin(), edges.end(), compare);
	kruskal();

	cout << result;

	return 0;
}
void kruskal()
{
	for (unsigned int i = 0; i < edges.size(); i++)
	{
		if (_union(edges[i].x, edges[i].y))
		{
			result += edges[i].w;
		}
	}
}
void init()
{
	for (int i = 0; i < SIZE + 1; i++)
		parent[i] = i;
}
int _parent(int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = _parent(parent[x]);
}
bool _union(int x, int y)
{
	x = _parent(x);
	y = _parent(y);
	if (x == y)
		return false;
	else if (x < y)
		parent[y] = x;
	else
		parent[x] = y;
	return true;
}