#include <iostream>
#include <algorithm>
#include <vector>

// map은 key값이 중복되는지 확인을 해주어야 한다.
#define SIZE 200

int map[SIZE + 1][SIZE + 1];

using namespace std;

int parent[SIZE+1];
void init();
int _parent(int x);
void _union(int x, int y);
bool travel(int n,int m);
bool check(int x, int y);
int* query;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	query = new int[m];

	for (int j = 0; j < m; j++)
		cin >> query[j];

	init();

	if (travel(n,m))
		cout << "YES";
	else
		cout << "NO";
	

	return 0;
}
bool travel(int n,int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (map[i][j])
				_union(i, j);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			if(i!=j)
				if (!check(query[i]-1, query[j]-1))
					return false;

	return true;
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
void _union(int x, int y)
{
	x = _parent(x);
	y = _parent(y);
	if (x == y)
		return;
	else if (x < y)
		parent[y] = x;
	else
		parent[x] = y;
	return;
}
bool check(int x, int y)
{
	x = _parent(x);
	y = _parent(y);
	if (x == y)
		return true;
	return false;
}