#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int n, c, max = INT_MIN, index = -1;
	int* arr;
	int* check_arr;
	int* count_arr;

	scanf("%d %d", &n, &c);
	arr = (int*)malloc(sizeof(int) * n);
	check_arr = (int*)calloc(n,sizeof(int));
	count_arr = (int*)calloc(n,sizeof(int));
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		check_arr[i] = arr[i];
		count_arr[i]++;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == check_arr[j])
			{
				count_arr[j]++;
				count_arr[i] = 0;
				check_arr[i] = 0;
				break;
			}
		}
	};


	for (int k = 0; k < n; k++)
	{
		max = INT_MIN;
		for (int i = 0; i < n; i++)
		{
			if (max < count_arr[i])
			{
				max = count_arr[i];
				index = i;
			}
		}
		for (int j = 0; j < count_arr[index]; j++)
		{
			if (max == 0)
			{
				break;
			}
			printf("%d ", arr[index]);
		}
		count_arr[index] = -1;
	}

	return 0;
}