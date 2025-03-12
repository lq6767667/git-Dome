#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm> //�㷨ͷ�ļ�
#include <deque>
#include <functional>
#include <numeric>
#include <fstream>

#include "speaker.h"

using namespace std;

class SpeechCompetition
{
public:
	SpeechCompetition();

	~SpeechCompetition();

	void initData();

	void creatSpeaker();

	void showMenu();

	void startCompetition();

	void Draw();

	void startSpeech();

	void showScore();

	void exitProgrammer();

	void saveRecord();

	void showRecord();

	void loadRecord();

	void clearRecorg();

public:
	vector<int> v1;

	vector<int> v2;

	vector<int> vVictory; //�ڶ��ֱ���������,ʤ����ѡ��

	map<int, Speaker> m_spaker;

	map<int, vector<string>> m_Rectord;//���ļ��ж�ȡ��������

	int m_Index; //��¼�ڼ��ֱ���

	bool fileIsEmpty;
};