#include <stdio.h>
#include <stdlib.h>

int find_count(int N);

int main(void)
{
	int N;
	scanf("%d", &N);

	printf("%d", find_count(N));

	return 0;
}
int find_count(int N)
{
	int count = 0, tmp = 0, tmp2 = 0, result = 0;

	if (N < 10)
	{
		N = N * 10;
		if (N == 0)
		{
			return 1;
		}
	}

	tmp = N % 10;
	tmp2 = (N - tmp) / 10;

	while (result != N)
	{
		result = tmp * 10 + (tmp + tmp2)%10;
		count++;
		tmp = result % 10;
		tmp2 = (result - tmp) / 10;
	}

	return count;
}