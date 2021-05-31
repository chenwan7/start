#include <iostream>
#include <vector>
#include <string>
using namespace std;

class parent
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