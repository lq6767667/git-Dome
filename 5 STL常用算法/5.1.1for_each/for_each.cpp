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

	for_each(v.begin(), v.end(), myPrintf);//�������������ú�����ʽ��ֻ��д����������
	cout << endl;
	for_each(v.begin(), v.end(), MyPrintf());
	cout << endl;

	system("pause");
	return 0;
}