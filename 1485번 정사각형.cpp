#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;
bool Isrec();
long long x[4];
long long y[4];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < 4; j++)
			cin >> x[j] >> y[j];
		if (Isrec())
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	return 0;
}
bool Isrec()
{
	long long d[6], idx = 0;
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 4; j++)
			d[idx++] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
	
	sort(&d[0], &d[6]);

	for (int i = 1; i < 4; i++)	// 직선 길이 확인
		if (d[i - 1] != d[i])
			return false;
	
	if (d[4] != d[5])	// 대각선 길이 확인
		return false;

	return true;
}