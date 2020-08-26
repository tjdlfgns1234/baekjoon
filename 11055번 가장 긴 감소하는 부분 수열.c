#include <stdio.h>
#include <stdlib.h>

void find_LIS(int* arr, int n);
int* dp;

int main(void)
{
	int n;
	int* arr;

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	dp = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	find_LIS(arr, n);


	return 0;
}
void find_LIS(int* arr, int n)
{
	int result = 0;
	for (int j = 0; j < n; j++)
	{
		if (dp[j] == 0) {
			dp[j] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			if (arr[j] < arr[i])
			{
				if (dp[j] < dp[i] + 1)
				{
					dp[j] = dp[i] + 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (result < dp[i])
		{
			result = dp[i];
		}
	}
	printf("%d", result);
}