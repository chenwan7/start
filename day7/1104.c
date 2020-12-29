#include <stdio.h>
#include <windows.h>

//"abcd1234"
void StrReverseHelper(char *str,  char *start,  char *end)
{
	if (start >= end){
		return;
	}
	char temp = *start;
	*start = *end;
	*end = temp;

	StrReverseHelper(str, ++start, --end);
}
void StrReverse(char *str,int len)
{
	char *start = str;
	char *end = str + strlen(str) - 1;

	StrReverseHelper(str, start, end);
	//if (*str == '\0'){
	//	return;
	//}
	//StrReverse(str + 1, len,res, start+1);
	//res[len - start-1] = *str;
	//printf("%c", *str);
}

int fun(int n, int m)
{
	if (m == 1){
		return n;
	}
	return n * fun(n, m - 1);
}



int DigitSum(int x)
{
	if (x > 9){
		return DigitSum(x / 10) + x % 10;
	}
	return x;
}

int main()
{
	//计算一个数的每位之和（递归实现）
	int x = 1729;
	int res = DigitSum(x);
	printf("%d\n", res);

	//递归实现n的k次方
	//n^10;
	//n *n^9
	//int n = 2;
	//int m = 10;
	//int res = fun(n, m);
	//printf("%d\n", res);
	//字符串逆序（递归实现）
	//const char * str = "abcd1234";
	//char str[] = "abcd1234";
	////char res[16] = { '\0' };
	//printf("before: %s\n", str);
	////StrReverse(str, strlen(str),res, 0);
	//
	//StrReverse(str, strlen(str));

	//printf("after: %s\n", str);

	//int i = 1;
	//int ret = (++i) + (++i) + (++i);
	//printf("%d\n", ret);
	//printf("%d\n", i);

	//int i = 10;
	//i = i-- - --i * (i = -3) * i++ + ++i;
	//printf("i = %d\n", i);
	//float f = 3.14f;
	//int num = (int)f;
	


	//char c = 1;
	//printf("%u\n", sizeof(c)); //1
	//printf("%u\n", sizeof(+c)); //4
	//printf("%u\n", sizeof(!c)); //


	//char a = 255;
	//unsigned char b = -1;

	//printf("%u\n", a);
	//printf("%u\n", b);


	//int a = -1;
	//unsigned int b = -1;
	//printf("%u\n", a); //-1
	//printf("%d\n", b); //2^32-1

	system("pause");
	return 0;
}