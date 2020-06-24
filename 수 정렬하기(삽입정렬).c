#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int* A, int n);

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

	insertion_sort(A, size);
	for (i = 0; i < size; i++)
	{
		printf("%d\n", A[i]);
	}

	return 0;
}
void insertion_sort(int* A, int n) {
	int i, j, temp;
	for (int i = 0; i < n; i++)
	{
		for (j = i - 1; j >= 0 && A[j] > A[j + 1]; j--)
		{
			temp = A[j + 1];
			A[j + 1] = A[j];
			A[j] = temp;
		}
	}
}