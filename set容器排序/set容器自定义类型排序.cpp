#include <iostream>
#include <set>
#include <string>
using namespace std;

class Person
{
public:
	Person(const string name, const int age)
	{
		m_name = name;
		m_age = age;
	}
	~Person()
	{

	}

public:
	string m_name;
	int m_age;
};

class comparePerson
{
public:
	bool operator()(const Person &p1,const Person &p2)const
	{
		/*if (p1.m_age == p2.m_age)
		{
			return p1.m_age < p2.m_age;   
		}*/
		return p1.m_age > p2.m_age;
	}

};
void test01()
{
	Person p1("�ŷ�", 45);
	Person p2("����", 30);
	Person p3("����", 35);
	Person p4("�ܲ�", 55);
	Person p5("���", 25);
	Person p6("����", 36);

	set<Person, comparePerson> s;
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);
	s.insert(p6);

	for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "������" << it->m_name << "���䣺" << it->m_age << endl;
	}

}

int main()
{
	test01();
	system("pause");
	return 0;
}