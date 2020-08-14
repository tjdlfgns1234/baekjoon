#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10000

void palindrome();		 //�縰����� �����ִ� �Լ� (O(n^2))
char buffer[101][SIZE+1];	 //���ڿ��� ������ �迭 ����

int main(void)
{
	int t;	// t : �׽�Ʈ ���̽��� �����ϴ� ����
	scanf("%d", &t);
	for(int i = 0 ; i<t;i++)	// �׽�Ʈ ���̽� ��ŭ �縰��� �Լ� ȣ��
		palindrome();

	return 0;
}
void palindrome()
{
	int n;	// n : ������ ����
	int size;	// buffer�� ũ��
	int check = 0;	//�縰����� ã�Ҵ��� Ȯ���ϴ� ����
	char temp[SIZE + 1];	// ���ڿ��� ��ģ���� �ӽ÷� �����ϴ� ����
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &buffer[i][0]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			// �ڿ� ���ڿ� ���̱�
			strcpy(temp, &buffer[i][0]);
			strcat(temp, &buffer[j][0]);
			size = strlen(temp);
			check = 0;
			for (int k = 0; k < size; k++)
			{
				if (temp[k] != temp[size - k - 1])
				{
					check = 1;	//�縰����� �ƴϸ�
					break;	//for�� Ż��
				}
			}
			if (check == 0)	//�縰����̸� ����ϰ� Ż��
			{
				printf("%s\n", temp);
				return;
			}
		}
		for (int j = i + 1; j < n; j++)
		{
			// �տ� ���ڿ� ���̱�
			strcpy(temp, &buffer[j][0]);
			strcat(temp, &buffer[i][0]);
			size = strlen(temp);
			check = 0;
			for (int k = 0; k < size; k++)
			{
				if (temp[k] != temp[size - k - 1])
				{
					check = 1;	//�縰����� �ƴϸ�
					break;	//for�� Ż��
				}
			}
			if (check == 0)//�縰����̸� ����ϰ� �Լ� ����
			{
				printf("%s\n", temp);
				return;
			}
		}
	}
	// ������� ������ �縰����� ����� �ִ� ������ ����.
	printf("0\n");	//���� 0 ���
}