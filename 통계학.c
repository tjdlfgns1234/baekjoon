#include <stdio.h>
#include <stdlib.h>
#define SIZE 4000

int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int mode_finder(const int* counting_sort);

int main(void)
{
	int N, counting_sort[SIZE*2 + 1]={ 0 },center_value=0,range=0,mode=0;
	double ave = 0;
	int* arr;
	scanf("%d", &N);

	arr = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] > 0)
		{
			counting_sort[arr[i]+SIZE]++;
		}
		else
		{
			counting_sort[abs(arr[i])]++;
		}
		ave = ave + arr[i];
	}
	ave = ave / (double)N;
	qsort((void*)arr, N, sizeof(int), compare);

	center_value = arr[N / 2];
	range = arr[N - 1] - arr[0];
	mode = mode_finder(counting_sort);

	printf("%0.lf\n", ave);
	printf("%d\n", center_value);
	printf("%d\n", mode);
	printf("%d", range);

	return 0;
}
int mode_finder(const int* counting_sort)
{
	int result=0,tmp1=8001,tmp2=8001,mode=0;

	for (int i = SIZE; i>0; i--)
	{
		if (counting_sort[SIZE +i] > mode)
		{
			mode = counting_sort[SIZE+i];
			tmp1 =i;
			tmp2 = SIZE * 2 + 1;
		}
		else if (counting_sort[SIZE+i] == mode)
		{
			mode = counting_sort[SIZE+i];
			tmp2 = tmp1;
			tmp1 =i;
		}
	}
	for (int i = 0; i < SIZE + 1; i++)
	{
		if (counting_sort[i] > mode)
		{
			mode = counting_sort[i];
			tmp1 = -i;
			tmp2 = SIZE * 2 + 1;
		}
		else if (counting_sort[i] == mode)
		{
			mode = counting_sort[i];
			tmp2 = tmp1;
			tmp1 = -i;
		}
	}

	if (tmp2 != (SIZE * 2 + 1))
	{
		return tmp2;
	}
	else
	{
		return tmp1;
	}
}