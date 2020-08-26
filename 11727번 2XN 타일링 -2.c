#include <stdio.h>
#include <stdlib.h>

void formula(int n);

int main(void)
{
	int n;

	scanf("%d", &n);
	formula(n);

	return 0;
}
void formula(int n)
{
	int* arr = (int*)malloc(sizeof(int) * n);


	if (n == 1)
	{
		printf("%d", 1);
		return;
	}
	arr[0] = 1;
	arr[1] = 3;

	for (int i = 2; i < n; i++)
	{
		arr[i] = (arr[i - 1] + 2 * arr[i - 2])%10007;
	}
	printf("%d", arr[n - 1]);
}