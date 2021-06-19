#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;


//0603
struct A
{
	void foo(){printf("foo");}
	virtual void bar(){ printf("bar"); }
	A(){ bar(); }
};

struct B :A
{
	void foo(){ printf("b_foo"); }
	void bar(){ printf("b_bar"); }

};
template<class T> class Foo{
	T tVar;
public:
	Foo(T t) :tVar(t){}
};
template<class T> 
class FooDerived :public Foo<T>
{};
int func(int x)
{
	int count = 0;
	while (x)
	{
		count++;
		x = x&(x - 1);
	}
	return count;
}
int main()
{
	int a = func(9999);
	cout << a << endl;
	//FooDerived<int> d(5);

	/*
	int I = 1;
	if (I <= 0)
		printf("****\n");
	else
		printf("%%\n");*/
	//A *p = new B;
	//p->foo();
	//p->bar();
	return 0;
}



/*
//0602
class MY{
public:
	MY(int i = 0){ cout << 1; }
	MY(const MY&x){ cout << 2;}
	MY& operator=(const MY&x){ 
		cout << 3;
		return *this;
	}
	~MY(){ cout << 4; }
};
void func(char **m)
{
	++m;
	cout << *m << endl;

}

int fun(int a)
{
	a ^= (1 << 5) - 1;
	return a;
}
class Test{
public:
	int a;
	int b;
	virtual void fun(){}
		Test(int temp1 = 0, int temp2 = 0)
		{
			a = temp1;
			b = temp2;

		}
		int getA()
		{
			return a;
		}
		int getB()
		{
			return b;
		}
};


int main()
{
	Test obj(5, 10);
	int* pInt = (int*)&obj;
	*(pInt + 0) = 100;
	*(pInt + 1) = 200;

	cout << "a=" << obj.getA() << endl;
	cout << "b=" << obj.getB() << endl;

	//int n=fun(21);
	//cout << n << endl;
	/*
	static char *a[] = { "morning", "afternoon", "evening" };
	char **p;
	p = a;
	func(p);
	//MY obj1(1), obj2(2), obj3(obj1);
	return 0;
}
*/

/*
//0601

void main()
{
	int a = 1, b = 0, c = -1, d = 0;
	++a;
	++b;
	++c;
	d = a || b&& c;
	cout << d << endl;
	return;
}













/*
//0529

int main()
{
	char a = 0, ch;
	while ((ch = getchar()) != '\n')
	{
		if (a % 2 != 0 && (ch >= 'a' &&ch <= 'z'))
			ch = ch - 'a' + 'A';
		a++;
		putchar(ch);
	}
	printf("\n");
}
/*
int main(){
	int m = 0123, n = 123;
	printf("%o %o\n", m, n);
	return 0;
}



/*
//0528
void main()
{
	int n[][3] = { 10, 20, 30, 40, 50, 60 };
	int(*p)[3];
	p = n;
	cout << p[0][0] << "," << *(p[0] + 1) << "," << (*p)[2] << endl;
}







/*
int main()
{
	char p1[15] = "abcd", *p2 = "ABCD", str[50] = "xyz";
	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
	printf("%s", str);
}

//0601
/*
class A
{
public:
	A() :m(0){ test(); }
	virtual void func(){ cout << m << ' '; }
	void test(){ func(); }
public:
	int m;
};
class B :public A
{
public:
	B(){ test(); }
	virtual void func()
	{
		++m;
		cout << m << ' ';
	}

};

int main(int argc, char*argv[])
{
	A*p = new B;
	p->test();
	return 0;
}




/*
int main()
{
	int a[4] = { 1, 2, 3, 4 };
	int *ptr = (int*)(&a + 1);
	printf("%d", *(ptr - 1));
}



/*class parent
{
	int i;
protected:
	int x;
public:
	parent(){ x = 0; i = 0; }
	void change(){ x++; i++; }
	void display();
};

class son :public parent
{
public:
	void modify();
};
void parent::display(){ cout << "x=" << x << endl; }
void son::modify(){ x++; }


int main()
{
	son A; parent B;
	A.display();
	A.change();
	A.modify();
	A.display();
	B.change();
	B.display();

}

/*
int main()
{
	int p[][4] = { { 1 }, { 3, 2 }, { 4, 5, 6 }, { 0 } };

	cout << p[1][2] << endl;
}
/*
class A
{
	friend long fun(A s)
	{
		if (s.x < 3)
		{
			return 1;
		}
		return s.x + fun(A(s.x - 1));
	}
public:
	A(long a)
	{
		x = a--;
	}
private:
	long x;
};

int main()
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += fun(A(i));
	}
	cout << sum;
}
/*
int main(void)
{
	vector<int>array;
	array.push_back(100);
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(500);
	vector<int>::iterator itor;
	for (itor = array.begin(); itor != array.end(); itor++)
	{
		if (*itor == 300)
		{
			itor = array.erase(itor);
		}
	}
	for (itor = array.begin(); itor != array.end(); itor++)
	{
		cout << *itor << " ";
	}
	return 0;
}




/*#include<iostream>
using namespace std;


int func()
{
	int i, j, k = 0;
	for (i = 0, j = -1; j = 0; i++, j++)
	{
		k++;
	}
	return k;
}
int main()
{
	cout << (func());
}



/*#include <stdio.h> 
int main()
{
	char a[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 0 }, *p; int i;
	i = 8;
	p = a + i;
	printf("%s\n", p - 3);
}




/*#include<iostream>
using namespace std;
int main(){
	int n;
	while (cin >> n){
		int *a = new int[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int maxsum = 0x80000000, sum = 0;
		for (int i = 0; i < n; i++){
			sum += a[i];
			maxsum = maxsum>sum ? maxsum : sum;
			sum = sum < 0 ? 0 : sum;
		}
		cout << maxsum;
		delete[] a;
	}
	return 0;
}

/*#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1, s2;
	cin >> s2;
	while (cin >> s1)
	{
		s2 = s1 + " " + s2;
	}
	cout << s2 << endl;

	return 0;
}
*/



//I like beijing.