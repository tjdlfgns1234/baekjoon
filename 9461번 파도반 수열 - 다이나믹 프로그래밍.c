#include <stdio.h>
#include <stdlib.h>

long long dp[100] = { 1,1,1,2,2,3,4,5,7,9 };
void formula(int n);

int main(void)
{
	int t,n;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		formula(n);
	}

	return 0;
}
void formula(int n)
{
	if (dp[n - 1] == 0)
	{
		for (int i = 10; i < n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 5];
		}
		printf("%lld\n", dp[n - 1]);
		return;
	}
	printf("%lld\n", dp[n - 1]);
	return;
}