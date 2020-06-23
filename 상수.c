#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int a, b;
	
	scanf("%d %d", &a, &b);

	a = (a / 100) + (a % 10)*100 + (a / 10) % 10*10;
	b = (b / 100) + (b % 10)*100 + (b / 10) % 10*10;

	if (a > b)
	{
		printf("%d", a);
	}
	else
	{
		printf("%d", b);
	}

	return 0;
}