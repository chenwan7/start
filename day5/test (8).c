#include <stdio.h>
#include <assert.h>
#include <windows.h>

#pragma warning(disable:4996)

void Reverse(char *str, int start, int end)
{
	assert(str);

	while (start < end){
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++, end--;
	}
}
//abcd
char *LeftMove(char *str, int len, int num)
{
	assert(str);
	num %= len;
	if (num == 0)
		return str;
	//""
	//f2

	Reverse(str, 0, num-1);
	Reverse(str, num, len - 1);//[]
	Reverse(str, 0, len - 1);

	return str;
	//f1
	//num %= len;
	//while (num){
	//	char temp = str[0];
	//	for (int j = 0; j < len - 1; j++){
	//		str[j] = str[j + 1];
	//	}
	//	str[len - 1] = temp;
	//	num--;
	//}
	//return str;
}
int FindData(int mix[][3], int row, int col, int target)
{
	assert(mix);

	int i = 0;
	int j = col - 1;
	while (i < row && j >= 0){
		if (target > mix[i][j]){
			i++;
		}
		else if (target < mix[i][j]){
			j--;
		}
		else{
			return 1;
		}
	}

	return 0;
}

struct stu{
	char name[32];
	int age;
	char sex; //f,m
};

void *my_memmove(void *dst, const void *src, int n)
{
	assert(dst);
	assert(src);

	char *_src = (char*)src;
	char *_dst = (char*)dst;

	if (_dst > _src && _dst < _src + n){
		//right -> left
		_src = _src + n - 1;
		_dst = _dst + n - 1;

		while (n){
			*_dst = *_src;
			_dst--;
			_src--;
			n--;
		}
	}
	else{
		//left -> right
		while (n){
			*_dst = *_src;
			_dst++;
			_src++;
			n--;
		}
	}
	return dst;
}


int main()
{
	char str[16] = "abcdefg";
	//char buf[16];
	int len = strlen(str)+1;
	//memcpy(str, str+1, len);
	//memcpy(str+1, str, len);

	//memmove(str, str + 1, len);
	memmove(str+1, str, len);

	printf("%s\n", str);



	//int a[5] = { 0 };

	//memset(a, 1, sizeof(a));

	//for (int i = 0; i < 5; i++){
	//	printf("%d\n", a[i]);
	//}

	//char buffer1[] = "DWgaOtP12df0";
	//char buffer2[] = "DWGAOTP12DF0";
	//int n;
	//n = memcmp(buffer1, buffer2, sizeof(buffer1));
	//if (n>0) printf("'%s' is greater than '%s'.\n", buffer1, buffer2);
	//else if (n<0) printf("'%s' is less than '%s'.\n", buffer1, buffer2);
	//else printf("'%s' is the same as '%s'.\n", buffer1, buffer2);










	//const char *str = "hello string";
	//char buf[16] = { 0 };
	//memmove(buf, str, strlen(str)+1);

	//memcpy(buf, str, strlen(str)+1);

	//struct stu tom = { "tom", 21, 'f' };

	//struct stu peter;

	//int a[] = { 1, 2, 3, 4, 5 };
	//int b[5] = { 0 };
	//memcpy(b, a , sizeof(a));

	//memcpy(&peter, &tom, sizeof(tom));






	//字符是数字

	//char c = 'a';
	//printf("%c\n", c - ('a' - 'A'));




	//char c = '9';

	//if (c >= '0' && c <= '9'){
	//	printf("yes\n");
	//}
	//else{
	//	printf("no!\n");
	//}





	//杨氏矩阵
	//题目内容 :
	//有一个数字矩阵，矩阵的每行从左到右是递增的，
	//矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
	//int n = 6;
	//int mix[3][3] = { 
	//	{1,2,3},
	//	{4,5,6},
	//	{7,8,9}
	//};
	//int res = FindData(mix, 3, 3, 19);
	//printf("%d\n", res);
	//char str[] = "abcd1234";
	//char sub[] = "cd1234ab";
	//int len = strlen(str);
	//if (len != strlen(sub)){
	//	return 1;
	//}
	//for (int i = 0; i < len; i++){
	//	LeftMove(sub, len, i);
	//	if (strcmp(str, sub) == 0){
	//		printf("yes!\n");
	//		break;
	//	}
	//}


	/*char *res = LeftMove(str,strlen(str),39);
	printf("%s\n", res);*/


	//字符串左旋
	//题目内容 :
	//实现一个函数，可以左旋字符串中的k个字符。
	//例如：
	//	ABCD左旋一个字符得到BCDA
	//	ABCD左旋两个字符得到CDAB


	system("pause");
	return 0;
}