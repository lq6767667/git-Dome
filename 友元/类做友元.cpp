#include <iostream>
#include <string>
using namespace std;

class Building
{
	friend class my_Friend;
public:

	Building()
	{
		living = "����";
		room = "����";
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
		//�������������
		building = new Building;
	}

	void vist()
	{
		cout << "my_Friend��������ڷ���Building���еģ�" << building->living << endl;

		cout << "my_Friend��������ڷ���Building���еģ�" << building->room << endl;//��Ҫ��Building����������Ϊ��Ԫ��

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