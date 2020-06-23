#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int price[5],sum=0,min=2001;

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &price[i]);
	}

	if (price[4] > price[3])
	{
		sum += price[3];
	}
	else
	{
		sum += price[4];
	}

	for (int i = 0; i < 3; i++)
	{
		if (min > price[i])
		{
			min = price[i];
		}
	}

	sum = sum+min-50;

	printf("%d", sum);

	return 0;
}