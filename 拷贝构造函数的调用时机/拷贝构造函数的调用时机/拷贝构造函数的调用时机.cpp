#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person Ĭ�Ϲ��캯���ĵ���" << endl;
	}
	~Person()
	{
		cout << "Person ���������ĵ���" << endl;
	}

	Person(int age)
	{
		cout << "Person �вι��캯���ĵ���" << endl;
		P_Age = age;
	}

	Person(const Person& p)
	{
		cout << "Person �������캯���ĵ���" << endl;
		P_Age = p.P_Age;
	}


//private:
	int P_Age;
};



//1.ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void test01()
{
	Person p1(20);
	Person p2(p1);

	cout << "p2������Ϊ��" << p2.P_Age << endl;
}
//2.ֵ���ݵķ�ʽ������������ֵ
void doWork(Person p)
{

}

void test02()
{
	Person p;
	doWork(p);//ʵ�δ����βε�ʱ�����ÿ������캯��
}
//3.��ֵ��ʽ���ؾֲ�����

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