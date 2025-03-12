#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//1、查找内置数据类型
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test01()
{
	vector<int> v;

	for (int i=1; i<10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());

	if (it == v.end())
	{
		cout << "未查找到指定数据" << endl;
	}
	else
	{
		cout << "查找到数据：" << *it << endl;
	}
}

//查找自定义数据类型

class Person
{
public:
	Person(int Age, string Name)
	{
		this->age = Age;
		this->name = Name;
	}


	int age;
	string name;
};

class Greater20
{
public:

	bool operator()(const Person &p)
	{
		return p.age > 20;
	}
};

void test02()
{
	Person p1(25, "小明");
	Person p2(15, "小光");
	Person p3(10, "小亮");
	Person p4(20, "小李");
	Person p5(19, "小月");

	vector<Person> vP;
	vP.push_back(p1);
	vP.push_back(p2);
	vP.push_back(p3);
	vP.push_back(p4);
	vP.push_back(p5);

	//查找年龄大于20的人，但只会返回查找到的第一个人的迭代器
	vector<Person>::iterator it = find_if(vP.begin(), vP.end(), Greater20());

	if (it == vP.end())
	{
		cout << "未查找到符合条件的人" << endl;
	}
	else
	{
		cout << "查找到：" << it->name << it->age << endl;
	}

}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
 }