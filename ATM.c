#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y);
int find_min(int num, int* P, int size);

int main(void)
{
	int N,result=0,minindex,sum=0;
	int* P;
	scanf("%d", &N);
	P = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N;i++)
	{
		scanf("%d", P + i);
	}

	for (int n = 0; n < N; n++)
	{
		minindex = find_min(n, P,N);
		swap(P + n, P + minindex);
	}

	for (int i = 0; i < N; i++)
	{
		sum += *(P + i);
		result += sum;
	}

	printf("%d", result);

	return 0;
}
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int find_min(int num, int* P, int size)
{
	int minindex = num;
	for (int m = num + 1; m < size;m++)
	{
		if (*(P + minindex) > * (P + m))
		{
			minindex = m;
		}
	}
	return minindex;
}