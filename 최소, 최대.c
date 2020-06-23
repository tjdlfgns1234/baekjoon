#include <stdio.h>
#include <stdlib.h>

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

	qsort((void*)arr, n, sizeof(int), compare);

	printf("%d %d", arr[0], arr[n - 1]);
	free(arr);

	return 0;
}