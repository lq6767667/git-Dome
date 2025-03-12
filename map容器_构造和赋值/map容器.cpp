#include <iostream>
#include <map>
using namespace std;

void myPrintf(const map<int, int>& p)
{
	for (map<int, int>::const_iterator it = p.begin(); it != p.end(); it++)
	{
		cout << "keyֵ= " << it->first << "value= " << it->second << endl;

	}
	cout << endl;
}


void test01()
{
	map<int, int> mp;
	mp.insert(pair<int, int>(1, 20));
	mp.insert(pair<int, int>(3, 50));
	mp.insert(pair<int, int>(5, 30));
	mp.insert(pair<int, int>(4, 40));

	myPrintf(mp);
}
int main()
{
	test01();
	system("pause");
	return 0;
}