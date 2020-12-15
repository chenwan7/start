#include <stdio.h>
#include <windows.h>

int get_max(int a, int b)
{
	if (a > b)
		return a;
	
	return b;
}

int sum(int a)
{
	int c = 0;
	static int b = 3;
	c += 1;
	b += 2;
	return(a + b + c);
}
int func(int a)
{
	int b;
	switch (a)
	{
		case 1:b = 30;
		case 2:b = 20;
		case 3:b = 16;
		default:b = 0;
	}
	return b;
}
int main()
{
	int x = 3;
	int y = 3;
	switch (x % 2)
	{
	case 1:
		switch (y)
		{
		case 0:
			printf("first");
		case 1:
			printf("second");
			break;
		default:printf("hello");
		}
	case 2:
		printf("third");
	}



	//printf("%d\n",func(1));
	//int i = 0;
	//for (i = 0; i < 10; i++)
	//{
	//	if (i = 5)
	//		printf("%d", i);
	//}


	//int i;
	//int a = 2;
	//for (i = 0; i < 5; i++)
	//{
	//	printf("%d,", sum(a));
	//}
	//
	//int num1 = 20;
	//int num2 = 30;
	//int max = get_max(num1, num2);
	//printf("max=%d\n",max);

	//printf("%d\n", strlen("c:\test\121"));
	
	system("pause");
	return 0;
}