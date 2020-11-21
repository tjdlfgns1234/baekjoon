#include <iostream>
#include <algorithm>

#define SIZE 2000

using namespace std;

// 기존의 관계를 꺠트려야 모순!

int like[SIZE + 1];
int hate[SIZE + 1];
void init(int n);
int find(int x);
void _union(int x, int y);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	init(n);
	int a, b;
	bool check = false;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		_union(a, b);
		_union(b, a);
		if (find(hate[a]) == find(hate[b]))
			check = true;
	}

	if (!check)
		cout << 1;
	else
		cout << 0;

	return 0;
}
void init(int n)
{
	for (int i = 1; i < n + 1; i++)
		hate[i] = -1,like[i]=i;
}
int find(int x)
{
	if (x == -1)
		return x;
	else if (like[x] == x)
		return x;
	else
		return like[x] = find(like[x]);
}
void _union(int x, int y)
{
	x = find(x);
	int enemy = find(hate[y]);

	if (enemy == -1)
	{
		hate[y] = x; enemy = x;
	}
	like[x] = enemy;
}