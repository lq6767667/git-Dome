#include <iostream>
using namespace std;


class Person
{
public:
	Person(int age)
	{
		m_A = new int(age);
	}

	~Person()
	{
		if (m_A != NULL)
		{
			delete m_A;
			m_A = NULL;
		}
	}

	//÷ÿ‘ÿ∏≥÷µ‘ÀÀ„∑˚
	Person& operator=(Person& p)
	{
		if (m_A != NULL)
		{
			delete m_A;
			m_A = NULL;
		}
		m_A = new int(*p.m_A);

		return *this;
	}
public:
	int* m_A;
};


void test()
{
	Person p1(10);
	Person p2(12);
	Person p3(13);
	p1 = p2= p3;

	cout << "p1.Age= " << *p1.m_A << endl;
	cout << "p2.Age= " << *p2.m_A << endl;
	cout << "p3.Age= " << *p3.m_A << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}
