#include<stdio.h>
#include<windows.h>
#include<math.h>

//�ݹ�׳�
int fact(int x)
{
	if (x <= 2){
		return x;
	}
	return x * fact(x - 1);

}
//ѭ���׳�
int Fac(int x)
{
	int ret = 1;
	for (int i = 2; i <= x; ++i)
	{
		ret *= i;
	}

	return ret;
}
//�ݹ�쳲�����
int fib(int n)
{
	if (n == 2 || n == 1){
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

//����쳲�����
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
//��ӡ���͵�ÿһλ
void ShowNumber(unsigned int x)
{
	//����
	//while (x){
	//	printf("%d", x % 10);
	//	x /= 10;
	//����
	if (x>9){
		ShowNumber(x / 10);
	}
	printf("%d ", x % 10);

}
//ѭ��ʵ��strlen
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
//�ݹ�ʵ��Strlen
int Strlen2(char *str)
{
	if(*str == '\0'){
		return 0;
	}
	return 1 + Strlen2(str + 1);

}


//���Լ�� շת�����
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
//���Լ�� շת�����
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
//���Լ�� ģ����
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

//�ж�����
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

//�Ƿ�Ϊ����
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
//������������

void Swap(int *x,int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;


}

int main()
{
	//��n�Ľ׳�
	//int result1 = fact(5);
	//printf("%d\n", result1);
	//int result2 = Fac(5);
	//printf("%d\n", result2);
	

	//쳲�����
	//1 1 2 3 5 8 13 
	//int n = fib(40);
	//printf("%d\n", n);
	//int n2 = fib2(40);
	//printf("%d\n", n2);

   	//��ӡ���͵�ÿһλ
	//unsigned int x = 12345;
	//ShowNumber(x);

	//Strlenѭ��
	//char *str = "1234abcd";
	//int len = Strlen(str);
	//printf("len:%d\n", len);
	//Strlen�ݹ�
	//char *str2 = "1234abcd";
	//int len2 = Strlen2(str2);
	//printf("len:%d\n", len2);

	//���Լ�� ���
	//int ret = fun(100, 75);
	//printf("%d\n", ret);	
	//���Լ�� ���
	//int ret2 = GreatCommonDivisor(100, 75);
	//printf("%d\n", ret2);
	//���Լ�� 
	//int ret3 = GreatCommonDivisor3(100, 75);
	//printf("%d\n", ret3);

	//����
	//int ret = is_prime(20);
	//printf("�Ƿ�Ϊ����%d\n", ret);
	//��ӡ100~200֮�������
	//int i = 0;
	//for (i = 100; i < 200;i++){
	//	if (is_prime(i)){
	//		printf("%d ", i);
	//	}
	//}
	//����
	int year = leapyear(2008);
	printf("%d\n", year);

	//������������
	//int *x = 10;
	//int *y = 20;
	//Swap(*x, *y);
	//printf("x=%d ,y=%d ", &x, &y);

	system("pause");
	return 0;
}