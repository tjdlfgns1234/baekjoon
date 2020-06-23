#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int year,check=0;
	scanf("%d", &year);

	if (year % 4 == 0)
	{
		if (year % 100 != 0 || year % 400 == 0)
		{
			check = 1;
		}
	}

	printf("%d", check);

	return 0;
}