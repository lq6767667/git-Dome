#include <iostream>
using namespace std;

class MyInteger
{

	friend ostream& operator<<(ostream& cout, MyInteger Int);

public:
	MyInteger()
	{
		num = 0;
	}

	//ǰ�õݼ�
	MyInteger& operator--()
	{
		num--;
		return *this;
	}
	//���õݼ�
	MyInteger operator--(int)//int��ռλ����
	{
		MyInteger temp = *this;//�ȼ�¼��ǰ�����ֵ��Ȼ���ñ����ֵ��1�����Ƿ��ص�����ǰ��ֵ�����غ�--

		num--;

		return temp;

	}

public:
	int num;
};

//�������������
ostream& operator<<(ostream& cout, MyInteger Int)
{
	cout << Int.num;
	return cout;
}

void test()
{
	MyInteger m_int;

	cout << m_int-- << endl;
	cout << m_int << endl;

}

int main()
{
	test();
	system("pause");
	return 0;
}