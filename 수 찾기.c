#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b)
{
	return *(int*)a > * (int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
	//return *(int*)a > * (int*)b; 으로 할 경우 int 범위가 넘어가면 오버플로우가 발생할 수있음
}

int bisearch(long long* arr, long long key,int N);

int main(void)
{
	int N,M;
	long long key;
	long long* arr;

	scanf("%d", &N);
	arr = (long long*)malloc(sizeof(long long) * N);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &arr[i]);
	}
	qsort((void*)arr, N, sizeof(long long), compare);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%lld", &key);
		printf("%d", bisearch(arr,key,N));
		if (i != M - 1)
		{
			printf("\n");
		}
	}
	free(arr);
	return 0;
}
int bisearch(long long* arr, long long key, int N)
{
	int low = 0;
	int high = N-1;
	int mid;
	while (low <= high) {
		mid = ((low + high) / 2);

		if (arr[mid] == key)
			return 1;
		else if (arr[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}