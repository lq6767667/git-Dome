#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MyPrintf
{
public:
	void operator()(const int v)const
	{
		 cout << v << " ";
	}
};

void myPrintf(int v)
{
	cout << v << " ";
}

int main()
{
	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), myPrintf);//第三个参数采用函数形式，只需写函数名即可
	cout << endl;
	for_each(v.begin(), v.end(), MyPrintf());
	cout << endl;

	system("pause");
	return 0;
}