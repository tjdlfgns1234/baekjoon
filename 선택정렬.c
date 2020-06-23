#include <stdio.h>
#include <stdlib.h>

int find_min(int n, int* array, int size);
void swap(int* a, int* b);

int main(void)
{
	int N,minindex=0;
	int* arr;
	scanf("%d", &N);
	arr = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
	}

	for (int n = 0; n < N; n++)
	{
		minindex = find_min(n, arr, N);
		swap(arr + n, arr + minindex);
		printf("%d\n", *(arr + n));
	}



	return 0;
}
int find_min(int n, int* array, int size)
{
	int minindex=n;
	for (int i = n + 1; i < size; i++)
	{
		if (*(array + minindex) > * (array + i))
		{
			minindex = i;
		}
	}
	return minindex;
}
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}