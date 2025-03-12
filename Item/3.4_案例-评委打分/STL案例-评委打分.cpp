#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <ctime>


//类：选手信息
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
		string name = "选手";
		name += P_name[i];

		int score = 0;

		Person p(name,score);
		v.push_back(p);//将创建出的成员存入容器中
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
			deq.push_back(score);//将打的分存入deque容器中
		}
		sort(deq.begin(), deq.end());//将10个评委打的分数进行排序（从小到大）
		//去除最高最低
		deq.pop_back();
		deq.pop_front();

		//取平均分
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
	//存放选手的容器,创建出5个选手
	vector<Person> v;
	creatPerson(v);

	/*for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << " 成绩：" << (*it).m_Score << endl;
	}*/

	//打分
	setScore(v);

	//打印各选手最后得分
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << " 成绩：" << (*it).m_Score << endl;
	}

	system("pause");
	return 0;
}
