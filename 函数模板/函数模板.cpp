#include <iostream>
using namespace std;

//������������
void swapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
//����������
void swapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//ʹ�ú���ģ��
template<typename T> void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


int main()
{
	int a = 2;
	int b = 3;

	
	//swapInt(a, b);
	//cout << "a=" << a << " b= " << b << endl;

	//1. �Զ������Ƶ�
	//mySwap(a, b);
	
	//2. ��ʾָ������
	mySwap<int>(a, b);
	cout << "ʹ�ú���ģ�壺a=" << a << " b= " << b << endl;

	system("pause");
	return 0;
}
