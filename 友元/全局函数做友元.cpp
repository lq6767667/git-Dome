#include <iostream>
using namespace std;
#include <string>

class Buliding
{

	friend void my_Friend(Buliding& b);

public:
	Buliding()
	{
		living = "����";
		room = "����";
	}
public:
	string living;
private:
	string room;
};

//ȫ�ֺ���
void my_Friend(Buliding& b)
{
	cout << "�������ڷ��ʣ�" << b.living << endl;

	cout << "�������ڷ��ʣ�" << b.room << endl;//���ʵĳ�ԱΪ˽�г�Ա����Ҫ���ú�������������Ϊ��Ԫ�����ſɷ��ʣ�
}


void test01()
{
	Buliding p;
	my_Friend(p);
}
int main()
{
	test01();
	system("pause");
	return 0;
}