#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Swap(int* arr, int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}
int Partition(int* arr, int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (pivot > arr[low])
		{
			low++;
		}

		while (pivot < arr[high])
		{
			high--;
		}

		if (low <= high)
		{
			Swap(arr, low, high);
		}
	}
	Swap(arr, left, high);
	return high;
}
void QuickSort(int* arr, int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

int main(void)
{
	int size;
	int* A;
	int i = 0;

	scanf("%d", &size);
	A = (int*)malloc(sizeof(int) * size);

	for (i = 0; i < size; i++)
	{
		scanf("%d", &A[i]);
	}

	QuickSort(A, 0,size-1);

	for (i = 0; i < size; i++)
	{
		printf("%d\n", A[i]);
	}

	return 0;
}