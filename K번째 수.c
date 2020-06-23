#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main(void)
{
	int n, k;
	int* a;
	scanf("%d %d", &n, &k);

	a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	qsort((void*)a, n, sizeof(int), compare);
	printf("%d", a[k-1]);

	return 0;
}