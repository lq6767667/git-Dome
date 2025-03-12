#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray
{
private:
	T* pAddress;//数组
	int m_Capacity;//容量
	int m_Size;//数组大小

public:
	//构造函数
	MyArray(int capacity)
	{
		//cout << "构造函数调用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;

		this->pAddress = new T[m_Capacity];
	}

	//重载[]操作符 arr[0]
	T& operator[](int index)
	{
		/*if (index >= this->m_Size)
		{
			cout << "数组越界，无法访问" << endl;
			return *this;
		}*/

		return this->pAddress[index];
	}

	 //尾插法
	void push_back(const T & val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}
	//尾删法
	void Pop_back()
	{
		//让用户访问不到最后一个元素，即为尾删，逻辑删除
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	//获取数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}
	//获取数组大小
	int getSize()
	{
		return this->m_Size;
	}

	//析构函数
	~MyArray()
	{
		//cout << "析构函数调用" << endl;
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
	//拷贝构造函数
	MyArray(const MyArray& arr)
	{
		//cout << "拷贝构造函数调用" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;

		//深拷贝
		this->pAddress = new T[arr.m_Capacity];

		//将arr中的数据都拷贝过来
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operator=防止浅拷贝的问题
	MyArray& operator=(MyArray& arr)
	{
		//cout << "Operator=调用" << endl;
		//先判断原来堆区是否有数据，如果有先释放
		if (this->pAddress != NULL)
		{
			this->m_Capacity = 0;
			this->m_Size = 0;

			delete[] this->pAddress;
			this->pAddress = NULL;
		}
		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	

};
