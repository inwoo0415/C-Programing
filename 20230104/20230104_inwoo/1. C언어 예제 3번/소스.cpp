
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int unit = 0;
	int unit2 = 0;
	int size_1 = 0;
	int cnt = 0;
	int chk = 0;
	int i = 0;
	scanf("%d", &unit);
	if (unit >= 2 && unit <= 100000) //막대기의 수가 2보다 작은건 말이 안됨 100000은 너무 커서 파일 크기가 오버남
	{
		int* unit2 = (int*)malloc(sizeof(int) * unit);
		for (i = 0; i < unit; i++)
		{
			scanf("%d", &size_1);
			if (size_1 >= 1 && size_1 <= 100000) unit2[i] = size_1;
			else
			{
				return 0;
			}
		}


		cnt = 1;
		chk = unit2[unit - 1];
		for (int i = unit - 2; i >= 0; i--)
			if (unit2[i] > chk)
			{
				cnt++;
				chk = unit2[i];
			}
		printf("\n%d", cnt);
		free(unit2);
	}
	return 0;
}