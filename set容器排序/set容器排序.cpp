#include <iostream>
#include <set>
using namespace std;

class Mysort
{
public:
	bool operator()(int v1,int v2)const		//在vs2019中需要加const进行修饰，否则会报错，原因是在调用仿函数的时候，调用对象的数据有可能会被修改，因此需要使用const限定调用函数的set对象不被修改。
	{
		return v1 > v2;
	}
};

void test01()
{
	set<int> s1;

	s1.insert(23);
	s1.insert(31);
	s1.insert(10);
	s1.insert(35);
	s1.insert(50);

	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	set<int, Mysort> s2;

	s2.insert(23);
	s2.insert(31);
	s2.insert(10);
	s2.insert(30);
	s2.insert(50);

	for (set<int>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}