#include <iostream>
using namespace std;

//����ģ��
template<class T> void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//ѡ������ģ�壨�Ӵ�С��
template<class T> void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;//max������������±�
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;//�������ֵ�±�
			}
		}
		if (max != i)//���ֵ���±��һ��ʼ���±겻һ�����򽻻����ֵ�±��Ԫ��
		{
			mySwap(arr[i], arr[max]);
		}
	}
}

//��ӡģ��
template<class T>void myPrintf(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01()//char��������
{
	char arr[] = "abcdefgh";
	int len = sizeof(arr) / sizeof(char);
	mySort(arr, len);
	myPrintf(arr, len);
}

void test02()//int��������
{
	int arr[] = { 1,2,4,2,3,6,8,4,7,12,9,10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	mySort(arr, len);
	myPrintf(arr, len);
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}
