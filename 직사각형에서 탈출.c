#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int find_distance(const int x,const int y,const int w,const int h);

int main(void)
{
	int x, y, w, h;
	int result = 0;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	result=find_distance(x, y, w, h);

	printf("%d", result);

	return 0;
}
int find_distance(const int x, const int y, const int w, const int h)
{
	int result = INT_MAX, tmp[4] = { 0 };
	tmp[0] = x;
	tmp[1] = y;
	tmp[2] = abs(h - y);
	tmp[3] = abs(w - x);
	//최솟값을 찾는 for문
	for (int i = 0; i < 4; i++)
	{
		if (result > tmp[i])
		{
			result = tmp[i];
		}
	}

	return result;
}