#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#define SIZE 1000001
#define min(a,b) (((a) < (b)) ? (a) : (b))

int dp[SIZE];	//bottom-up ¹æ½Ä O(n)

int main(void)
{
	int n;
	int count = 0;
	scanf("%d", &n);
	if (n == 1)
	{
		printf("0");
		return 0;
	}
	for (int i = 2; i < n+1; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}
	printf("%d", dp[n]);

	return 0;
}