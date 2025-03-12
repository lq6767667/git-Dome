#include <iostream>
using namespace std;

class Person
{
public:
	Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}

	bool operator==(Person& p)
	{
		if (this->m_A == p.m_A && this->m_B == p.m_B)
		{
			return true;
		}
		return false;
	}

public:
	int m_A;
	int m_B;
};


void test()
{
	Person p1(2, 3);
	Person p2(3, 3);

	if (p1 == p2)
	{
		cout << "p1��p2���" << endl;
	}
	else
	{
		cout << "�����" << endl;
	}
}

int main() {
	test();
	system("pause");
	return 0;
}