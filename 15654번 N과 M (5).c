#include <stdio.h>
#include <stdlib.h>

void print_result(int * arr,const int n, const int m, const int count);
int compare(const void* a, const void* b);
int* check;
int arr[8];

int main(void)
{
	int n, m;
	int* input;
	scanf("%d %d", &n, &m);
	input = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input[i]);
	}

	qsort(input, n, sizeof(int), compare);

	check = (int*)calloc(n, sizeof(int));
	print_result(input,n, m, 0);

	return 0;
}
void print_result(int *input,const int n, const int m, const int count)
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
			arr[count] = input[j];
			print_result(input,n, m, count + 1);	// 다음 단계로 호출
			check[j] = 0;	// 재탐색 할 수 있도록 하기
		}
	}
	return;
}
int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}