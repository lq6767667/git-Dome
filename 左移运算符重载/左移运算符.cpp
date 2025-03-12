#include <iostream>
using namespace std;

class Person
{

	friend ostream& operator<<(ostream& cout, Person& p);//全局函数做友元
public:
	Person(int m_A, int m_B)
	{
		this->m_A = m_A;
		this->m_B = m_B;
	}
private:
	int m_A;
	int m_B;
};


ostream& operator<<(ostream& cout, Person& p)
{
	cout << p.m_A << " " << p.m_B;
	return cout;
}


void test01()
{
	Person p(10, 12);

	cout << p << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}