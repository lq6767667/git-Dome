#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace  std;;

int main()
{

#if 0
	//迭代器失效测试
	int arr[] = { 1,2,3,4,4,4,4,5,6,7 };
	vector<int> v(arr, arr+10);

	for (vector<int>::iterator it=v.begin(); it !=v.end();)
	{
		if (*it == 4)
		{
			vector<int>::iterator it1;
			it1=v.erase(it);//这么写会导致it迭代器失效，在vs中会崩溃，需要修改成it = =v.erase(it);
			cout << *it1 << endl;
		}
		else
			it++;
	}

// 	for (auto it=v.begin(); it != v.end(); it++)
// 	{
// 		cout << *it << " ";
// 	}
// 	cout << endl;

#endif

#if 0
	list<int> lstA;
	lstA.push_back(1);
	lstA.push_back(2);
	lstA.push_back(3);
	lstA.push_back(4);

	list<int> lstB(lstA.begin(), lstA.end());

	for (list<int>::iterator it=lstB.begin(); it != lstB.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
#endif

	set<int>set1;
	set1.insert(1);
	set1.insert(4);
	set1.insert(3);
	set1.insert(7);

	set1.erase(++set1.begin());

	for (set<int>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	

	system("pause");
	return 0;
}