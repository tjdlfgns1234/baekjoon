#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int count = 0;
string arr[25][26];
bool visit[25][25] = { 0 };
vector<int> result;
void dfs(int m, int n, int x, int y);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	cin.ignore(7, '\n');
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n+1; j++)
			arr[i][j]= cin.get();


	for (int k = 0; k < n; k++)
		for (int l = 0; l < n; l++)
			if (!visit[k][l] && arr[k][l]=="1")
			{
				dfs(n, n, k, l);
				result.push_back(::count);
				::count = 0;
			}

	sort(result.begin(), result.end());

	cout << result.size() << "\n";
	for (unsigned int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}

	return 0;
}
void dfs(int m, int n, int x, int y)
{
	visit[x][y] = true;
	::count++;
	int tmp[4] = { 0,0,-1,1 };	// 이동방향을 위한 배열
	for (int i = 0; i < 4; i++)
	{
		int nx = x + tmp[i];
		int ny = y + tmp[3 - i];
		if (nx<m && ny <n && nx>-1 && ny >-1)
		{
			if (!visit[nx][ny])
			{
				visit[nx][ny] = 1;
				if (arr[nx][ny]=="1")
					dfs(m, n, nx, ny),::count;
			}
		}
	}
	return;
}