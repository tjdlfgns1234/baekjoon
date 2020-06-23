#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int FindSubarray(int* arr, int n);

int main(void)
{
	int t,n;
	int* arr;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		arr = (int*)malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[j]);
		}
		printf("%d\n",FindSubarray(arr, n));
		free(arr);
	}

	return 0;
}
int FindSubarray(int* arr, int n)
{
	int maxSum = INT_MIN; // 최종 답을 저장할 변수
	int sum; // 중간 답을 저장할 변수
	int i, j;
	for (i = 0; i < n; i++)
	{
		sum = 0;
		for (j = i; j < n; j++)
		{
			sum = sum + arr[j];
			if (sum > maxSum)
				maxSum = sum;
		}
	}
	return(maxSum);
}