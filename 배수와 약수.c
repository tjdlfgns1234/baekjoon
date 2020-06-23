#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int x, y,tmp,tmp2;

	for (;;)
	{
		scanf("%d %d", &x, &y);
		if (x == 0 && y == 0)
		{
			break;
		}
		tmp = y % x;
		tmp2 = x % y;
		if (tmp == 0)
		{
			printf("factor\n");
		}
		else if (tmp2 == 0)
		{
			printf("multiple\n");
		}
		else
		{
			printf("neither\n");
		}
	}

	return 0;
}