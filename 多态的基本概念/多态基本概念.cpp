#include <iostream>
using namespace std;

//�����ࣨ���ࣩ
class Animal
{
public:
	//�麯��
	virtual void spack()
	{
		cout << "������˵��" << endl;
	}
};

//è�ࣨ���ࣩ
class Cat : public Animal
{
public:
	//��д�� ��������ֵ ������ �����б�	Ҫ��ȫ�븸���麯����ͬ��virtual�ؼ��ʿ�д�ɲ�д
	void spack()
	{
		cout << "è��˵��" << endl;
	}
};

//���ࣨ���ࣩ
class Dog : public Animal
{
public:
	void spack()
	{
		cout << "����˵��" << endl;
	}
};
//==============================================================//

//��ַ���  �����ڱ���׶�ȷ��������ַ
//�����ִ����è˵������ô���������ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а󶨣�Ҳ���ǵ�ַ���

//��̬��̬��������
//1. �м̳й�ϵ
//2. ������д������麯��

//��̬��ʹ��
//����ָ�������ָ���������
void doSpack(Animal& animal)// Animal & animal = cat
{
	animal.spack();
}

void test()
{
	Cat cat;
	doSpack(cat);

	Dog dog;
	doSpack(dog);
}

int main()
{
	test();
	system("pause");
	return 0;
}
