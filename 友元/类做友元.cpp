#include <iostream>
#include <string>
using namespace std;

class Building
{
	friend class my_Friend;
public:

	Building()
	{
		living = "客厅";
		room = "卧室";
	}

public:
	string living;
private:
	string room;
};

class my_Friend
{

public:
	my_Friend()
	{
		//创建建筑物对象
		building = new Building;
	}

	void vist()
	{
		cout << "my_Friend这个类正在访问Building类中的：" << building->living << endl;

		cout << "my_Friend这个类正在访问Building类中的：" << building->room << endl;//需要在Building中声明该类为友元类

	}

public:
	Building* building;
};

void test01()
{
	my_Friend p1;
	p1.vist();
}
int main()
{
	test01();
	system("pause");
	return 0;
}