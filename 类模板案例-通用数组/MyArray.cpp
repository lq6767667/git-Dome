#include <iostream>
#include "MyArray.hpp"
#include <string>

void myPrintf(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test()
{
	MyArray<int> arr1(5);

	for (int i = 0; i < arr1.getCapacity(); i++)
	{
		arr1.push_back(i);
	}
	myPrintf(arr1);
	cout << "������" << arr1.getCapacity() << endl;
	cout << "��С��" << arr1.getSize() << endl;

	cout << "---------------------" << endl;
	
	MyArray<int> arr2(arr1);
	arr2.Pop_back();
	myPrintf(arr2);
	cout << "������" << arr2.getCapacity() << endl;
	cout << "��С��" << arr2.getSize() << endl;

	cout << "---------------------" << endl;
	//MyArray<int> arr3(100);
	//arr1 = arr3;
}



//�����Զ�����������
class Person
{
public:
	Person() {};
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void myPersonPrintf(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i].m_Name << " " << arr[i].m_Age << endl;;
	}
	cout << endl;
}

void test2()
{
	MyArray<Person> p_arr(5);//����һ������Ϊ5����������ΪPerson������
	Person p1("�����", 999);
	Person p2("�˽�", 888);
	Person p3("ɳɮ", 789);
	Person p4("��ɮ", 25);

	//�����ݲ���������
	p_arr.push_back(p1);
	p_arr.push_back(p2);
	p_arr.push_back(p3);
	p_arr.push_back(p4);

	//��ӡ
	myPersonPrintf(p_arr);

	cout << "������" << p_arr.getCapacity() << endl;
	cout << "��С��" << p_arr.getSize() << endl;
}

int main()
{
	//test();
	test2();
	system("pause");
	return 0;
}
