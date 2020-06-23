#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 10000

int main(void)
{
	int N,x,i;
	int  count[MAX_NUM + 1] = { 0 };
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &x);
		count[x]++;
	}

	for (i = 1; i < MAX_NUM+1; i++)
	{
		while (count[i] != 0)
		{
			printf("%d", i);
			printf("\n");
			count[i]--;
		}
	}


	return 0;
}