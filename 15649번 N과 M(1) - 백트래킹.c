#include <stdio.h>
#include <stdlib.h>

void print_result(const int n, const int m,const int count);
int* check;
int arr[8];

int main(void)
{
	int n, m;

	scanf("%d %d", &n, &m);

	check = (int*)calloc(n, sizeof(int));
	print_result(n, m, 0);

	return 0;
}
void print_result(const int n, const int m, const int count)
{
	if (count == m)
	{
		for (int i = 0; i < m; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int j = 0; j < n; j++)
	{
		if (check[j] == 0)	//방문 안했으면
		{
			check[j] = 1;
			arr[count] = j + 1;
			print_result(n,m,count + 1);	// 다음 단계로 호출
			check[j] = 0;	// 재탐색 할 수 있도록 하기
		}
	}
	return;
}