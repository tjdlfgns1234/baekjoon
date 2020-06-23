#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main(void)
{
	int K,N,*arr;
	int tmp,gap=INT_MIN;
	scanf("%d", &K);

	for (int i = 0; i < K; i++)
	{
		scanf("%d", &N);
		arr = (int*)malloc(sizeof(int) * N);
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[j]);
		}
		qsort(arr, N, sizeof(int), compare);
		for (int j = 0; j < N-1; j++)
		{
			tmp = arr[j+1] - arr[j];
			if (tmp > gap)
			{
				gap = tmp;
			}
		}
		printf("Class %d\n", i + 1);
		printf("Max %d, Min %d, Largest gap %d\n",arr[N-1],arr[0],gap);
		gap = INT_MIN;
	}


	return 0;
}