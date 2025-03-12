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
	cout << "容量：" << arr1.getCapacity() << endl;
	cout << "大小：" << arr1.getSize() << endl;

	cout << "---------------------" << endl;
	
	MyArray<int> arr2(arr1);
	arr2.Pop_back();
	myPrintf(arr2);
	cout << "容量：" << arr2.getCapacity() << endl;
	cout << "大小：" << arr2.getSize() << endl;

	cout << "---------------------" << endl;
	//MyArray<int> arr3(100);
	//arr1 = arr3;
}



//测试自定义数据类型
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
	MyArray<Person> p_arr(5);//定义一个容量为5，数据类型为Person的数组
	Person p1("孙悟空", 999);
	Person p2("八戒", 888);
	Person p3("沙僧", 789);
	Person p4("唐僧", 25);

	//将数据插入数组中
	p_arr.push_back(p1);
	p_arr.push_back(p2);
	p_arr.push_back(p3);
	p_arr.push_back(p4);

	//打印
	myPersonPrintf(p_arr);

	cout << "容量：" << p_arr.getCapacity() << endl;
	cout << "大小：" << p_arr.getSize() << endl;
}

int main()
{
	//test();
	test2();
	system("pause");
	return 0;
}
