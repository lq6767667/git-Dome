#include <iostream>
using namespace std;

class Person
{
public:
	Person(int age)
	{//���βκͳ�Ա��������ʱ����thisָ��������
		this->age = age;
	}

	Person& PersonAddPerson(Person p)
	{
		this->age += p.age;
		//���ض�����
		return *this;
	}

	int age;
};

void test01()
{
	Person p1(10);
	cout << "p1������Ϊ��" << p1.age << endl;

}

void test02()
{
	Person p1(10);
	Person p2(p1);

	//��ʽ���˼��
	
	//����Ϊ�β���ֵ���أ�ֵ���صĻ����Ͳ��Ƿ��ض���ı��壬��Ϊֵ���ص��õ��ǿ������캯�����Ḵ��һ���µ����ݳ���Ҳ���ǻ��½�һ��p2'��Ҳ����
	//������p2��ֵ�����Ƿ���������p2'������p2���壬�������p2.age��ӡ����ʱ�����ܵõ���ȷ���
	p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);

	cout << "p2������Ϊ��" << p2.age << endl;

}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}