#include <iostream>
#include "Person.h"

#include <vector>
#include <map>
#include <time.h>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2
/*
����10��Ա����ABCDEFGHIJ����Ա������Ϣ�У�����������
�����ŷ�Ϊ���߻����������з�
�������10��Ա�����䲿�ź͹���
��ͨ��multimap������Ϣ�Ĳ��� key�����ű�ţ�value��Ա����
�����ʵ�ֲַ�����ʾԱ����Ϣ

1������10��Ա�����ŵ�vector����
2������vector������ȡ��ÿ��Ա���������������
3������󣬽�Ա�����ű����Ϊkeyֵ������Ա����Ϊvalue���ŵ�multimap����
4���ֲ�����ʾԱ����Ϣ
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
		p.m_name = "Ա��С";
		p.m_name += w_name[i];

		p.m_salary = rand() % 10000 + 10000; //10000~19999

		worker.push_back(p);
	}
}

void PersonGroup(vector<Person>& v, multimap<int, Person>& m)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//����������ű��
		int deptId = rand() % 3; //0~2

		//��Ա�����������
		m.insert(make_pair(deptId, *it));
	}
}

void showPerson(multimap<int, Person>& mp)
{
	//����0��ABC 1��DE ��2��FG...
	cout << "�߻�����" << endl;
	multimap<int, Person>::iterator pos = mp.find(CEHUA); 
	int count = mp.count(CEHUA);//ͳ�ƾ���������ͳ�Ƽ�ֵΪ0��������
	int index = 0;
	for (; pos != mp.end() && count > index; pos++, index++)
	{
		cout << "������" << pos->second.m_name << " н�ʣ�" << pos->second.m_salary << endl;
	}
	
	cout << "��������" << endl;
	pos = mp.find(MEISHU);
	count = mp.count(MEISHU);//ͳ�ƾ�������
	index = 0;
	for (; pos != mp.end() && count > index; pos++, index++)
	{
		cout << "������" << pos->second.m_name << " н�ʣ�" << pos->second.m_salary << endl;
	}

	cout << "�з�����" << endl;
	pos = mp.find(YANFA);
	count = mp.count(YANFA);//ͳ�ƾ�������
	index = 0;
	for (; pos != mp.end() && count > index; pos++, index++)
	{
		cout << "������" << pos->second.m_name << " н�ʣ�" << pos->second.m_salary << endl;
	}
}

void test01()
{
	//����Ա��
	vector<Person> worker;
	creatWorker(worker);

	//ΪԱ������
	multimap<int, Person> mp;
	PersonGroup(worker, mp);

	//�ֲ�����ʾԱ����Ϣ
	showPerson(mp);

}

int main()
{
	srand((unsigned int)time(NULL));
	test01();
	system("pause");
	return 0;
}