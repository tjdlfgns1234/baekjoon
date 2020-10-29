#include <iostream>
#include <algorithm>

#define SIZE 300000

using namespace std;
int parent[SIZE + 1];

void init();
int find(int v);
bool _union(int v, int u);


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int x,y;
	int ans[2] = { 0 };
	int idx = 0;
	cin >> n;
	init();
	for (int i = 0; i < n-2; i++)
	{
		cin >> x >> y;
		_union(x, y);
	}
	for (int i = 1; i < n + 1; i++)
	{
		if (parent[i] == i)
			ans[idx++] = i;
	}
	cout << ans[0] << " " << ans[1];


	return 0;
}
void init()
{
	for (int i = 0; i < SIZE + 1; i++)
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
bool _union(int v, int u)
{
	v = find(v), u = find(u);

	if (v == u)
		return false;
	else if(v>u)
		parent[u] = v;
	else
		parent[v] = u;
	return true;
}