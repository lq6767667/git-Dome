#include <iostream>
using namespace std;
#include <string>

class Buliding
{

	friend void my_Friend(Buliding& b);

public:
	Buliding()
	{
		living = "客厅";
		room = "卧室";
	}
public:
	string living;
private:
	string room;
};

//全局函数
void my_Friend(Buliding& b)
{
	cout << "朋友正在访问：" << b.living << endl;

	cout << "朋友正在访问：" << b.room << endl;//访问的成员为私有成员，需要将该函数在类中声明为友元函数才可访问；
}


void test01()
{
	Buliding p;
	my_Friend(p);
}
int main()
{
	test01();
	system("pause");
	return 0;
}