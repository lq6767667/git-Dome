#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <ctime>


//�ࣺѡ����Ϣ
class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name;
	int m_Score;
};

void creatPerson(vector<Person>& v)
{
	string P_name = "ABCDE";

	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
		name += P_name[i];

		int score = 0;

		Person p(name,score);
		v.push_back(p);//���������ĳ�Ա����������
	}
}

void setScore(vector<Person>& v)
{
	deque<int> deq;
	srand((unsigned int)time(NULL));
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;//60~100
			deq.push_back(score);//����ķִ���deque������
		}
		sort(deq.begin(), deq.end());//��10����ί��ķ����������򣨴�С����
		//ȥ��������
		deq.pop_back();
		deq.pop_front();

		//ȡƽ����
		int sum = 0;
		for (deque<int>::iterator dt = deq.begin(); dt != deq.end(); dt++)
		{
			sum += *dt;
		}
		sum = sum / deq.size();
		it->m_Score = sum;

	}
}

int main()
{
	//���ѡ�ֵ�����,������5��ѡ��
	vector<Person> v;
	creatPerson(v);

	/*for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������" << (*it).m_Name << " �ɼ���" << (*it).m_Score << endl;
	}*/

	//���
	setScore(v);

	//��ӡ��ѡ�����÷�
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������" << (*it).m_Name << " �ɼ���" << (*it).m_Score << endl;
	}

	system("pause");
	return 0;
}
