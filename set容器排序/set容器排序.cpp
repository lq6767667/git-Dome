#include <iostream>
#include <set>
using namespace std;

class Mysort
{
public:
	bool operator()(int v1,int v2)const		//��vs2019����Ҫ��const�������Σ�����ᱨ��ԭ�����ڵ��÷º�����ʱ�򣬵��ö���������п��ܻᱻ�޸ģ������Ҫʹ��const�޶����ú�����set���󲻱��޸ġ�
	{
		return v1 > v2;
	}
};

void test01()
{
	set<int> s1;

	s1.insert(23);
	s1.insert(31);
	s1.insert(10);
	s1.insert(35);
	s1.insert(50);

	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	set<int, Mysort> s2;

	s2.insert(23);
	s2.insert(31);
	s2.insert(10);
	s2.insert(30);
	s2.insert(50);

	for (set<int>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}