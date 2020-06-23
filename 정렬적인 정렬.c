#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int main(void)
{
	int N;
	int* arr;

	scanf("%d", &N);
	arr = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	qsort(arr, N, sizeof(int), compare);

	for (int i = 0; i < N; i++)
	{
		printf("%d ", arr[i]);
	}


	return 0;
}