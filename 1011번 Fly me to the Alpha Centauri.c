#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void formula(long long x, long long y);

int main(void)
{
	int t;
	long long x, y;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%lld %lld", &x, &y);
		formula(x, y);
	}

	return 0;
}
void formula(long long x, long long y)
{
	long long ans = 0LL;
	long long n = 0LL;
	long long d = y - x;

	while (1)
	{
		n++;
		if (n * n > d)
			break;
	}

	if (((n - 1) * (n - 1)) == d)
		ans = 2LL * (n - 1LL) - 1LL;
	else if (((n - 1) * (n - 1) + ((n * n - (n - 1)* (n - 1))/ 2)) >= d)
		ans = 2LL * n - 2LL;
	else
		ans = 2LL * n - 1LL;

	
	printf("%lld\n",ans);#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void formula(long long x, long long y);

int main(void)
{
	int t;
	long long x, y;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%lld %lld", &x, &y);
		formula(x, y);
	}

	return 0;
}
void formula(long long x, long long y)
{
	long long ans = 0LL;
	long long n = 0LL;
	long long d = y - x;

	while (1)
	{
		n++;
		if (n * n > d)
			break;
	}

	if (((n - 1) * (n - 1)) == d)
		ans = 2LL * (n - 1LL) - 1LL;
	else if (((n - 1) * (n - 1) + ((n * n - (n - 1)* (n - 1))/ 2)) >= d)
		ans = 2LL * n - 2LL;
	else
		ans = 2LL * n - 1LL;

	
	printf("%lld\n",ans);
}
}