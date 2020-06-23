#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int check_prime(int N);
void count_ini();
int count = 0;

int main(void)
{
	int a;
	while (1)
	{
		scanf("%d",&a);
		if (a == 0)
		{
			return 0;
		}
		for (int i = a+1; i <= 2*a ; i++)
		{
			check_prime(i);
		}
		printf("%d\n", count);
		count_ini();
	}
}
int check_prime(int N)
{
	double to = sqrt(N);
	int check = 0;
	if (N == 2)
	{
		count++;
		return 1;
	}
	if (N % 2 == 0)
	{
		return 0;
	}
	for (int i = 2; i <=to; i++)
	{
		if ((N % i) == 0)
		{
			return 0;
		}
	}
	count++;
	return 1;
}
void count_ini()
{
	count = 0;
}