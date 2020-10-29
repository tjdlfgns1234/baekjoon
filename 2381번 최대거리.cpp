#include <iostream>
#include <algorithm>

using namespace std;

struct point {
	int x, y;
};
typedef struct point Point;

int dist(Point* a, Point* b)
{
	return abs(a->x - b->x) + abs(a->y - b->y);
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	Point* arr = new Point[n];
	int* ap = new int[n];
	int* am = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i].x >> arr[i].y, ap[i]= arr[i].x + arr[i].y, am[i] = arr[i].x - arr[i].y;
	
	sort(ap, ap + n);
	sort(am, am + n);

	cout << max(ap[n-1]-ap[0],am[n-1]-am[0]);

	return 0;
}