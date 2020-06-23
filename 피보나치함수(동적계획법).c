#include <stdio.h>
#include <stdlib.h>

void fibo_find(int n);
long long int fibonachi(int n);
long long int fibo[91] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597 };

int main(void)
{
	int n;
	scanf("%d", &n);

	fibo_find(n);
	printf("%lld", fibonachi(n));

	return 0;
}
long long int fibonachi(int n)
{
	return fibo[n];
}
void fibo_find(int n)
{
	for (int i = 17; i < n + 1; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
}