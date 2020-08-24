#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define min(a,b) (((a) < (b)) ? (a) : (b))

struct point {
	int x;
	int y;
};

typedef struct point point;

point* p;

int compareX(const void* a, const void* b)
{
	point* p1 = (point*)a, * p2 = (point*)b;
	return (p1->x - p2->x);
}
int compareY(const void* a, const void* b)
{
	point* p1 = (point*)a, * p2 = (point*)b;
	return (p1->y - p2->y);
}
int dist(point p1, point p2)
{
	return ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
int bruteForce(int start, int end)
{
	int min = INT_MAX;
	for (int i = start; i < end; i++)
		for (int j = i + 1; j < end; j++)
			if (dist(p[i], p[j]) < min)
				min = dist(p[i], p[j]);
	return min;
}
int conquer(point cpy[], int size, int d)
{
	int min = d;
	qsort(cpy, size, sizeof(point), compareY);

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; (j < size) && (((cpy[j].y - cpy[i].y) * (cpy[j].y - cpy[i].y)) < min); j++)
		{
			if (dist(cpy[i], cpy[j]) < min)
				min = dist(cpy[i], cpy[j]);
		}
	}

	return min;
}

int closestUtil(int start, int end)
{
	if (end - start + 1 <= 100)
		return bruteForce(start, end + 1);

	int mid = (start + end) / 2;
	point midpoint = p[mid];

	int tmp;
	int dl = closestUtil(start, mid);
	int dr = closestUtil(mid + 1, end);

	int d = min(dl, dr);

	point* cpy = (point*)malloc(sizeof(point) * (end - start + 1));
	int j = 0;
	for (int i = 0; i < end - start + 1; i++)
	{
		tmp = p[i].x - midpoint.x;
		if ((tmp * tmp) < d)
			cpy[j] = p[i], j++;
	}

	return min(d, conquer(cpy, j, d));
}
int closest(int start, int end)
{
	qsort(p, end - start + 1, sizeof(point), compareX);

	return closestUtil(start, end);
}

int main(void)
{
	int n;

	scanf("%d", &n);

	p = (point*)malloc(sizeof(point) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &p[i].x, &p[i].y);
	}
	printf("%d", closest(0, n - 1));
	return 0;
}