#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Transfrom
{
public:
	int operator()(int value)const
	{
		return value;
	}
};
class myPrintf
{
public:
	void operator()(const int value)const
	{
		cout << value << " ";
	}
};
int main()
{
	vector<int> v1;

	for (int i = 1; i < 10; i++)
	{
		v1.push_back(i);
	}

	vector<int> v2;//目标容器
	v2.resize(v1.size());//目标容器需要提前开辟空间

	transform(v1.begin(), v1.end(), v2.begin(), Transfrom());

	for_each(v2.begin(), v2.end(), myPrintf());
	cout << endl;

	for_each(v1.begin(), v1.end(), myPrintf());
	cout << endl;

	system("pause");
	return 0;
}