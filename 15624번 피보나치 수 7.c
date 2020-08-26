#include <stdio.h>
#include <stdlib.h>

void formula(long long arr[], int n);

int main(void)
{
	int n;
	long long* arr;

	scanf("%d", &n);
	arr = (long long*)malloc(sizeof(long long) * (n+1));
	formula(arr, n);

	return 0;
}
void formula(long long arr[], int n)
{
	if (n == 0)
	{
		printf("%d", 0);
		return;
	}
	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i < n+1; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000007LL;
	}

	printf("%lld", arr[n]);
}