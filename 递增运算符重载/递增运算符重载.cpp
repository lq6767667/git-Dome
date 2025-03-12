#include <iostream>
using namespace std;

class MyInteger
{

	friend ostream& operator<<(ostream& cout, MyInteger Int);

public:
	MyInteger()
	{
		num = 0;
	}

	//前置递减
	MyInteger& operator--()
	{
		num--;
		return *this;
	}
	//后置递减
	MyInteger operator--(int)//int做占位参数
	{
		MyInteger temp = *this;//先记录当前本身的值，然后让本身的值减1，但是返回的是以前的值，返回后--

		num--;

		return temp;

	}

public:
	int num;
};

//左移运算符重载
ostream& operator<<(ostream& cout, MyInteger Int)
{
	cout << Int.num;
	return cout;
}

void test()
{
	MyInteger m_int;

	cout << m_int-- << endl;
	cout << m_int << endl;

}

int main()
{
	test();
	system("pause");
	return 0;
}