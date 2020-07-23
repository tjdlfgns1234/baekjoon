#include <stdio.h>
#include <stdlib.h>

void n_queen(int n, int queen);	// n_queen �Լ�
int count;					// count ����
int* board;					// ü���� ����

int main(void)
{
	int n;	// n�� �����ϴ� ����
	
	scanf("%d", &n);	// �Է� ���� n�� ������ ����
	board = (int*)calloc(n, sizeof(int));	// board�� n��ŭ �����Ҵ�
	n_queen(n,0);	// n_queen �Լ� ȣ��

	printf("%d", count);	// ��� ���

	return 0;
}
void n_queen(int n, int queen)
{
	int check; // ���� ��ġ�� �������� Ȯ���ϴ� �÷���

	if(queen == n)	// ���� ������ n���϶� �����̹Ƿ�
	{
		count++;	// ����� �� ����
		return;		// �Լ� ����
	}

	for (int i = 0; i < n; i++)
	{
		check = 1;	
		for (int j = 0; j < queen; j++) // for���� j�� ���� Ȯ������
		{
			// ���� �� ��ġ�� ���� ��ġ �������� Ȯ�� (���� ���� �κ�)
			if (board[j] == i || abs(queen - j) == abs(i - board[j])) 
			{
				//  ���� �࿡ ���� ��ġ�ϰų� �밢���� ���� ������ ���
				check = 0;
				break;
			}
		}
		if (check == 1)	// ���� ���� ������ �� ������(���� ������ ������ ��)
		{
			board[queen] = i;	   // i��° ��ġ�� �� ��ġ
			n_queen(n, queen + 1); // ��� ������ ��Ʈ��ŷ ����
		}
	}
	return;
}