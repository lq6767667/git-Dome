#include <iostream>
using namespace std;
#include <string>

//��ӡ�����
class MyPrint
{
public:
	void operator()(string N)
	{
		cout << N << endl;
	}

};

//���������
class myAdd
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};

void test()
{
	MyPrint p1;
	p1("LQQ");
	MyPrint()("Qing");//��������
}

void test2()
{
	int a = myAdd()(2, 3);
	cout << myAdd()(2, 3) << endl;
}

int main()
{
	test();
	test2();
	system("pause");
	return 0;
}