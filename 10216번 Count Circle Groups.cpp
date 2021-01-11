#include <bits/stdc++.h>
#define ll long long
using namespace std;
int parent[3000];
struct point {
	int x, y, r;
};

int dist(point src, point dest)
{
	return ((src.x - dest.x) * (src.x - dest.x)) + ((src.y - dest.y) * (src.y - dest.y));
}

void makeset(int n)
{
	for (int i = 0; i < n; i++)
		parent[i] = i;
}

int find(int a)
{
	if (a == parent[a])
		return a;

	return parent[a]= find(parent[a]);
}

void _union(int a, int b)
{
	a = find(a), b = find(b);
	if (a == b)
		return;
	else if (a > b)
		parent[a] = b;
	else
		parent[b] = a;
}

int main(void)
{
	ios::sync_with_stdio(NULL);
	cout.tie(NULL), cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		makeset(n);
		point* p = new point[n];
		for (int i = 0; i < n; i++)
			cin >> p[i].x >> p[i].y >> p[i].r;
		
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
				if (dist(p[i], p[j]) <= (p[i].r + p[j].r)*(p[i].r + p[j].r))
					_union(i, j);
		int ans = 0;
		for (int i = 0; i < n; i++)
			if (parent[i] == i)
				ans++;
		cout << ans << '\n';
	}

	return 0;
}