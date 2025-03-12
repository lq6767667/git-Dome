#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}
	Person(int age, int height)
	{
		cout << "Person的有参构造函数调用函数" << endl;
		m_Age = age;
		m_Height = new int(height);
	}

	//拷贝构造函数
	Person(const Person &p)
	{
		cout << "Person拷贝构造函数调用" << endl;
		m_Age = p.m_Age;
		//m_Height = p.m_Height; 在没有定义拷贝构造函数时，编译器默认实现的就是该行代码
		m_Height = new int(*p.m_Height);
	}
	//析构函数
	~Person()
	{
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
		cout << "Person析构函数调用" << endl;
	}

	int m_Age;
	int *m_Height;
};

void test01()
{
	Person p1(18,160);
	cout << "p1的年龄为：" << p1.m_Age << "身高为：" << *p1.m_Height << endl;
	
	Person p2(p1);//在没有定义拷贝构造函数时，由编译器使用默认的拷贝构造函数，值拷贝
	cout << "p2的年龄为: " << p2.m_Age << "身高为：" << *p2.m_Height << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
