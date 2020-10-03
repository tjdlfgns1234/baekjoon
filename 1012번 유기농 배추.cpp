#include <iostream>
#include <algorithm>

using namespace std;
int count;
int arr[50][50] = { 0 };
int visit[50][50] = { 0 };
void dfs(int m, int n, int x, int y);
void init(int m, int n);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	int m, n, k;
	int x, y;
	cin >> t;

	for (int j = 0; j < t; j++)
	{
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			arr[x][y] = 1;
		}
		for(int k = 0; k<m;k++)
			for(int l = 0; l < n;l++)
				if(!visit[k][l] && arr[k][l])
					dfs(m, n, k, l),::count++;
		cout << ::count << "\n";
		init(m, n);
	}
	return 0;
}
void init(int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = 0, visit[i][j] = 0;
	::count = 0;
}
void dfs(int m, int n, int x, int y)
{
	visit[x][y] = 1;
	int tmp[4] = { 0,0,-1,1 };	// 이동방향을 위한 배열
	for (int i = 0; i < 4; i++)
	{
		int nx = x + tmp[i];
		int ny = y + tmp[3 - i];
		if ( nx<m &&ny <n && nx>-1 &&ny >-1)
		{
			if (!visit[nx][ny])
			{
				visit[nx][ny] = 1;
				if (arr[nx][ny])
					dfs(m, n, nx, ny);
			}
		}
	}
	return;
}