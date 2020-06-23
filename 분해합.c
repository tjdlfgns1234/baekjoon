#include <stdio.h>
#include <stdlib.h>

int cal_M(int j,int N);	//�������� ���ϴ� �Լ�(�� �ڸ��� ���� ���� ����ϰ� ���ִ� �Լ�)

int main(void)
{
	int N,result=0;
	scanf("%d", &N);

	for (int i = 1; i < N+1; i++)
	{
		result = cal_M(i,N);	// 1���� N���� �������� ���ϴ� �Լ��� ȣ��
		if (result != 0)		// ���� �������� ���� 0�� �ƴϸ� �ݺ��� Ż��
			break;
	}

	printf("%d", result);	//��� ���

	return 0;
}
int cal_M(int j, int N)
{
	int x[7] = { 0 };	//�� �ڸ��� ���� �����ϴ� �迭
	int y = 1000000, i = 6, sum = 0;	//������ ���� ����
	int result; //�������� �����ϴ� ����
	for (i = 6; i > -1; i--)  //�� �ڸ����� ����Ͽ� �迭x�� �־���
	{
		x[i] = (j % (10 * y) / y);
		y = y / 10;
	}
	for (i = 0; i < 7; i++)	//�� �ڸ����� ���� �������
	{
		sum = sum + x[i];
	}
	result = j + sum;	//result������ �������� �־���
	if (result == N)
		return j;
	else
		return 0;
}