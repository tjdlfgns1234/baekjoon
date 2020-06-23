#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main(void)
{
	int n;
	int* arr;

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	qsort(arr, n, sizeof(int), compare);

	for (int i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}