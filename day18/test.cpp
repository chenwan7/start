#include<iostream>//输入输出


using namespace std;//命名空间
int fun(int a=0, int b = 0, int c = 0)  //缺省参数  备胎
{
	return a + b + c;
}
void main()
{
	printf("result = %d\n", fun());
}

//void main()
//{
//	char ch;//= 'A';
//	int a;//= 100;
//	float f; //= 12.34f;
//
//
//	cout << ch<<endl;//printf  \n
//	cout << a << endl;
//	cout << f << endl;
//
//}



