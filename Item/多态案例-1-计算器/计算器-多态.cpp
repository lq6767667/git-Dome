#include <iostream>
using namespace std;

//使用普通方法实现
class Courter//计算器
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
//多态方式
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

//加法运算类
class Addopera : public Courter_2
{
public:
	int getResult()
	{
		return n_num1 + n_num2;
	}
};

//减法运算类
class Subopera : public Courter_2
{
public:
	int getResult()
	{
		return n_num1 - n_num2;
	}
};

//乘法运算类
class Mulopera : public Courter_2
{
public:
	int getResult()
	{
		return n_num1 * n_num2;
	}
};

//公共接口
//int getResult(Courter_2* cour)
//{
//	return cour->operation();
//}

void test1()//普通方法
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
	//加法
	Courter_2* add = new Addopera;// new Addopera创建一个加法计算器的对象，用Courter_2*运算器去指向它（用父类的指针去指向子类的对象，这个时候就已经发生多态了）
	add->n_num1 = 4;
	add->n_num2 = 5;
	cout << add->n_num1 << "+" << add->n_num2 << "=" << add->getResult() << endl;
	delete add;

	//减法
	add = new Subopera;
	add->n_num1 = 4;
	add->n_num2 = 5;
	cout << add->n_num1 << "-" << add->n_num2 << "=" << add->getResult() << endl;
	delete add;

	//乘法
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
