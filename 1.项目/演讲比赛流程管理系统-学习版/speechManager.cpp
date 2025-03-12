#include "speechManager.h"
#include <sstream>
//���캯��
SpeechManager::SpeechManager()
{
	initSpeech();
	creatSpeaker();

	loadRecord(); //���������¼
}

//��������
SpeechManager::~SpeechManager()
{

}

void SpeechManager::show_Menu()
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

void SpeechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");

	exit(0);
}

void SpeechManager::initSpeech()
{
	//������Ϊ��
	v1.clear();
	v2.clear();
	vVictory.clear();
	m_Speaker.clear();
	m_Index = 1;

	//��ʼ����¼����
	m_Rectord.clear();
}

void SpeechManager::creatSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";

	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		Speaker sp;
		sp.m_name = name;
		for (int b = 0; b < 2; b++)
		{
			sp.m_Score[b] = 0;
		}

		//12��ѡ�ֱ��
		v1.push_back(i + 10001);
		
		//ѡ�ֱ���Լ���Ӧ��ѡ�֣���ŵ�map������
		m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

void SpeechManager::startSpeech()
{
	//��һ�ֿ�ʼ����

	//1.��ǩ
	speechDraw();

	//2.����
	speechContest();

	//3.��ʾ�������
	showScore();

	//�ڶ��ֿ�ʼ����
	m_Index++;

	//1.��ǩ
	speechDraw();

	//2.����
	speechContest();

	//3.��ʾ�������
	showScore();

	//4.����������ļ���
	saveRecord();

	//���ñ�����ȡ��¼
	initSpeech();
	creatSpeaker();

	loadRecord(); //���������¼

	cout << "���������ϣ�" << endl;
	system("pause");
	system("cls");
}

void SpeechManager::speechDraw()
{
	cout << "�� ��" << m_Index << "���ֱ�����ѡ�����ڳ�ǩ" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;

	if (m_Index == 1)
	{
		//��һ�ֱ���
		random_shuffle(v1.begin(), v1.end()); //����v1����
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << (*it) << "  ";
		}
		cout << endl;
	}
	else
	{
		//�ڶ��ֱ���
		random_shuffle(v2.begin(), v2.end()); //����v2����
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
	cout << "-----------��" << m_Index << "�ֱ�����ʽ��ʼ-----------" << endl;

	//׼����ʱ���� ���С��ɼ����Ӵ�С����
	multimap<double, int, greater<double>> groupScore;

	int num = 0; //��¼��Ա������6��һ��

	vector<int> v_Src;	//����ѡ������
	if (m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//��������ѡ�ֽ��б���
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//��ί���
		deque<double> d; //˫����������������ȥ����ͷֺ���߷�
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f; //600~1000����10.0
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;

		sort(d.begin(), d.end(), greater<double>()); //�������򣬵������������ڽ��ĺ������������ͷ�ļ�<functional>
		d.pop_front(); //ȥ����߷�
		d.pop_back();//ȥ����ͷ�

		double sum = accumulate(d.begin(), d.end(),0.0f); //���ܷ֣������ͷ�ļ�<numeric>
		double avg = sum / (double)d.size();//ƽ����

		//��ӡÿ����ƽ����
		//cout << "��ţ� " << *it << " ������" << m_Speaker[*it].m_name << " ƽ����Ϊ��" << avg << endl;

		//��ƽ���ַ���map������
		m_Speaker[*it].m_Score[m_Index - 1] = avg;

		//��������ݷ��뵽��ʱС��������
		groupScore.insert(make_pair(avg, *it)); //key�ǵ÷֣�value�Ǿ�����Ա�ı��

		//ÿ6��ȡ��ǰ����
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "��ţ�" << it->second << " ������" << m_Speaker[it->second].m_name << " �ɼ���" << m_Speaker[it->second].m_Score[m_Index-1] << endl;
			}

			//ȡ��ǰ����
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (m_Index == 1)
				{
					v2.push_back(it->second);//��һ�ֽ���
				}
				else
				{
					vVictory.push_back(it->second);//�ڶ��ֽ���
				}
			}

			groupScore.clear();//С������������

			cout << endl;
		}
	}

	cout << "----------------------��" << m_Index << "�ֱ�������------------" << endl;
	system("pause");
}

void SpeechManager::showScore()
{
	cout << "------------------��" << m_Index << "�ֽ���ѡ�����£�------------------" << endl;

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
		cout << "ѡ�ֱ�ţ�" << *it << " ������" << m_Speaker[*it].m_name << " �÷֣�" << m_Speaker[*it].m_Score[m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");

	show_Menu();
}

void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); //��׷�ӵķ�ʽд�ļ�

	//��ÿ��ѡ������д���ļ���
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	ofs.close();
	cout << "��¼����ɹ���" << endl;

	//�м�¼�ˣ��ļ���Ϊ��
	fileIsEmpty = false;
}

void SpeechManager::showRecord()
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

void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in); //���ļ�

	if (!ifs.is_open())
	{
		fileIsEmpty = true;
		//cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	
	//�ļ�Ϊ�յ����
	char ch;
	ifs >> ch; //��һ���ַ�
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	fileIsEmpty = false;

	ifs.putback(ch); //�������ȡ�ĵ����ַ� �Ż���

	string data;
	int index = 0; //�ڼ���

	//while (ifs >> data)  //��ȡ��ʱ����Կո񣬻��У��Ʊ����Ϊ�ָ��������ļ��д�����Щ���Żᵼ�¶�ȡ��������
	while (std::getline(ifs, data)) //���е���ʽ����
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
		m_Rectord.insert(make_pair(index, v));
		index++;
	}
	
	ifs.close();

	/*for (map<int, vector<string>>::iterator it = m_Rectord.begin(); it != m_Rectord.end(); it++)
	{
		cout << "��<" << it->first << ">�� �ھ���ţ�" << it->second[0] << " ������" << it->second[1] << endl;
	}*/
}

void SpeechManager::clearRecord()
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

		initSpeech();
		creatSpeaker();//����ѡ��
		loadRecord();

		cout << "��ճɹ���" << endl;
	}

	system("pause");
	system("cls");
}
