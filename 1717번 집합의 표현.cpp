#include <iostream>
#include <algorithm>

#define SIZE 1000000

using namespace std;
int parent[SIZE+1];

void init();
int find(int v);
void _union(int v,int u);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	int a, b, c;
	init();
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		if (a == 0)
			_union(b, c);
		else if (a == 1)
			if (find(b) == find(c))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
	}


	return 0;
}
void init()
{
	for (int i = 0; i < SIZE+1; i++)
	{
		parent[i] = i;
	}
}
int find(int v)
{
	if (v == parent[v])
		return v;

	return parent[v] = find(parent[v]);
}
void _union(int v, int u)
{
	v = find(v), u = find(u);

	if (v == u)
		return;
	parent[v] = u;
}