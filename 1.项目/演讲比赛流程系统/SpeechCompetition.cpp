#include "SpeechCompetition.h"
#include <algorithm>

SpeechCompetition::SpeechCompetition()
{
	initData();
	creatSpeaker();//����ѡ��

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

	m_Index = 1; //��һ��
	m_Rectord.clear();
}

void SpeechCompetition::creatSpeaker()
{
	string ne = "ABCDEFGHIJKL";

	for (int i = 0; i<ne.size(); i++)
	{
		string name = "ѡ��";
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
	cout << "**         ��ӭ�μ��ݽ�����          **" << endl;
	cout << "**          1.��ʼ�ݽ�����           **" << endl;
	cout << "**          2.�鿴�����¼           **" << endl;
	cout << "**          3.��ձ�����¼           **" << endl;
	cout << "**          0.�˳���������           **" << endl;
	cout << "**                                   **" << endl;
	cout << "***************************************" << endl;
	cout << endl;
}

void SpeechCompetition::startCompetition()
{
	//��ǩ
	Draw();

	//����
	startSpeech();

	//���չʾ
	showScore();

	//�ڶ���
	m_Index++;
	Draw();
	startSpeech();
	showScore();

	saveRecord();

	//���ñ�����¼
	initData();
	creatSpeaker();
	loadRecord();

	cout << "�������������" << endl;
	system("pause");
	system("cls");

}

void SpeechCompetition::Draw()
{
	cout << "=================�� " << m_Index << " �ֱ�����ʼ��ǩ,��ǩ������£� ================" << endl;

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
	cout << "=================�� " << m_Index << " �ֱ�����ʼ================" << endl;

	multimap<double, int, greater<double>> groupScore;

	int numSpaker = 0;

	vector<int> v_Src; //��ʱ����

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
		//���
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
			cout << "�� " << numSpaker / 6 << " С��ı�������Ϊ��" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "��ţ� " << it->second << " ������" << m_spaker[it->second].m_name << " �ɼ���" << m_spaker[it->second].m_Score[m_Index - 1] << endl;
			}
			//ȡ��ǰ��������ڶ���
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
	cout << "----------------------��" << m_Index << "�ֱ�������------------" << endl;
	system("pause");
}

void SpeechCompetition::showScore()
{
	cout << "===================�� " << m_Index << " �ֽ�����ѡ��Ϊ��=====================" << endl;

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
		cout << "ѡ�ֱ�ţ�" << *it << " ������" << m_spaker[*it].m_name << " �÷֣�" << m_spaker[*it].m_Score[m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");

	showMenu();
}

void SpeechCompetition::exitProgrammer()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

void SpeechCompetition::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);

	//��ÿ��ѡ������д���ļ���
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << m_spaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	ofs.close();
	cout << "��¼����ɹ���" << endl;

	//�м�¼�ˣ��ļ���Ϊ��
	fileIsEmpty = false;
}

void SpeechCompetition::showRecord()
{
	if (fileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��߲����ڣ�" << endl;
	}
	else
	{
		int a = m_Rectord.size();
		for (int i = 0; i < m_Rectord.size(); i++)
		{
			cout << "��" << i + 1 << "��" << endl;
			cout << " �ھ���ţ�" << m_Rectord[i][0] << " �÷֣�" << m_Rectord[i][1] << endl;
			cout << " �Ǿ���ţ�" << m_Rectord[i][2] << " �÷֣�" << m_Rectord[i][3] << endl;
			cout << " ������ţ�" << m_Rectord[i][4] << " �÷֣�" << m_Rectord[i][5] << endl;
		}
		/*for (map<int, vector<string>>::iterator it = m_Rectord.begin(); it != m_Rectord.end(); it++)
		{
			cout << "��<" << it->first << ">�� �ھ���ţ�" << it->second[0] << " ������" << it->second[1] << endl;
			cout << "��<" << it->first << ">�� �Ǿ���ţ�" << it->second[2] << " ������" << it->second[3] << endl;
			cout << "��<" << it->first << ">�� ������ţ�" << it->second[4] << " ������" << it->second[5] << endl;
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
		vector<string> v; //���6��string�ַ���

		int pos = -1; //�鵽������λ�õı��
		int start = 0; //��0��λ�ÿ�ʼ����

		data.erase(std::remove(data.begin(), data.end(), ' '), data.end()); //�Ƴ������еĿո�

		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				//û���ҵ������
				break;
			}

			string temp = data.substr(start, pos - start); //��ȡ�ַ���

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
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.ȡ��" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽ ios::trunc �������ɾ���ļ������´���
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		initData();
		creatSpeaker();//����ѡ��
		loadRecord();

		cout << "��ճɹ���" << endl;
	}

	system("pause");
	system("cls");
}

