#include <stdio.h>
#include <stdlib.h>

void check_sum(int* arr, int n, int s,int sum, int index);
int count = 0;

int main(void)
{
	int n ,s;
	int* arr;

	scanf("%d %d", &n, &s);
	arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	check_sum(arr, n, s,0, 0);
	printf("%d", count);

	return 0;
}
void check_sum(int* arr, int n, int s, int sum, int index)
{

	if (index == n)	// �迭�� �����Ƿ� ����
		return;

	if (sum + arr[index] == s)
	{
		count++;
	}

	check_sum(arr, n, s, sum + arr[index], index+1);	// �ڱ� �ڽ� ����
	check_sum(arr, n, s, sum,index+1);	// �ڱ� �ڽ� ����
}