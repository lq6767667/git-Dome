#include <iostream>
using namespace std;

//ʹ����ͨ����ʵ��
class Courter//������
{
public:
	int operating(string opera)
	{
		if (opera == "+")
		{
			return num1 + num2;
		}
		if (opera == "-")
		{
			return num1 - num2;
		}
		if (opera == "*")
		{
			return num1 * num2;
		}

	}

public:
	int num1;
	int num2;
};
//=========================================
//��̬��ʽ
class Courter_2
{
public:
	virtual int getResult()
	{
		return 0;
	}
public:
	int n_num1;
	int n_num2;
};

//�ӷ�������
class Addopera : public Courter_2
{
public:
	int getResult()
	{
		return n_num1 + n_num2;
	}
};

//����������
class Subopera : public Courter_2
{
public:
	int getResult()
	{
		return n_num1 - n_num2;
	}
};

//�˷�������
class Mulopera : public Courter_2
{
public:
	int getResult()
	{
		return n_num1 * n_num2;
	}
};

//�����ӿ�
//int getResult(Courter_2* cour)
//{
//	return cour->operation();
//}

void test1()//��ͨ����
{
	Courter cou;
	cou.num1 = 10;
	cou.num2 = 10;

	cout << cou.num1 << "+" << cou.num2 << "=" << cou.operating("+") << endl;
	cout << cou.num1 << "-" << cou.num2 << "=" << cou.operating("-") << endl;
	cout << cou.num1 << "*" << cou.num2 << "=" << cou.operating("*") << endl;
}

void test2()
{
	//�ӷ�
	Courter_2* add = new Addopera;// new Addopera����һ���ӷ��������Ķ�����Courter_2*������ȥָ�������ø����ָ��ȥָ������Ķ������ʱ����Ѿ�������̬�ˣ�
	add->n_num1 = 4;
	add->n_num2 = 5;
	cout << add->n_num1 << "+" << add->n_num2 << "=" << add->getResult() << endl;
	delete add;

	//����
	add = new Subopera;
	add->n_num1 = 4;
	add->n_num2 = 5;
	cout << add->n_num1 << "-" << add->n_num2 << "=" << add->getResult() << endl;
	delete add;

	//�˷�
	add = new Mulopera;
	add->n_num1 = 4;
	add->n_num2 = 5;
	cout << add->n_num1 << "*" << add->n_num2 << "=" << add->getResult() << endl;
	delete add;
}

int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}
