#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person 默认构造函数的调用" << endl;
	}
	~Person()
	{
		cout << "Person 析构函数的调用" << endl;
	}

	Person(int age)
	{
		cout << "Person 有参构造函数的调用" << endl;
		P_Age = age;
	}

	Person(const Person& p)
	{
		cout << "Person 拷贝构造函数的调用" << endl;
		P_Age = p.P_Age;
	}


//private:
	int P_Age;
};



//1.使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
	Person p1(20);
	Person p2(p1);

	cout << "p2的年龄为：" << p2.P_Age << endl;
}
//2.值传递的方式给函数参数传值
void doWork(Person p)
{

}

void test02()
{
	Person p;
	doWork(p);//实参传给形参的时候会调用拷贝构造函数
}
//3.以值方式返回局部对象

Person doWork2()
{
	Person p1;
	return p1;
}

void test03()
{
	Person p = doWork2();
}

int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}