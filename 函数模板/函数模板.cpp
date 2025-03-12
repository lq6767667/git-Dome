#include <iostream>
using namespace std;

//交换整数函数
void swapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
//交换浮点数
void swapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//使用函数模板
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

	//1. 自动类型推导
	//mySwap(a, b);
	
	//2. 显示指定类型
	mySwap<int>(a, b);
	cout << "使用函数模板：a=" << a << " b= " << b << endl;

	system("pause");
	return 0;
}
