#include <stdio.h>
#include <windows.h>
#include <math.h>
#include<stdlib.h>
#include<time.h>

#pragma warning(disable:4996)

void menu()
{
	printf("******************************\n");
	printf("********   1.play   **********\n");
	printf("********   0.exit   **********\n");
	printf("******************************\n");

}
void game()
{
	int ret = rand() % 100 + 1;
	int num = 0;
	while (1)
	{
		printf("猜数字游戏：>");
		scanf("%d", &num);
		if (num == ret)
		{
			printf("恭喜你，你猜对了！\n");
			break;
		}
		else if (num > ret)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("猜小了\n");
		}
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int key = 7;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]);
	
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid]>key)
		{
			right = mid;
		}
		else if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else
		{
			printf("找到了，下标是：%d\n", mid);
			break;
		}
	}
	if (left >= right)
		printf("找不到\n");


	//int input = 0;
	//srand((unsigned int)time(NULL));
	//do
	//{
	//	menu();
	//	printf("请选择：>");
	//	scanf("%d", &input);
	//	switch (input)
	//	{
	//		case 1:
	//			game();
	//			break;
	//		case 0:
	//			printf("退出游戏\n");
	//			break;
	//		default:
	//			printf("选择错误\n");
	//			break;
	//	}
	//} 
	//while (input);

	//int a = 0, b = 0;
	//for (a = 1, b = 1; a <= 100; a++)
	//{
    //		if (b >= 20)
	//		break;
	//	if (b % 3 == 1)
	//	{
	//		b = b + 3;
	//		continue;
	//	}
	//	b = b - 5;
	//}
	//printf("%d\n", a);
//	int i = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			printf(" %d*%d=%2d", i, j, i*j);
//		}
//		printf("\n");
//	}
	//int arr[10] = { 0 };
	//int i = 0;
	//int max = 0;
	//for (i = 0; i < 10; i++)
	//{
	//	scanf("%d", &arr[i]);
	//}
	//max = arr[0];
	//for (i = 1; i < 10; i++)
	//{
	//	if (arr[i]>max)
	//		max = arr[i];
	//}
	//printf("max=%d\n", max);

//	int i = 0;
//	double sum = 0.0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += flag*1.0 / i;
//		flag = -flag;
//	}
//	printf("%lf\n", sum);

	//int i = 0;
	//int count = 0;

	//for (i = 1; i <= 100; i++)
	//{
	//	if (i % 10 == 9)
	//		count++;
	//	if (i / 10 == 9)
	//		count++;

	//}
	//printf("%d\n", count);


	//int i = 0;
	//int count = 0;

	//for (i = 101; i <= 200; i += 2)
	//{
	//	int j = 0;
	//	for (j = 2; j <= sqrt(i); j++)
	//	{
	//		if (i%j == 0)
	//		{
	//			break;
	//		}
	//	}
	//	if (j > sqrt(i))
	//	{
	//		count++;
	//		printf("%d ", i);
	//	}
	//}
	//printf("\ncount=%d\n", count);

	//int year = 0;
	//for (year = 1000; year <= 2000; year++)
	//{
	//	if (year % 4 == 0)
	//	{
	//		if (year % 100 != 0)
	//		{
	//			printf("%d ", year);
	//		}
	//	}
	//	if (year % 400 == 0)
	//	{
	//		printf("%d ", year);
	//	}
	//}
//	int a = 10;
//	int b = 75;
//	int c = 0;
//	printf("%d\n", a%b);
//	while (c = a%b)
//	{
//		a = b;
//		b = c;
//	}
//	printf("%d\n", b);

	//int i = 0;
	//for (i = 1; i <= 100; i++)
	//{
	//	if (i % 3 == 0)
	//	{
	//		printf("%d ", i);
	//	}
	//}

	//int a = 5;
	//int b = 7;
	//int c = 9;
	//if (a < b)
	//{
	//	int tmp = a;
	//	a = b;
	//	b = tmp;
	//}
	//if (a < c)
	//{
	//	int tmp = a;
	//	a = c;
	//	c = tmp;
	//}
	//if (b < c)
	//{
	//	int tmp = b;
	//	b = c;
	//	c = tmp;
	//}
	//printf("a=%d b=%d c=%d\n", a, b, c);
	system("pause");
	return 0;
}