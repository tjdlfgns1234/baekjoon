#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main(void)
{
	int N;
	int n[1000000] = { 0 };
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", n + i);
	}

	qsort((void*)n, N, sizeof(int), compare);//Äü¼ÒÆ®

	for (int i = 0; i < N; i++)
	{
		printf("%d\n", *(n+i));
	}

	return 0;
}