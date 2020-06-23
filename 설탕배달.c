#include <stdio.h>

int main(void)
{
	int N,five,x;

	scanf("%d", &N);
	
	five = N % 5;
	if (five == 0)
	{
		printf("%d", N / 5);
		return 0;
	}
	else if (N == 4)
	{
		printf("%d", -1);
		return 0;
	}

	for (int i = 1; i < 5; i++)
	{
		x = N - 3 * i;
		if (x < 0)
		{
			break;
		}

		if (x % 5== 0)
		{
			printf("%d", x / 5 + i);
			return 0;
		}
	}
	printf("%d", -1);

	return 0;
}