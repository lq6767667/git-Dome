#include "SpeechCompetition.h"
#include <algorithm>

SpeechCompetition::SpeechCompetition()
{
	initData();
	creatSpeaker();//创建选手

	loadRecord();

}

SpeechCompetition::~SpeechCompetition()
{

}

void SpeechCompetition::initData()
{
	v1.clear();
	v2.clear();
	vVictory.clear();
	m_spaker.clear();

	m_Index = 1; //第一轮
	m_Rectord.clear();
}

void SpeechCompetition::creatSpeaker()
{
	string ne = "ABCDEFGHIJKL";

	for (int i = 0; i<ne.size(); i++)
	{
		string name = "选手";
		name += ne[i];

		Speaker sk;
		sk.m_name = name;
		for (int j = 0; j < 2; j++)
		{
			sk.m_Score[j] = 0;
		}

		v1.push_back(i + 10001);
		m_spaker.insert(make_pair(i + 10001, sk));
	}


}

void SpeechCompetition::showMenu()
{
	cout << "***************************************" << endl;
	cout << "**                                   **" << endl;
	cout << "**         欢迎参加演讲比赛          **" << endl;
	cout << "**          1.开始演讲比赛           **" << endl;
	cout << "**          2.查看往届记录           **" << endl;
	cout << "**          3.清空比赛记录           **" << endl;
	cout << "**          0.退出比赛程序           **" << endl;
	cout << "**                                   **" << endl;
	cout << "***************************************" << endl;
	cout << endl;
}

void SpeechCompetition::startCompetition()
{
	//抽签
	Draw();

	//比赛
	startSpeech();

	//结果展示
	showScore();

	//第二轮
	m_Index++;
	Draw();
	startSpeech();
	showScore();

	saveRecord();

	//重置比赛记录
	initData();
	creatSpeaker();
	loadRecord();

	cout << "本届比赛结束！" << endl;
	system("pause");
	system("cls");

}

void SpeechCompetition::Draw()
{
	cout << "=================第 " << m_Index << " 轮比赛开始抽签,抽签结果如下： ================" << endl;

	if (m_Index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++ )
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}

	cout << "===================================================================================" << endl;
	system("pause");
}

void SpeechCompetition::startSpeech()
{
	cout << "=================第 " << m_Index << " 轮比赛开始================" << endl;

	multimap<double, int, greater<double>> groupScore;

	int numSpaker = 0;

	vector<int> v_Src; //临时容器

	if (m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		numSpaker++;
		//打分
		deque<double> d;

		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.0f;
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();
		d.pop_back();

		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();

		m_spaker[*it].m_Score[m_Index - 1] = avg; // 

		groupScore.insert(make_pair(avg, *it));

		if (numSpaker % 6 == 0)
		{
			cout << "第 " << numSpaker / 6 << " 小组的比赛名次为：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号： " << it->second << " 姓名：" << m_spaker[it->second].m_name << " 成绩：" << m_spaker[it->second].m_Score[m_Index - 1] << endl;
			}
			//取出前三名进入第二轮
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (m_Index == 1)
				{
					v2.push_back(it->second);
				}
				else
				{
					vVictory.push_back(it->second);
				}
			}
			groupScore.clear();
			cout << endl;
		}
	}
	cout << "----------------------第" << m_Index << "轮比赛结束------------" << endl;
	system("pause");
}

void SpeechCompetition::showScore()
{
	cout << "===================第 " << m_Index << " 轮晋级的选手为：=====================" << endl;

	vector<int> v;
	if (m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手编号：" << *it << " 姓名：" << m_spaker[*it].m_name << " 得分：" << m_spaker[*it].m_Score[m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");

	showMenu();
}

void SpeechCompetition::exitProgrammer()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

void SpeechCompetition::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);

	//将每个选手数据写到文件中
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << m_spaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	ofs.close();
	cout << "记录保存成功！" << endl;

	//有记录了，文件不为空
	fileIsEmpty = false;
}

void SpeechCompetition::showRecord()
{
	if (fileIsEmpty)
	{
		cout << "文件为空或者不存在！" << endl;
	}
	else
	{
		int a = m_Rectord.size();
		for (int i = 0; i < m_Rectord.size(); i++)
		{
			cout << "第" << i + 1 << "届" << endl;
			cout << " 冠军编号：" << m_Rectord[i][0] << " 得分：" << m_Rectord[i][1] << endl;
			cout << " 亚军编号：" << m_Rectord[i][2] << " 得分：" << m_Rectord[i][3] << endl;
			cout << " 季军编号：" << m_Rectord[i][4] << " 得分：" << m_Rectord[i][5] << endl;
		}
		/*for (map<int, vector<string>>::iterator it = m_Rectord.begin(); it != m_Rectord.end(); it++)
		{
			cout << "第<" << it->first << ">届 冠军编号：" << it->second[0] << " 分数：" << it->second[1] << endl;
			cout << "第<" << it->first << ">届 亚军编号：" << it->second[2] << " 分数：" << it->second[3] << endl;
			cout << "第<" << it->first << ">届 季军编号：" << it->second[4] << " 分数：" << it->second[5] << endl;
		}*/
	}

	system("pause");
	system("cls");
}

void SpeechCompetition::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);

	if (!ifs.is_open())
	{
		fileIsEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		fileIsEmpty = true;
		ifs.close();
		return;
	}

	fileIsEmpty = false;
	ifs.putback(ch);

	string data;
	int Index = 0;
	while (std::getline(ifs, data))
	{
		vector<string> v; //存放6个string字符村

		int pos = -1; //查到“，”位置的标记
		int start = 0; //从0号位置开始查找

		data.erase(std::remove(data.begin(), data.end(), ' '), data.end()); //移除数据中的空格

		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				//没有找到的情况
				break;
			}

			string temp = data.substr(start, pos - start); //截取字符串

			v.push_back(temp);

			start = pos + 1;
		}
		m_Rectord.insert(make_pair(Index, v));
		Index++;
	}
	ifs.close();
}

void SpeechCompetition::clearRecorg()
{
	cout << "确认清空？" << endl;
	cout << "1.确认" << endl;
	cout << "2.取消" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		initData();
		creatSpeaker();//创建选手
		loadRecord();

		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
}

