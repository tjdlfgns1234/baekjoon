#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
	unsigned long int s,sum=0;

	scanf("%u", &s);

	if (s == 2 ||s == 1)
	{
		printf("1");
		return 0;
	}
	if (s == 3)
	{
		printf("2");
	}

	for (unsigned long int i = 1; i < s; i++)
	{
		sum = sum + i;
		if (sum > s)
		{
			printf("%u", i-1);
			break;
		}
	}

	return 0;
}