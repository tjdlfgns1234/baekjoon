#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int* arr;
	int* sum;
	int tmp = 0;
	int i, j;

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	sum = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++)
	{
		sum[i] = arr[i] + tmp;
		tmp += arr[i];
	}

	scanf("%d", &n);
	for (int k = 0; k < n; k++)
	{
		scanf("%d %d", &i, &j);
		if (i != j)
			if(i==1)
				printf("%d\n", sum[j - 1]);
			else
				printf("%d\n", sum[j - 1] - sum[i-2]);
		else
			printf("%d\n", arr[j-1]);
	}


	return 0;
}