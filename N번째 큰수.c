#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void* a, const void* b)
{
	return (*(int *)a - *(int *)b);
}

int main(void)
{
	int T;
	int arr[10];

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			scanf("%d", &arr[j]);
		}
		qsort(arr, 10, sizeof(int), compare);
		printf("%d\n", arr[7]);
	}

	return 0;
}