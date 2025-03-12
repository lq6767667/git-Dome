#include <iostream>
using namespace std;

class Person
{
public:
	Person(int age)
	{//当形参和成员变量重名时，用this指针来区分
		this->age = age;
	}

	Person& PersonAddPerson(Person p)
	{
		this->age += p.age;
		//返回对象本身
		return *this;
	}

	int age;
};

void test01()
{
	Person p1(10);
	cout << "p1的年龄为：" << p1.age << endl;

}

void test02()
{
	Person p1(10);
	Person p2(p1);

	//链式编程思想
	
	//解释为何不可值返回：值返回的话，就不是返回对象的本体，因为值返回调用的是拷贝构造函数，会复制一份新的数据出来也就是会新建一个p2'，也就是
	//复制了p2的值，但是返回来的是p2'，不是p2本体，因此在用p2.age打印数据时，不能得到正确结果
	p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);

	cout << "p2的年龄为：" << p2.age << endl;

}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}