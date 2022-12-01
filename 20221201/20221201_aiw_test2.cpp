// 20221201_aiw_test2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include <iostream>
#include <stdio.h>

//C언어
#include<stdlib.h> //rand(), srand()
#include<time.h> //time()
#include<math.h>

int find_max(int d, int e, int f);
int find_min(int d, int e, int f);
double find_min_double(double d, double e, double f);
double find_max_double(double d, double e, double f);

int main()
{
	int a = 0, b = 0, c = 0;
	int min = 0, max = 0;
	int random_number = 0;
	int i = 0, median_value = 0;
	double sum = 0.0, avg = 0.0;
	int input = 0.0;
	double dist1 = 0.0, dist2 = 0.0, dist3 = 0.0;
	double min_d = 0.0;
	double max_d = 0.0;
	
	srand((unsigned int)time(NULL)); //seed값으로 현재시간 부여
	scanf("%d %d %d%", &a, &b, &c);

	min = find_min(a, b, c);
	max = find_max(a, b, c);
	min = -5, max = 5;
	for (i = 0; i < 10; i++)
	{
		random_number = rand() % (max - min + 1) + min;
		printf("난수[%d] : %d\n", i, random_number);
		sum += random_number;
	}
	
		avg = sum / 10;
		printf("sum=%6.3lf | avg = %6.3lf \n", sum, avg);

		min = find_min_double(dist1, dist2, dist3);
		printf("%d", min);

		dist1 = fabs(a - avg);
		dist2 = fabs(b - avg);
		dist3 = fabs(c - avg);
		printf("%6.3lf %6.3lf %6.3lf \n", dist1, dist2, dist3);

		min_d = find_min_double(dist1, dist2, dist3);
		printf("min : 6.31\n", min_d);

		max_d = find_max_double(dist1, dist2, dist3);
		printf("max : 6.31\n", max_d);

		if (min_d == dist1)
		{
			printf("중간값은 %d \n", a);
			median_value = a;
		}


		if (min_d == dist2)
		{
			printf("중간값은 %d\n", b);
			median_value = b;
		}
		if (min_d == dist3)
		{
			printf("중간값은 %d\n", c);
			median_value = c;
		}
		random_number = rand() % (max - min + 1) + min;
		for (int i = 0; i < 10; i++)
		{
			printf("숫자를 입력하세요:\n");
			scanf("%d", &input);
			if (random_number > input)
			{
				printf("입력된 숫자의 값이 랜덤 값보다 작습니다.\n");
			}
			else if (random_number < input)
			{
				printf("입력된 숫자의 값이 랜덤 값보다 큽니다.\n");
			}
			else
			{
				printf("입력된 숫자의 값이 랜덤 값과 같습니다.\n");
				return 0;
			}
			
	}
		printf("10번에 정답을 못맞췄습니다.");

		return 0;
}//난수 발생


	





int find_max(int d, int e, int f)
{
	int max = d;
	max = (d > max) ? d : max;
	max = (e > max) ? e : max;
	max = (f > max) ? f : max;

	return max;
}
int find_min(int d, int e, int f)
{
	int min = d;

	min = (d < min) ? d : min;
	min = (e < min) ? e : min;
	min = (f < min) ? f : min;

	return min;
}
double find_min_double(double d, double e, double f)
{
	double min = d;

	min = (d < min) ? d : min;
	min = (e < min) ? e : min;
	min = (f < min) ? f : min;

	return min;
}
double find_max_double(double d, double e, double f)
{
	int max = d;
	max = (d > max) ? d : max;
	max = (e > max) ? e : max;
	max = (f > max) ? f : max;

	return max;
}









// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
