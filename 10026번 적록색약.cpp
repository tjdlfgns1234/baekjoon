#include <iostream>
#include <algorithm>
#define SIZE 100
using namespace std;

void normal(int n, int x, int y, const char flag);
void color_blindness(int n, int x, int y, const char flag);

int ncnt = 0;
int ccnt = 0;

bool visit[SIZE][SIZE];
bool cvisit[SIZE][SIZE];
char arr[SIZE + 1][SIZE + 1];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	
	cin >> n;
	cin.ignore(n, '\n');

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n+1; j++)
		{
			arr[i][j]= cin.get();
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j])
			{
				ncnt++;
				normal(n, i, j,arr[i][j]);
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!cvisit[i][j])
			{
				ccnt++;
				color_blindness(n, i, j, arr[i][j]);
			}
		}
	}
	cout << ncnt << " " << ccnt;

	return 0;
}
void normal(int n, int x, int y, const char flag)
{
	if (visit[x][y])
	{
		return;
	}

	if (flag == arr[x][y])
	{
		visit[x][y] = true;
		int tmp[4] = { 0, 0, -1,1 };
		for (int i = 0; i < 4; i++)
		{
			int nx = x + tmp[i];
			int ny = y + tmp[3 - i];
			if(nx > -1 && nx<n && ny>-1&&ny<n)
				normal(n, nx, ny, flag);
		}
	}
	return;
}
void color_blindness(int n, int x, int y, const char flag)
{
	if (cvisit[x][y])
	{
		return;
	}

	if (flag == 'B')
	{
		if (flag == arr[x][y])
		{
			cvisit[x][y] = true;
			int tmp[4] = { 0, 0, -1,1 };
			for (int i = 0; i < 4; i++)
			{
				int nx = x + tmp[i];
				int ny = y + tmp[3 - i];
				if (nx > -1 && nx<n && ny>-1 && ny < n)
					color_blindness(n, nx, ny, flag);
			}
		}
	}
	else
	{
		if (arr[x][y] != 'B')
		{
			cvisit[x][y] = true;
			int tmp[4] = { 0, 0, -1,1 };
			for (int i = 0; i < 4; i++)
			{
				int nx = x + tmp[i];
				int ny = y + tmp[3 - i];
				if (nx > -1 && nx<n && ny>-1 && ny < n)
					color_blindness(n, nx, ny, flag);
			}
		}
	}
	return;
}