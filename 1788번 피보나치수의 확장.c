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
	int check = 1;
	int tmp =n;
	if (n < 0)
	{
		check = -1;
		tmp = -tmp;
	}

	if (tmp == 0)
	{
		printf("%d\n", 0);
		printf("%d", 0);
		return;
	}

	if (tmp == 1)
	{
		printf("%d\n", 1);
		printf("%d", 1);
		return;
	}

	if (tmp == 0)
	{
		printf("%d\n", check);
		printf("%d", 1);
		return;
	}

	long long* arr = (long long*)malloc(sizeof(long long) * (tmp+1));

	arr[0] = 0LL;
	arr[1] = 1LL;

	for (int i = 2; i < tmp+1; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2])%1000000000LL;
	}

	if (n>0)
	{
		printf("%d\n", 1);
		printf("%lld", arr[tmp]);
	}
	else
	{
		if((tmp%2) == 0)
			printf("%d\n", -1);
		else
			printf("%d\n", 1);
		printf("%lld", arr[tmp]);
	}
}