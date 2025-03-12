#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray
{
private:
	T* pAddress;//����
	int m_Capacity;//����
	int m_Size;//�����С

public:
	//���캯��
	MyArray(int capacity)
	{
		//cout << "���캯������" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;

		this->pAddress = new T[m_Capacity];
	}

	//����[]������ arr[0]
	T& operator[](int index)
	{
		/*if (index >= this->m_Size)
		{
			cout << "����Խ�磬�޷�����" << endl;
			return *this;
		}*/

		return this->pAddress[index];
	}

	 //β�巨
	void push_back(const T & val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}
	//βɾ��
	void Pop_back()
	{
		//���û����ʲ������һ��Ԫ�أ���Ϊβɾ���߼�ɾ��
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	//��ȡ��������
	int getCapacity()
	{
		return this->m_Capacity;
	}
	//��ȡ�����С
	int getSize()
	{
		return this->m_Size;
	}

	//��������
	~MyArray()
	{
		//cout << "������������" << endl;
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
	//�������캯��
	MyArray(const MyArray& arr)
	{
		//cout << "�������캯������" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;

		//���
		this->pAddress = new T[arr.m_Capacity];

		//��arr�е����ݶ���������
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operator=��ֹǳ����������
	MyArray& operator=(MyArray& arr)
	{
		//cout << "Operator=����" << endl;
		//���ж�ԭ�������Ƿ������ݣ���������ͷ�
		if (this->pAddress != NULL)
		{
			this->m_Capacity = 0;
			this->m_Size = 0;

			delete[] this->pAddress;
			this->pAddress = NULL;
		}
		//���
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
