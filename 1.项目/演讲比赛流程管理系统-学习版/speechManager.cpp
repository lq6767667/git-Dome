#include "speechManager.h"
#include <sstream>
//构造函数
SpeechManager::SpeechManager()
{
	initSpeech();
	creatSpeaker();

	loadRecord(); //加载往届记录
}

//析构函数
SpeechManager::~SpeechManager()
{

}

void SpeechManager::show_Menu()
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

void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");

	exit(0);
}

void SpeechManager::initSpeech()
{
	//容器都为空
	v1.clear();
	v2.clear();
	vVictory.clear();
	m_Speaker.clear();
	m_Index = 1;

	//初始化记录容器
	m_Rectord.clear();
}

void SpeechManager::creatSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";

	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		Speaker sp;
		sp.m_name = name;
		for (int b = 0; b < 2; b++)
		{
			sp.m_Score[b] = 0;
		}

		//12名选手编号
		v1.push_back(i + 10001);
		
		//选手编号以及对应的选手，存放到map容器中
		m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

void SpeechManager::startSpeech()
{
	//第一轮开始比赛

	//1.抽签
	speechDraw();

	//2.比赛
	speechContest();

	//3.显示晋级结果
	showScore();

	//第二轮开始比赛
	m_Index++;

	//1.抽签
	speechDraw();

	//2.比赛
	speechContest();

	//3.显示晋级结果
	showScore();

	//4.保存分数到文件中
	saveRecord();

	//重置比赛获取记录
	initSpeech();
	creatSpeaker();

	loadRecord(); //加载往届记录

	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");
}

void SpeechManager::speechDraw()
{
	cout << "第 《" << m_Index << "》轮比赛，选手正在抽签" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;

	if (m_Index == 1)
	{
		//第一轮比赛
		random_shuffle(v1.begin(), v1.end()); //打乱v1容器
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << (*it) << "  ";
		}
		cout << endl;
	}
	else
	{
		//第二轮比赛
		random_shuffle(v2.begin(), v2.end()); //打乱v2容器
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << (*it) << "  ";
		}
		cout << endl;
	}

	cout << "----------------------------------------------------" << endl;
	system("pause");
	cout << endl;
}

void SpeechManager::speechContest()
{
	cout << "-----------第" << m_Index << "轮比赛正式开始-----------" << endl;

	//准备临时容器 存放小组成绩，从大到小排序
	multimap<double, int, greater<double>> groupScore;

	int num = 0; //记录人员个数，6人一组

	vector<int> v_Src;	//比赛选手容器
	if (m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//遍历所有选手进行比赛
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//评委打分
		deque<double> d; //双端数组容器，方便去除最低分和最高分
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f; //600~1000除以10.0
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;

		sort(d.begin(), d.end(), greater<double>()); //降序排序，第三个参数是内建的函数对象，许包含头文件<functional>
		d.pop_front(); //去除最高分
		d.pop_back();//去除最低分

		double sum = accumulate(d.begin(), d.end(),0.0f); //求总分，需包含头文件<numeric>
		double avg = sum / (double)d.size();//平均分

		//打印每个人平均分
		//cout << "编号： " << *it << " 姓名：" << m_Speaker[*it].m_name << " 平均分为：" << avg << endl;

		//将平均分放入map容器中
		m_Speaker[*it].m_Score[m_Index - 1] = avg;

		//将打分数据放入到临时小组容器中
		groupScore.insert(make_pair(avg, *it)); //key是得分，value是具体人员的编号

		//每6人取出前三名
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号：" << it->second << " 姓名：" << m_Speaker[it->second].m_name << " 成绩：" << m_Speaker[it->second].m_Score[m_Index-1] << endl;
			}

			//取走前三名
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (m_Index == 1)
				{
					v2.push_back(it->second);//第一轮晋级
				}
				else
				{
					vVictory.push_back(it->second);//第二轮晋级
				}
			}

			groupScore.clear();//小组比赛容器清空

			cout << endl;
		}
	}

	cout << "----------------------第" << m_Index << "轮比赛结束------------" << endl;
	system("pause");
}

void SpeechManager::showScore()
{
	cout << "------------------第" << m_Index << "轮晋级选手如下：------------------" << endl;

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
		cout << "选手编号：" << *it << " 姓名：" << m_Speaker[*it].m_name << " 得分：" << m_Speaker[*it].m_Score[m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");

	show_Menu();
}

void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); //用追加的方式写文件

	//将每个选手数据写到文件中
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	ofs.close();
	cout << "记录保存成功！" << endl;

	//有记录了，文件不为空
	fileIsEmpty = false;
}

void SpeechManager::showRecord()
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

void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in); //读文件

	if (!ifs.is_open())
	{
		fileIsEmpty = true;
		//cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	
	//文件为空的情况
	char ch;
	ifs >> ch; //读一个字符
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件不为空
	fileIsEmpty = false;

	ifs.putback(ch); //将上面读取的单个字符 放回来

	string data;
	int index = 0; //第几届

	//while (ifs >> data)  //读取的时候会以空格，换行，制表符作为分隔符，若文件中存在这些符号会导致读取出现问题
	while (std::getline(ifs, data)) //以行的形式来读
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
		m_Rectord.insert(make_pair(index, v));
		index++;
	}
	
	ifs.close();

	/*for (map<int, vector<string>>::iterator it = m_Rectord.begin(); it != m_Rectord.end(); it++)
	{
		cout << "第<" << it->first << ">届 冠军编号：" << it->second[0] << " 分数：" << it->second[1] << endl;
	}*/
}

void SpeechManager::clearRecord()
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

		initSpeech();
		creatSpeaker();//创建选手
		loadRecord();

		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
}
