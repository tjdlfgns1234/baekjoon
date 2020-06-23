#include <stdio.h>

int main(void)
{
	int h, m, time;
	scanf("%d %d", &h, &m);

	time = 60 * h + m-45;
	if (time < 0)
	{
		time += 24 * 60;
	}

	h = time / 60;
	m = time % 60;
	printf("%d %d", h, m);

	return 0;
}