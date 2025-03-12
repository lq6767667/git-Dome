#include <iostream>
using namespace std;

//交换模板
template<class T> void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//选择排序模板（从大到小）
template<class T> void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;//max保存最大数的下标
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;//更新最大值下标
			}
		}
		if (max != i)//最大值的下标和一开始的下标不一样，则交换最大值下标的元素
		{
			mySwap(arr[i], arr[max]);
		}
	}
}

//打印模板
template<class T>void myPrintf(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01()//char类型排序
{
	char arr[] = "abcdefgh";
	int len = sizeof(arr) / sizeof(char);
	mySort(arr, len);
	myPrintf(arr, len);
}

void test02()//int类型排序
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
