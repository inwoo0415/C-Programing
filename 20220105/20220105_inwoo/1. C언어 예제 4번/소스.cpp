#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc�Լ��� ���� ����

int main()
{
	int N = 0; // ����� ����
	int M = 0; // ����� ũ�� ����
	int P = 0; // �ӽú���
	int cnt = 0; // üũ ����⸦ �������� üũ ����⺸�� ū ������ ���� ����
	int chk = 0; // üũ ������ �� ����� ����;
	int i = 0;
	// ������ �Է� ����
	scanf("%d", &N);
	if (N >= 2 && N <= 100000)
	{
		// ����� ���� �ش�Ǵ� �����޸� ����
		int* M = (int*)malloc(sizeof(int) * N);
		for (i = 0; i < N; i++)
		{
			// ������ �����޸𸮿� ������� ũ�⸦ �Է��Ѵ�.
			scanf("%d", &P);
			if (P >= 1 && P <= 100000) M[i] = P;
			else
			{
				return 0;
			}

		}
		// �Ǹ����� �Էµ� ����⸦ üũ������ ���ϰ�
		// üũ ����⺸�� ū ����⸦ ã�´�.
		cnt = 1;
		chk = M[N - 1];
		for (i = N - 2; i >= 0; i--)
			if (M[i] > chk)
			{
				cnt++;
				chk = M[i];
			}
		//��� ���

		printf("\n %d", cnt);

		// ������ �����޸� ����
		free(M);



	}
	return 0;
}
