#include <iostream>
#include "Person.h"

#include <vector>
#include <map>
#include <time.h>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2
/*
·有10名员工（ABCDEFGHIJ），员工的信息有：姓名，工资
·部门分为：策划、美术、研发
·随机给10名员工分配部门和工资
·通过multimap进行信息的插入 key（部门编号）value（员工）
·最后实现分部门显示员工信息

1）创建10名员工，放到vector容器
2）遍历vector容器，取出每个员工，进行随机分组
3）分组后，将员工部门编号作为key值，具体员工作为value，放到multimap容器
4）分部门显示员工信息
*/
using namespace std;

class Person
{
public:
	Person()
	{

	}
	~Person()
	{

	}

	string m_name;
	int m_salary;
};

void creatWorker(vector<Person>& worker)
{
	string w_name = "ABCDEFGHIJ";

	for (int i = 0; i < 10; i++)
	{
		Person p;
		p.m_name = "员工小";
		p.m_name += w_name[i];

		p.m_salary = rand() % 10000 + 10000; //10000~19999

		worker.push_back(p);
	}
}

void PersonGroup(vector<Person>& v, multimap<int, Person>& m)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//产生随机部门编号
		int deptId = rand() % 3; //0~2

		//将员工插入分组中
		m.insert(make_pair(deptId, *it));
	}
}

void showPerson(multimap<int, Person>& mp)
{
	//可能0：ABC 1：DE ：2：FG...
	cout << "策划部：" << endl;
	multimap<int, Person>::iterator pos = mp.find(CEHUA); 
	int count = mp.count(CEHUA);//统计具体人数（统计键值为0的数量）
	int index = 0;
	for (; pos != mp.end() && count > index; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_name << " 薪资：" << pos->second.m_salary << endl;
	}
	
	cout << "美术部：" << endl;
	pos = mp.find(MEISHU);
	count = mp.count(MEISHU);//统计具体人数
	index = 0;
	for (; pos != mp.end() && count > index; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_name << " 薪资：" << pos->second.m_salary << endl;
	}

	cout << "研发部：" << endl;
	pos = mp.find(YANFA);
	count = mp.count(YANFA);//统计具体人数
	index = 0;
	for (; pos != mp.end() && count > index; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_name << " 薪资：" << pos->second.m_salary << endl;
	}
}

void test01()
{
	//创建员工
	vector<Person> worker;
	creatWorker(worker);

	//为员工分组
	multimap<int, Person> mp;
	PersonGroup(worker, mp);

	//分部门显示员工信息
	showPerson(mp);

}

int main()
{
	srand((unsigned int)time(NULL));
	test01();
	system("pause");
	return 0;
}