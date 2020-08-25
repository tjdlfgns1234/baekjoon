#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int compare(const void* a, const void* b)
{
	int tmp = *(int*)a - *(int*)b;
	if (tmp > 0)
		return 1;
	else if (tmp == 0)
		return 0;
	else
		return -1;
}

int main(void)
{
	int n;
	int* arr;
	int line;
	int sum = 0;
	double avg = 0.0;

	scanf("%d", &n);
	if (n == 0)
	{
		printf("0");
		return 0;
	}
	arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	line = (int)round((double)n * (0.15));

	qsort(arr, n, sizeof(int), compare);

	for (int i = line; i < n -line; i++)
	{
		sum = sum+arr[i];
	}

	n = n - line*2;
	avg = (sum)/(double)(n);


	printf("%.0lf", round(avg));
	return 0;
}