#include <iostream>
#include <string>
#include <map>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	~Person()
	{

	}
	string m_name;
	int m_age;
};

class mySort
{
public:
	bool operator()(const int& age1, const int& age2)const
	{
		return age1 > age2;
	}
};

void test01()
{
	map<int, Person, mySort> mp;
	Person p1("刘备", 40);
	Person p2("关羽", 35);
	Person p3("张飞", 50);
	Person p4("曹操", 25);
	Person p5("周瑜", 30);

	mp.insert(make_pair(p1.m_age, p1));
	mp.insert(make_pair(p2.m_age, p2));
	mp.insert(make_pair(p3.m_age, p3));
	mp.insert(make_pair(p4.m_age, p4));
	mp.insert(make_pair(p5.m_age, p5));

	for (map<int, Person, mySort>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		cout << "姓名：" << it->second.m_name << " 年龄：" << it->first << endl;
	}
}

int main()
{
	test01();
	system("pause");
	return 0;
}