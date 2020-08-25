#include <stdio.h>
#include <stdlib.h>

void formula(int arr[], int n);

int main(void)
{
	int n;
	int* arr;

	scanf("%d",& n);
	arr = (int*)malloc(sizeof(int) * n);
	formula(arr, n);

	return 0;
}
void formula(int arr[], int n)
{
	arr[0] = 1;
	arr[1] = 2;

	for (int i = 2; i < n; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2])%10007;
	}

	printf("%d", arr[n - 1]);
}