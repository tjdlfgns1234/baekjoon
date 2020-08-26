#include <stdlib.h>
#include <stdio.h>

int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int lower_bisearch(int* arr, int key, int N);
int upper_bisearch(int* arr, int key, int N);

int main(void)
{
	int n, m, tmp = 0, count = 0, lower, upper;
	int* arr_n, * arr_m;
	int* count_n;

	/* 입력 부분 */
	scanf("%d", &n);
	arr_n = (int*)malloc(sizeof(int) * n);
	count_n = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr_n[i]);
	}

	scanf("%d", &m);
	arr_m = (int*)malloc(sizeof(int) * m);

	for (int i = 0; i < m; i++)
	{
		scanf("%d", &arr_m[i]);
	}

	/* 알고리즘 부분 */

	qsort(arr_n, n, sizeof(int), compare);

	for (int i = 0; i < m; i++)
	{
		lower = lower_bisearch(arr_n, arr_m[i], n);
		upper = upper_bisearch(arr_n, arr_m[i], n);
		if (upper == n - 1 && arr_n[n - 1] == arr_m[i])
		{
			upper++;
		}
		if(upper - lower >=1)
			printf("%d ", 1);
		else
			printf("%d ", 0);
	}


	return 0;
}
int lower_bisearch(int* arr, int key, int N)
{
	int low = 0;
	int high = N - 1;
	int mid;
	while (low < high) {
		mid = ((low + high) / 2);
		if (arr[mid] >= key)
			high = mid;
		else
			low = mid + 1;
	}
	return high;
}
int upper_bisearch(int* arr, int key, int N)
{
	int low = 0;
	int high = N - 1;
	int mid;
	while (low < high) {
		mid = ((low + high) / 2);

		if (arr[mid] > key)
			high = mid;
		else
			low = mid + 1;
	}
	return high;
}