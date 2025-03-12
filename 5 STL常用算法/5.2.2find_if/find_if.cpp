#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//1������������������
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
		cout << "δ���ҵ�ָ������" << endl;
	}
	else
	{
		cout << "���ҵ����ݣ�" << *it << endl;
	}
}

//�����Զ�����������

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
	Person p1(25, "С��");
	Person p2(15, "С��");
	Person p3(10, "С��");
	Person p4(20, "С��");
	Person p5(19, "С��");

	vector<Person> vP;
	vP.push_back(p1);
	vP.push_back(p2);
	vP.push_back(p3);
	vP.push_back(p4);
	vP.push_back(p5);

	//�����������20���ˣ���ֻ�᷵�ز��ҵ��ĵ�һ���˵ĵ�����
	vector<Person>::iterator it = find_if(vP.begin(), vP.end(), Greater20());

	if (it == vP.end())
	{
		cout << "δ���ҵ�������������" << endl;
	}
	else
	{
		cout << "���ҵ���" << it->name << it->age << endl;
	}

}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
 }