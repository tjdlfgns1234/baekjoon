#include <stdio.h>
#include <stdlib.h>
#define MOON 0.167

int main(void)
{
	double earth, luna;
	while (1)
	{
		scanf("%lf", &earth);
		luna = earth * MOON;
		if (earth < 0)
		{
			break;
		}
		printf("Objects weighing %.2lf on Earth will weigh %.2lf on the moon.\n", earth, luna);
	}
	return 0;
}