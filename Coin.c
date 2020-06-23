#include <stdio.h>
#include <stdlib.h>
int Cal_Coin(int *a,int k,int size);

int main(void)
{
	int n, k,j;
	int* A;
	scanf("%d %d", &n, &k);
	A = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &j);
		*(A + i) = j;
	}

	printf("%d", Cal_Coin(A, k,n));

	return 0;
}
int Cal_Coin(int* a, int k,int n)
{
	int remain=k,counter=0,total;

	for (int i = 0; i < n; i++)
	{
		total = remain / (*(a + n - 1 - i));
		counter += total;
		remain = remain - total * (*(a + n - 1 - i));
		if (remain == 0)
		{
			break;
		}
	}

	return counter;
}