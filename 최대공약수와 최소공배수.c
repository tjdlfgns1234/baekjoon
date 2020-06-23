#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b);
int lcm(int a, int b);
int main(void)
{
	int a, b;
	int result1, result2;
	scanf("%d %d", &a, &b);
	
	result1 = gcd(a, b);
	result2 = lcm(a, b);

	printf("%d %d", result1, result2);
	return 0;
}
int gcd(int a,int b)
{
	int tmp = a, tmp2 = b;
	while (tmp2 != 0)
	{
		int r = tmp % tmp2;
		tmp = tmp2;
		tmp2 = r;
	}
	return tmp;
}
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}