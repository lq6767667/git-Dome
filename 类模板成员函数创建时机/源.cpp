#include <iostream>
using namespace std;

//��ģ���еĳ�Ա�����ڵ���ʱ�Żᴴ��
class Person1
{
public:
	void myShow1()
	{
		cout << "Person1 show" << endl;
	}
};

class Person2
{
public:
	void myShow1()
	{
		cout << "Person2 show" << endl;
	}
};

//��ģ��
template<class T> class muban
{
public:
	T obj;

	void show1()
	{
		obj.myShow1();
	}
	void show2()
	{
		obj.myShow2();
	}
};

void test()
{
	muban<Person1> m;
	m.show1();
	//m.show2();
}

int main()
{
	test();
	system("pause");
	return 0;
}
