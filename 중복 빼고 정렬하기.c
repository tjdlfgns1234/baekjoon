#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int main(void)
{
	int n;
	int* arr;
	int count_arr[1001] = { 0 };
	int count_arr2[1001] = { 0 };

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] > -1)
		{
			count_arr[arr[i]]++;
		}
		else
		{
			count_arr2[-arr[i]]++;
		}
	}
	for (int i = 1000; 0 < i; i--)
	{
		if (count_arr2[i]!=0)
		{
			printf("%d ", -i);
		}
	}
	for (int i = 0; i < 1001; i++)
	{
		if (count_arr[i] != 0)
		{
			printf("%d ", i);
		}
	}

	return 0;
}