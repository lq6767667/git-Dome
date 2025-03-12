#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class MyPrint
{
public:
	void operator()(const int &val)
	{
		cout << val << " ";
	}
};

class Greater20
{
public:
	bool operator()(int val)
	{
		return val >= 20;
	}
};
void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(60);
	v.push_back(30);
	v.push_back(10);

	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	//将大于20的全部替换成2000
	replace_if(v.begin(), v.end(), Greater20(), 3000);
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}