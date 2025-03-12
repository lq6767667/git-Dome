#include <iostream>
#include <list>
#include <string>
//案例描述：将Person自定义数据数据类型进行排序
//排序规则：按照年龄进行升序，若年龄相同按照身高进行降序
using namespace std;
class Person
{
public:
	Person(string name, int age, int height)
	{
		m_name = name;
		m_age = age;
		m_height = height;
	}
	~Person()
	{

	}

public:
	string m_name;
	int m_age;
	int m_height;
};


bool Personcompare(const Person& p1, const Person& p2)
{
	if (p1.m_age == p2.m_age)
	{
		return p1.m_height > p2.m_height;
	}
	return p1.m_age < p2.m_age;
}

void test01()
{
	list<Person> p;
	Person p1("刘备", 35, 190);
	Person p2("关羽", 34, 187);
	Person p3("张飞", 35, 195);
	Person p4("赵云", 29, 200);
	Person p5("周瑜", 35, 180);
	Person p6("诸葛", 50, 190);

	p.push_back(p1);
	p.push_back(p2);
	p.push_back(p3);
	p.push_back(p4);
	p.push_back(p5);
	p.push_back(p6);

	for(list<Person>::const_iterator it=p.begin(); it!=p.end(); it++)
	{
		cout << "姓名：" << it->m_name << " 年龄：" << it->m_age << " 身高：" << it->m_height << endl;
	}

	cout << "--------------------------------" << endl;
	p.sort(Personcompare);

	for (list<Person>::const_iterator it = p.begin(); it != p.end(); it++)
	{
		cout << "姓名：" << it->m_name << " 年龄：" << it->m_age << " 身高：" << it->m_height << endl;
	}
}

int main()
{
	test01();
	system("pause");
	return 0;
}