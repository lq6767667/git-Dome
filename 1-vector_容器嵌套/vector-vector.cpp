#include <iostream>
using namespace std;
#include <vector>


void test()
{
	vector< vector<int> > V;

	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	vector<int> v5;

	//向容器中插入数据
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
		v5.push_back(i + 5);
	}

	//将小容器放入大容器中
	V.push_back(v1);
	V.push_back(v2);
	V.push_back(v3);
	V.push_back(v4);
	V.push_back(v5);

	for (vector<vector<int>>::iterator it = V.begin(); it != V.end(); it++)
	{
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << (*vit) << " ";
		}
		cout << endl;
	}

}
int main()
{
	test();
	system("pause");
	return 0;
}