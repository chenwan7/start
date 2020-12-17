#include<stdio.h>
#include<windows.h>
#include<math.h>


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
int main()
{
	int n = 5;
	int sp = is_prime(n);
		printf("%d\n", sp);


	system("pause");
	return 0;
}