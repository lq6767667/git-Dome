#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

//���ò����㷨

class Person
{
public:
	Person(string name,int age) : m_name(name), m_age(age)
	{

	}

	//���� == �õײ�find֪����ζԱ�person��������
	bool operator==(const Person& p)const
	{
		if (this->m_age == p.m_age && this->m_name == p.m_name)
		{
			return true;
		}
		return false;
	}

	int m_age;
	string m_name;
};
//�Զ����������͵Ĳ���
void test02()
{
	vector<Person> vp;

	Person p1("Lqq", 24);
	Person p2("aaa", 25);
	Person p3("bbb", 26);
	Person p4("ccc", 23);
	Person p5("ddd", 29);

	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);
	vp.push_back(p4);
	vp.push_back(p5);

	Person f_p("Lqq", 24);

	vector<Person>::iterator it = find(vp.begin(), vp.end(), f_p);
	if (it != vp.end())
	{
		cout << "���ҵ���" << it->m_name << endl;
	}
	else
	{
		cout << "δ���ҵ����ݣ�" << endl;
	}
}


//�����������͵Ĳ���
void test01()
{
	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find(v.begin(), v.end(), 60);
	if (it != v.end())
	{
		cout << "���ҵ���" << *it << endl;
	}
	else
	{
		cout << "δ���ҵ����ݣ�" << endl;
	}

}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}