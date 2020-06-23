#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 50
#define SIZE 8

int check(const char arr[][SIZE]);

int main(void)
{
	int i, j, n, m, count = 0;
	int min = INT_MAX,result=0;
	char board[MAX][MAX];
	char arr[SIZE][SIZE];
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf(" %c",&board[i][j]);
		}
	}
	
	/* 8*8로 나누어서 탐색 */
	for (int y = 0; y < m - 7; y++)
	{
		for (int x = 0; x < n - 7; x++)
		{
			for (i = 0; i < SIZE; i++)
			{
				for (j = 0; j < SIZE; j++)
				{
					arr[i][j] = board[i+x][j + y];
				}
			}
			result = check(arr);
			if (min > result)
			{
				min = result;
			}
		}
	}
	
	printf("%d", min);
	return 0;
}
int check(const char arr[][SIZE])
{
	/*알고리즘*/
	int count = 0;
	int count2 = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i % 2) == 0)
			{
				if ((j % 2) == 0)
				{
					if (arr[i][j] == 'B')
					{
						count++;
					}
				}
				else
				{
					if (arr[i][j] == 'W')
					{
						count++;
					}
				}
			}
			else
			{
				if ((j % 2) == 0)
				{
					if (arr[i][j] == 'W')
					{
						count++;
					}
				}
				else
				{
					if (arr[i][j] == 'B')
					{
						count++;
					}
				}
			}
		}
	}


	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i % 2) == 0)
			{
				if ((j % 2) == 0)
				{
					if (arr[i][j] == 'W')
					{
						count2++;
					}
				}
				else
				{
					if (arr[i][j] == 'B')
					{
						count2++;
					}
				}
			}
			else
			{
				if ((j % 2) == 0)
				{
					if (arr[i][j] == 'B')
					{
						count2++;
					}
				}
				else
				{
					if (arr[i][j] == 'W')
					{
						count2++;
					}
				}
			}
		}
	}
	if(count < count2)
	{
		return count;
	}
	else
	{
		return count2;
	}	
}