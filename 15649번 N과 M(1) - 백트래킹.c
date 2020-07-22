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
		if (check[j] == 0)	//�湮 ��������
		{
			check[j] = 1;
			arr[count] = j + 1;
			print_result(n,m,count + 1);	// ���� �ܰ�� ȣ��
			check[j] = 0;	// ��Ž�� �� �� �ֵ��� �ϱ�
		}
	}
	return;
}