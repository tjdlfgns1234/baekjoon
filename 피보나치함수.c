#include <stdio.h>
#include <stdlib.h>

void one_value(int n);
void zero_value(int n);
void print_result(int n);

int one[41] = { 0,1 };
int zero[41] = { 1,0 };

int main(void)
{
	int T;
	int* fibo;
	scanf("%d", &T);
	fibo = (int*)malloc(sizeof(int) * T);
	one_value(41);
	zero_value(41);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &fibo[i]);
	}

	for (int i = 0; i < T; i++)
	{
		print_result(fibo[i]);
	}


	return 0;
}
void one_value(int n)
{
	for (int i = 2; i < n; i++)
	{
		one[i] = one[i - 1] + one[i - 2];
	}
}
void zero_value(int n)
{
	for (int i = 2; i < n; i++)
	{
		zero[i] = zero[i - 1] + zero[i - 2];
	}
}
void print_result(int n)
{
	printf("%d %d\n", zero[n], one[n]);
}