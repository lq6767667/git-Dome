#include <iostream>
using namespace std;

class Person 
{
public:

	static int m_Age;
	int m_phone;
};

int Person::m_Age = 0;

int main()
{

	const Person p1;

	p1.m_Age = 100;
	//p1.m_phone = 200;

	cout << p1.m_Age << endl;

	system("pause");
	return 0;
}