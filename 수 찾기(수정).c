#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b)
{
	if (*(long long*)a > *(long long*)b)
		return 1;
	else if (*(long long*)a < * (long long*)b)
		return -1;
	else
		return 0;
}

int bisearch(long long* arr, long long key, int N);

int main(void)
{
	int N, M;
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
		printf("%d", bisearch(arr, key, N));
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
	int high = N - 1;
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