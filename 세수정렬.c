#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void selection_sort(int *num,int i);

int main(void)
{
	int num[3], tmp = 0;

	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		selection_sort(num,i);
	}

	printf("%d %d %d", num[2], num[1], num[0]);

	return 0;
}
void selection_sort(int* num,int i)
{
	int max = INT_MIN,index=0,tmp=0;

	for (int j = i; j < 3; j++)
	{
		if (max < num[j])
		{
			max = num[j];
			index = j;
		}
	}
	tmp = num[i];
	num[i] = max;
	num[index] = tmp;
}