#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a[1001] = { 0 }, x, count = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &x);
		a[(x%42)]++;
	}

	for (int i = 0; i < 1000; i++)
	{
		if (a[i] != 0)
		{
			count++;
		}
	}

	printf("%d", count);

	return 0;
}