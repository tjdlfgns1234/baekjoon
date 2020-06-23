#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int c,n,sum=0,ex=0;
	int* score;
	double mean = 0;
	double* result;
	scanf("%d", &c);
	result = (double*)malloc(sizeof(double) * c);

	for (int k = 0; k < c; k++)
	{
		scanf("%d", &n);
		score = (int*)malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &score[i]);
			sum = sum + score[i];
		}
		mean = (double)sum /(double)n;
		for (int i = 0; i < n; i++)
		{
			if (mean < score[i])
			{
				ex++;
			}
		}
		*(result+k) =((double)ex/(double)n)*100;
		sum = 0,ex=0;
		free(score);
	}

	for (int i = 0; i < c; i++)
	{
		printf("%.3lf", result[i]);
		printf("%%\n");
	}

	return 0;
}