#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main(void)
{
	int N, M, sum = 0, result = 0;
	int card[100] = { 0 };
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", card + i);
	}

	qsort((void*)card, N, sizeof(int), compare);	//Äü¼ÒÆ®

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (i != j && i != k && k != j)
				{
					sum = (*(card + i)) + (*(card + j)) + (*(card + k));
					if (sum <= M && sum > result)
					{
						result = sum;
					}
				}
			}
		}
	}

	printf("%d", result);

	return 0;
}