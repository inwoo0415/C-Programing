#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h> // malloc(), free()��
#include <string.h> // strlen(), strcpy()

int main()
{
	int T = 0; // ���ڿ��� ������ �Է¹޴´�.
	char str[255];// ������ ���ڿ��� �Է��� ���ڿ� �迭����
	int r = 0, c = 0; // ��, ������
	int c1 = 0, c2 = 0;
	int sen1 = 0, sen2 = 0, sen3 = 0; // ȸ��, ����ȸ��, ��ȸ�� ����
	int i = 0;// �ݺ�����
	int N = 0;// ���ڿ��� ���� ����

	// ���ڿ� ���� �Է� �ޱ�
	scanf("%d%*c", &T);

	// 1<=T<=30 ���ǿ� ������ �۾��� ����Ѵ�.
	if (T >= 1 && T <= 30)
	{
		//�Էµ� ���ڿ��� ������ŭ�� ���ڿ��� �Է��� �����޸𸮸� ����
		char** M = (char**)malloc(sizeof(char*) * T);
		for (r = 0; r < T; r++)
		{
			//���ڿ��� �Է��Ѵ�.
			scanf("%s%*c", str);

			if (strlen(str) >= 3 && strlen(str) <= 100000) // ���ڿ��� ���� ��ȯ
			{
				M[r] = (char*)malloc(sizeof(char) * (strlen(str) + 1));
				strcpy(M[r], str);
			}
			else
				return 0;
		}

		// �Էµ� ���ڿ��� ȸ��, ����ȸ��, �Ѵ� �ƴ��� üũ�Ѵ�.
		for (r = 0; r < T; r++)
		{
			// ���ڿ� �� Ʋ�� ���ڰ� ������ ȸ���� �ƴ�
			// Ʋ�� ������ ��ġ�� ȸ��üŭ������ ����
			// ȸ���̸� ���

			sen1 = -1; // ȸ��üũ����
			N = strlen(M[r]);
			for (c = 0; c < N / 2; c++)
				if (M[r][c] != M[r][N - 1 - c])
				{
					sen1 = c;
					break;
				}
			if (sen1 == 1)
			{
				printf("0\n");
			}
			else
			{
				//����ȸ�� �Ǵ� ��ȸ������ üũ�Ѵ�.
				c1 = c2 = 0;
				sen2 = 0;
				sen3 = 0;
				char* senStr1 = (char*)malloc(sizeof(char) * (strlen(M[r] + 1)));
				char* senStr2 = (char*)malloc(sizeof(char) * (strlen(M[r] + 1)));// ���� ���ڿ� ����

				// Ʋ�� ��ġ�� ���ڸ� �� ���ڵ��� ������ ������ �����Ѵ�.
				for (i = 0; i < N - 1; i++)
				{
					if (i != sen1) senStr1[c1++] = M[r][i];
					if (i != N - 1 - sen1) senStr2[c2++] = M[r][i];
				}

				// ������ ���ڵ��� ���Ͽ� ����ȸ��, ��ȸ���� üũ�Ѵ�.
				for (i = 0; i < N - 1; i++)
				{
					if (senStr1[i] != senStr1[N - 2 - i]) sen2 = 1;
					if (senStr2[i] != senStr2[N - 2 - i]) sen3 = 1;
				}
				if (sen2 == 1 && sen3 == 1)
					printf("2\n");
				else
					printf("1\n");

				free(senStr1);
				free(senStr2);
			}
		}
		for (r = 0; r < T; r++)
		{
			free(M[r]);
			free(M);
		}

		return 0;
	}
}



