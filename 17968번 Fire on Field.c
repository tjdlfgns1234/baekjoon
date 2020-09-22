#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int found = 1;
	int n;
	int* arr;
	int tmp = 1;
	int k = 1;

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n+2);

	arr[0] = 1;
	arr[1] = 1;

	for (int i = 2; i < n+1; i++)
	{
		while (1)
		{
			arr[i] = tmp;
			while (i - 2*k >= 0)
			{
				if ((arr[i] - arr[i - k]) == (arr[i-k]-arr[i-2*k]))
				{
					found = 0;
					break;
				}
				else
				{
					k++;
				}
			}
			if (found)
				break;
			
			tmp++;
			k = 1;
			found = 1;
		}
		k = 1;
		found = 1;
		tmp = 1;
	}

	printf("%d", arr[n]);

	return 0;
}