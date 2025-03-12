#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int, less<int>> s1;//ÉıĞòÅÅÁĞ
	set<int, greater<int>>s2;//½µĞòÅÅÁĞ

	s1.insert(1);
	s1.insert(3);
	s1.insert(5);

	s2.insert(1);
	s2.insert(3);
	s2.insert(5);


	for (auto it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	for (auto it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}