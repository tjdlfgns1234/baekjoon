#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int as = 0, de = 0, n[8] = { 0 };
	for (int i = 0; i < 8; i++)
	{
		scanf("%d", &n[i]);
	}

	for (int i = 0; i < 7; i++)
	{
		if (*(n + i) < *(n + i+1))
		{
			as++;
		}
		else if (*(n + i) > *(n + i+1))
		{
			de++;
		}
	}

	if (as == 7)
	{
		printf("ascending");
	}
	else if (de == 7)
	{
		printf("descending");
	}
	else
	{
		printf("mixed");
	}

	return 0;
}