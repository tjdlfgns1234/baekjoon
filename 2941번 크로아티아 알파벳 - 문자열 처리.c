#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

void croatia_alpha(char* buffer);	// ũ�ξ�Ƽ�� ���ĺ��� ã�� �Լ�

int main(void)
{
	char buffer[SIZE + 1];	// ����
	scanf("%s", buffer);	// ���ۿ� ���� �Է��� ����
	croatia_alpha(buffer);	// ũ�ξ�Ƽ�� ���ĺ� �Լ� ȣ��

	return 0;	// ����
}
void croatia_alpha(char* buffer)
{
	int count = 0;	// count : ������ ���� ����
	int size = strlen(buffer);	// size : buffer�� ����ִ� ���ڿ� ����
	for (int i = 0; i < size; i++)
	{
		// strncmp(str1, str2, MAXCOUNT)
		// st1�� str2�� MAXCOUNT��° ���� ������ Ȯ�����ִ� �Լ�
		if (!strncmp(buffer + i, "c=", 2))
		{
			count++;
		}
		if (!strncmp(buffer + i, "c-", 2))
		{
			count++;
		}
		if (!strncmp(buffer + i, "d-", 2))
		{
			count++;
		}
		if (!strncmp(buffer + i, "lj", 2))
		{
			count++;
		}
		if (!strncmp(buffer + i, "nj", 2))
		{
			count++;
		}
		if (!strncmp(buffer + i, "s=", 2))
		{
			count++;
		}
		if (!strncmp(buffer + i, "dz=", 3))
		{
			// dz=�� ã������ z=�� �˻��ɰ��̱� ������ count++�� ����
			count++;
		}
		if (!strncmp(buffer + i, "z=", 2))
		{
			count++;
		}
	}
	printf("%d", size-count);	// ��� ���
}