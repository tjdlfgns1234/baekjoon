#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int x, y, z,sum=0;

	scanf("%d %d %d", &x, &y, &z);

	sum = x + y;
	if (sum == z)
	{
		printf("%d+%d=%d", x, y, z);
		return 0;
	}
	sum = x - y;
	if (sum == z)
	{
		printf("%d-%d=%d", x, y, z);
		return 0;
	}
	sum = x * y;
	if (sum == z)
	{
		printf("%d*%d=%d", x, y, z);
		return 0;
	}
	sum = x / y;
	if (sum == z)
	{
		printf("%d/%d=%d", x, y, z);
		return 0;
	}

	sum = y + z;
	if (sum == x)
	{
		printf("%d=%d+%d", x, y, z);
		return 0;
	}
	sum = y - z;
	if (sum == x)
	{
		printf("%d=%d-%d", x, y, z);
		return 0;
	}
	sum = y * z;
	if (sum == x)
	{
		printf("%d=%d*%d", x, y, z);
		return 0;
	}
	sum = y /z;
	if (sum == x)
	{
		printf("%d=%d/%d", x, y, z);
	}


	return 0;
}