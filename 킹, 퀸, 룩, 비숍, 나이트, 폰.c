#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
	int num[6], num2[6] = { 1,1,2,2,2,8 };

	for (int i = 0; i < 6; i++)
	{
		scanf("%d", &num[i]);
		num[i] = num2[i] - num[i];
	}

	for (int i = 0; i < 6; i++)
	{
		printf("%d ", num[i]);
	}

	return 0;
}