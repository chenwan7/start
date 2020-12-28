#include<stdio.h>
#include<windows.h>
#include<math.h>

//递归阶乘
int fact(int x)
{
	if (x <= 2){
		return x;
	}
	return x * fact(x - 1);

}
//循环阶乘
int Fac(int x)
{
	int ret = 1;
	for (int i = 2; i <= x; ++i)
	{
		ret *= i;
	}

	return ret;
}
//递归斐波那契
int fib(int n)
{
	if (n == 2 || n == 1){
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

//迭代斐波那契
int fib2(int n)
{
	int first = 1;
	int second = 1;
	int third = 1 ;
	while (n>2){
		third = first + second;
		first = second;
		second = third;
		n--;
	}
	return third;

}
//打印整型的每一位
void ShowNumber(unsigned int x)
{
	//倒序
	//while (x){
	//	printf("%d", x % 10);
	//	x /= 10;
	//正序
	if (x>9){
		ShowNumber(x / 10);
	}
	printf("%d ", x % 10);

}
//循环实现strlen
int Strlen(char *str)
{
	char *start = str;
	int count = 0;
	while (*start != '\0'){
		count++;
		start++;
	}
	return count;


}
//递归实现Strlen
int Strlen2(char *str)
{
	if(*str == '\0'){
		return 0;
	}
	return 1 + Strlen2(str + 1);

}


//最大公约数 辗转相减法
int fun(int x, int y)
{
	while (1){
		if (x > y){
			x -= y;
		}
		else if (x < y){
			y -= x;
		}
		else
			return x;

	}
}
//最大公约数 辗转相除法
int GreatCommonDivisor(int x, int y)
{
	int top = x > y ? y : x;
	for (; top >0 ; top--){
		if ((x %top == 0) && (y %top == 0)){
			break;
		}
	}
	return top;
}
//最大公约数 模运算
int GreatCommonDivisor3(int x, int y)
{
	while (x*y!=0){
		if (x > y){
			x %= y;
		}
		else if(x < y){
			y %= x;

		}
		else{
			return x;
		}

	}
	return x == 0 ? y : x;

}

//判断素数
int is_prime(int n)
{
	int i = 0;
	for (i = 2; i <= sqrt(n); i++)
	{
		if (0 == n%i)
		{
			return 0;
		}
	}
	return 1;
}

//是否为闰年
int leapyear(int year)
{
	if (((0 == year% 4) && (0 !=year % 100)) || (0 == year%400))
	{
		return 1;
	}
	else{
		return 0;
	}
}
//交换两个整数

void Swap(int *x,int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;


}

int main()
{
	//求n的阶乘
	//int result1 = fact(5);
	//printf("%d\n", result1);
	//int result2 = Fac(5);
	//printf("%d\n", result2);
	

	//斐波那锲
	//1 1 2 3 5 8 13 
	//int n = fib(40);
	//printf("%d\n", n);
	//int n2 = fib2(40);
	//printf("%d\n", n2);

   	//打印整型的每一位
	//unsigned int x = 12345;
	//ShowNumber(x);

	//Strlen循环
	//char *str = "1234abcd";
	//int len = Strlen(str);
	//printf("len:%d\n", len);
	//Strlen递归
	//char *str2 = "1234abcd";
	//int len2 = Strlen2(str2);
	//printf("len:%d\n", len2);

	//最大公约数 相减
	//int ret = fun(100, 75);
	//printf("%d\n", ret);	
	//最大公约数 相除
	//int ret2 = GreatCommonDivisor(100, 75);
	//printf("%d\n", ret2);
	//最大公约数 
	//int ret3 = GreatCommonDivisor3(100, 75);
	//printf("%d\n", ret3);

	//素数
	//int ret = is_prime(20);
	//printf("是否为素数%d\n", ret);
	//打印100~200之间的素数
	//int i = 0;
	//for (i = 100; i < 200;i++){
	//	if (is_prime(i)){
	//		printf("%d ", i);
	//	}
	//}
	//闰年
	int year = leapyear(2008);
	printf("%d\n", year);

	//交换两个整数
	//int *x = 10;
	//int *y = 20;
	//Swap(*x, *y);
	//printf("x=%d ,y=%d ", &x, &y);

	system("pause");
	return 0;
}