#include <stdio.h>

int main(void)
{
	FILE* fp = 0;
	int i;
	int data1 = 0;
	double data2 = 0;
	char ch = 0;

	fp = fopen("data3.txt", "rt");

	if (fp == NULL)
	{
		//printf("File Writing Error!\n");
		puts("File Reading Error!\n");
		return -1;
	}
	else
	{
		printf("File Reading Success!\n");
	}
	for (i = 0; i < 2; i++)
	{
		
		fscanf(fp, "%d", &data1);
		printf("%d \n", data1);
	}
	for (i = 0; i < 2; i++)
	{

		fscanf(fp, "%lf", &data2);
		printf("%lf \n", data2);
	}


	return 1;

	
}

void example1(void)
{
	FILE* fp = 0;

	fp = fopen("data1.txt", "wt");

	if (fp == NULL)
	{
		//printf("File Writing Error!\n");
		puts("File Writing Error!\n");
		return ;
	}
	else
	{
		printf("File Writing Success!\n");
	}

	fputc('A', fp);
	fputc('B', fp);
	fputc('C', fp);
	fputs("\nDEF\n", fp);

	printf("%d\n", fclose(fp));

	return ;
}

void example2(void)
{
	FILE* fp = 0;
	int i;
	char ch = 0;

	fp = fopen("data2.txt", "rt");

	if (fp == NULL)
	{
		//printf("File Writing Error!\n");
		puts("File Reading Error!\n");
		return ;
	}
	else
	{
		printf("File Reading Success!\n");
	}
	for (i = 0; i < 7; i++)
	{
		ch = fgetc(fp);
		fscanf(fp, "%c", &ch);
		printf("%c \n", ch);
	}



	return ;
}