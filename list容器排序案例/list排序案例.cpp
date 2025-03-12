#include <iostream>
#include <list>
#include <string>
//������������Person�Զ��������������ͽ�������
//������򣺰����������������������ͬ������߽��н���
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
	Person p1("����", 35, 190);
	Person p2("����", 34, 187);
	Person p3("�ŷ�", 35, 195);
	Person p4("����", 29, 200);
	Person p5("���", 35, 180);
	Person p6("���", 50, 190);

	p.push_back(p1);
	p.push_back(p2);
	p.push_back(p3);
	p.push_back(p4);
	p.push_back(p5);
	p.push_back(p6);

	for(list<Person>::const_iterator it=p.begin(); it!=p.end(); it++)
	{
		cout << "������" << it->m_name << " ���䣺" << it->m_age << " ��ߣ�" << it->m_height << endl;
	}

	cout << "--------------------------------" << endl;
	p.sort(Personcompare);

	for (list<Person>::const_iterator it = p.begin(); it != p.end(); it++)
	{
		cout << "������" << it->m_name << " ���䣺" << it->m_age << " ��ߣ�" << it->m_height << endl;
	}
}

int main()
{
	test01();
	system("pause");
	return 0;
}