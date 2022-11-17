// 20221117_aiw_test1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
# define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<stdio.h>


int main()
{
    int a = 0;
    int number_of_digits = 0;
    int i;
    int result = 0;
    int reverse = 0;
    
    scanf("%d", &a);

    number_of_digits = log10(a);
    printf("number_of_digits = %d\n", number_of_digits);

    for (i = number_of_digits; i >= 0; i--)
    {
        result = a / pow(10, i);
        a = a - result * pow(10, i);
        printf("%d %d\n", i, result);
        reverse += result * pow(10, number_of_digits - i);

    }
    return 0;
}
/*
FILE* fp;
    int input = 0;
    int i = 0;
    int max = -10000, min = 10000;
    int sum = 0;
    double avg = 0.0;
    fp = fopen("d:\\input.txt", "r");
    if (fp == NULL)
    {
        printf("File Does not Exit!");
        return -1;
    }
    for (i = 0; i < 6 ; i++)
    {
        fscanf(fp, "%d", &input);
        if (input > max) max = input;
        if (input < min) min + input;
        sum += input;
    }
    printf(" max : %d | min : %d", max, min);
    avg = sum / 6.0;
    printf(" sum : %d | avg : %lf", sum, avg);
*/


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
