#include <algorithm>
#include <iostream>
#include <map>
#define SIZE 500
using namespace std;

int parent[SIZE + 1];
int count[SIZE + 1];
void init(int n);
int find(int x);
void _union(int x, int y);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int x, y;
	int result;
	int idx = 1;
	while (1)
	{
		result = 0;
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		init(n);
		for (int i = 0; i < m; i++)
			cin >> x >> y,_union(x,y);
		
		for (int i = 1; i < n + 1; i++)
		{
			if (::count[i] != -1)
				result++;
		}
		if (result == 0)
		{
			cout << "Case " << idx << ": No trees." << '\n';
		}
		else if (result == 1)
		{
			cout << "Case " << idx << ": There is one tree." << '\n';
		}
		else
		{
			cout << "Case " << idx << ": A forest of "<<result<<" trees." << '\n';
		}
		idx++;
	}

	return 0;
}
void init(int n)
{
	for (int i = 1; i < n + 1; i++)
		parent[i] = i;
	for (int i = 1; i < n + 1; i++)
		::count[i] = 1;
}
int find(int x)
{
	if (parent[x]==x)
		return x;
	else
		return parent[x] = find(parent[x]);
}
void _union(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x == y)
		::count[x] = -1, ::count[y] = -1;
	else if (x > y)
		parent[y] = x, ::count[y] = -1;
	else if (x < y)
		parent[x] =y, ::count[x] = -1;
	return;
}