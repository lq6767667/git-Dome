#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Person
{
public:
	Person(string Name, int Age)
	{
		this->name = Name;
		this->age = Age;
	}

	bool operator==(const Person& p)const
	{
		if (this->age == p.age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string name;
	int age;
 };

void test01()
{
	Person p1("关羽" , 45);
	Person p2("曹操", 50);
	Person p3("刘备", 45);
	Person p5("孙权", 50);
	Person p6("司马懿", 45);

	Person p7("诸葛亮", 45);

	vector<Person> vp;
	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);
	vp.push_back(p5);
	vp.push_back(p6);

	int num = count(vp.begin(), vp.end(), p7);

	cout << "与诸葛亮同岁的有：" << num << "人" << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}
