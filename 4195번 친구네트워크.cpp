#include <algorithm>
#include <iostream>
#include <map>
#define SIZE 200000

using namespace std;
map<string, int>mp;
int parent[SIZE + 1];
int count[SIZE + 1];
void init(int n);
int find(int x);
void _union(int x, int y);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	int f;
	int cnt;
	string tmp, tmp2;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cnt = 1;
		cin >> f;
		init(f * 2);
		for (int j = 0; j < f; j++)
		{

			cin >> tmp >> tmp2;
			if (mp.count(tmp) == 0)
				mp.insert(make_pair(tmp, cnt++));
			if (mp.count(tmp2) == 0)
				mp.insert(make_pair(tmp2, cnt++));
			_union(mp[tmp], mp[tmp2]);
			cout << ::count[find(mp[tmp])] << "\n";
		}
		mp.erase(mp.begin(), mp.end());
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
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find(parent[x]);
}
void _union(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x == y)
		return;
	else if (x > y)
		parent[y] = x, ::count[x] += ::count[y];
	else if (x < y)
		parent[x] = y, ::count[y] += ::count[x];
	return;
}