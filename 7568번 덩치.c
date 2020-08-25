#include <stdio.h>
#include <stdlib.h>

struct weight_height {
	int weight;
	int height;
	int rate;	// 초기값은 1
};

typedef struct weight_height point;

void rate(point p[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (p[i].height < p[j].height && p[i].weight < p[j].weight)
				p[i].rate++;
}

int main(void)
{
	int n;
	point *p;

	scanf("%d", &n);
	p = (point*)malloc(sizeof(point) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &p[i].weight, &p[i].height);
		p[i].rate = 1;
	}

	rate(p, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", p[i].rate);
	}


	return 0;
}