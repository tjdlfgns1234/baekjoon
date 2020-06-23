#include <stdio.h>
#include <stdlib.h>

/*자료형의 범위에 주의하자*/
int main(void)
{
	long long int result = 0, temp = 0;	
	int n,i;
	double* a;
	scanf("%d", &n);
	a = (double*)malloc(sizeof(double) * n);

	for (i = 0; i < n; i++)
	{
		scanf("%lf",&a[i]);
	}

	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp = a[i] - a[j];
			if (temp < 0)
			{
				result += -temp;
			}
			else
			{
				result += temp;
			}
		}
	}

	printf("%lld", result);
	free(a);

	return 0;
}