#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

void formula(long long x, long long y);
long long n, k, q;

int main(void)
{
	long long x, y;

	scanf("%lld %lld %lld", &n, &k,&q);
	for (long long i = 0LL; i < q; i++)
	{
		scanf("%lld %lld", &x, &y);
		formula(x, y);
	}


	return 0;
}
void formula(long long x, long long y)
{
	long long Vmax;
	long long tmp =x, tmp2 =y;
	long long count = 0;
	if (k == 1)
	{
		printf("%lld\n", abs(x - y));
		return;
	}

	while (tmp != tmp2)
	{
		Vmax = max(tmp, tmp2);
		tmp2 = min(tmp, tmp2);
		tmp = (Vmax - 2) / k + 1;
		count++;
	}
	printf("%lld\n", count);
	return;
}