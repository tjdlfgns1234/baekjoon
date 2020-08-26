#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int check_prime(int n);
int count = 1;
int result;

int main(void)
{
	int n;
	scanf("%d", &n);

	if (n == 1)
	{
		printf("%d", 2);
		return 0;
	}

	for(int i = 3 ;;i=i+2)
	{
		if (check_prime(i))
		{
			count++;
			if (count == n)
			{
				result = i;
				break;
			}
		}
	}
	printf("%d", result);
	return 0;
}
int check_prime(int n)
{
	double to = sqrt(n);


	for (int i = 3; i <= to; i = i + 2)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}