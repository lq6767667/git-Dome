#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//���ò����㷨adjacent_find
void test01()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(1);
	v.push_back(5);
	v.push_back(1);

	auto it = adjacent_find(v.begin(), v.end());
	if (it == v.end())
	{
		cout << "δ�ҵ������ظ�Ԫ��" << endl;
	}
	else
	{

	}

}

int main()
{
	test01();
	system("pause");
	return 0;
}