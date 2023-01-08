#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h> // malloc(), free()용
#include <string.h> // strlen(), strcpy()

int main()
{
	int T = 0; // 문자열의 개수를 입력받는다.
	char str[255];// 임의의 문자열을 입력할 문자열 배열변수
	int r = 0, c = 0; // 행, 열변수
	int c1 = 0, c2 = 0;
	int sen1 = 0, sen2 = 0, sen3 = 0; // 회문, 유사회문, 비회문 변수
	int i = 0;// 반복변수
	int N = 0;// 문자열의 길이 변수

	// 문자열 개수 입력 받기
	scanf("%d%*c", &T);

	// 1<=T<=30 조건에 맞으면 작업을 계속한다.
	if (T >= 1 && T <= 30)
	{
		//입력된 문자열의 개수만큼의 문자열을 입력할 동적메모리를 설정
		char** M = (char**)malloc(sizeof(char*) * T);
		for (r = 0; r < T; r++)
		{
			//문자열을 입력한다.
			scanf("%s%*c", str);

			if (strlen(str) >= 3 && strlen(str) <= 100000) // 문자열의 길이 반환
			{
				M[r] = (char*)malloc(sizeof(char) * (strlen(str) + 1));
				strcpy(M[r], str);
			}
			else
				return 0;
		}

		// 입력된 문자열이 회문, 유사회문, 둘다 아닌지 체크한다.
		for (r = 0; r < T; r++)
		{
			// 문자열 중 틀린 글자가 나오면 회문이 아님
			// 틀린 문자의 위치를 회문체큼변수에 저장
			// 회문이면 출력

			sen1 = -1; // 회문체크변수
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
				//유사회문 또는 비회문인지 체크한다.
				c1 = c2 = 0;
				sen2 = 0;
				sen3 = 0;
				char* senStr1 = (char*)malloc(sizeof(char) * (strlen(M[r] + 1)));
				char* senStr2 = (char*)malloc(sizeof(char) * (strlen(M[r] + 1)));// 비교할 문자열 변수

				// 틀린 위치의 문자를 뺀 문자들을 각각의 변수에 저장한다.
				for (i = 0; i < N - 1; i++)
				{
					if (i != sen1) senStr1[c1++] = M[r][i];
					if (i != N - 1 - sen1) senStr2[c2++] = M[r][i];
				}

				// 각각의 문자들을 비교하여 유사회문, 비회문을 체크한다.
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



