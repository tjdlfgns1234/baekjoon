#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

/*���簢���� ��ǥ ���� �ν��� ¦�� �̷�ٴ� ��Ģ�� �̿�*/

int main(void)
{
	int x[3], y[3], countx[SIZE+1] = { 0 }, county[SIZE+1] = { 0 };
	for (int i = 0; i < 3; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
		countx[x[i]]++;
		county[y[i]]++;
	}
	
	for (int i = 0; i < 3; i++)
	{
		if (countx[x[i]] == 1)
		{
			printf("%d ", x[i]);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (county[y[i]] == 1)
		{
			printf("%d", y[i]);
		}
	}

	return 0;
}