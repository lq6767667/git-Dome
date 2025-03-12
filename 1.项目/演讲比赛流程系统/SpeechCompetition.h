#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm> //算法头文件
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

	vector<int> vVictory; //第二轮比赛结束后,胜出的选手

	map<int, Speaker> m_spaker;

	map<int, vector<string>> m_Rectord;//从文件中读取往届数据

	int m_Index; //记录第几轮比赛

	bool fileIsEmpty;
};