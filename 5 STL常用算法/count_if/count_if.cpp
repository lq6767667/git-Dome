#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Greater20
{
public:
	bool operator()(int &val)
	{
		return val > 20;
	}
};
//ͳ��������������
void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	v.push_back(70);

	int num = count_if(v.begin(), v.end(), Greater20());

	cout << "�����д���20��Ԫ�ظ�����" << num << endl;
}


class Person
{
public:
	Person(const string &Name, const int &Age)
	{
		this->age = Age;
		this->name = Name;
	}

	int age;
	string name;
};

class GreaterPerson20
{
public:
	bool operator()(const Person &p)
	{
		return p.age > 20;
	}
};
//ͳ���Զ�����������
void test02()
{
	Person p1("�ŷ�", 35);
	Person p2("����", 111);
	Person p3("����", 40);
	Person p4("�ܲ�", 45);
	Person p5("����", 30);
	Person p6("����", 50);

	vector<Person> vP;
	vP.push_back(p1);
	vP.push_back(p2);
	vP.push_back(p3);
	vP.push_back(p4);
	vP.push_back(p5);
	vP.push_back(p6);

	int num = count_if(vP.begin(), vP.end(), GreaterPerson20());

	cout << "�����д���20������У�" << num << endl;
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}