#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main(void)
{
	int N, result = 0, temp = 0;
	int weight[100000] = { 0 };
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", weight + i);
	}

	qsort((void*)weight, N, sizeof(int), compare);	//Äü¼ÒÆ®

	for (int i = 0; i < N; i++)
	{
		temp = (*(weight + i)) * (N - i);
		if (result < temp)
		{
			result = temp;
		}
	}
	printf("%d", result);

	return 0;
}