#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int T;
	int* x, * y,*result;
	scanf("%d", &T);
	x = (int*)malloc(sizeof(int) * T);
	y = (int*)malloc(sizeof(int) * T);
	result= (int*)malloc(sizeof(int) * T);

	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
		result[i] = x[i] + y[i];
	}

	for (int i = 0; i < T; i++)
	{
		printf("Case #%d: %d\n", i + 1, result[i]);
	}

	return 0;
}