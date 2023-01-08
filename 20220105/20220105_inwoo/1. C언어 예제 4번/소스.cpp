#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc함수를 쓰기 위함

int main()
{
	int N = 0; // 막대기 개수
	int M = 0; // 막대기 크기 개수
	int P = 0; // 임시변수
	int cnt = 0; // 체크 막대기를 기준으로 체크 막대기보다 큰 막대기수 세는 변수
	int chk = 0; // 체크 기준이 될 막대기 변수;
	int i = 0;
	// 막대기수 입력 받음
	scanf("%d", &N);
	if (N >= 2 && N <= 100000)
	{
		// 막대기 수에 해당되는 동적메모리 설정
		int* M = (int*)malloc(sizeof(int) * N);
		for (i = 0; i < N; i++)
		{
			// 설정한 동적메모리에 막대기의 크기를 입력한다.
			scanf("%d", &P);
			if (P >= 1 && P <= 100000) M[i] = P;
			else
			{
				return 0;
			}

		}
		// 맨마지막 입력된 막대기를 체크막대기로 정하고
		// 체크 막대기보다 큰 막대기를 찾는다.
		cnt = 1;
		chk = M[N - 1];
		for (i = N - 2; i >= 0; i--)
			if (M[i] > chk)
			{
				cnt++;
				chk = M[i];
			}
		//결과 출력

		printf("\n %d", cnt);

		// 설정된 동적메모리 해제
		free(M);



	}
	return 0;
}
