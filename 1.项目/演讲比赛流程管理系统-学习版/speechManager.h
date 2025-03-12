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

/*创建管理类
1.提供菜单界面与用户交互
2.对演讲比赛流程进行控制
3.与文件读写交互
*/
class SpeechManager
{
public:
	//构造函数
	SpeechManager();
	//析构函数
	~SpeechManager();

	//展示菜单
	void show_Menu();

	//退出系统
	void exitSystem();

	//初始化成员属性
	void initSpeech();

	//初始化创建12名选手
	void creatSpeaker();

	//开始比赛
	void startSpeech();

	//抽签
	void speechDraw();

	//比赛
	void speechContest();

	//显示成绩
	void showScore();

	//保存到文件中
	void saveRecord();

	//显示往届的记录
	void showRecord();

	//读取记录
	void loadRecord();

	//清空记录
	void clearRecord();

public:
	//成员属性
	//保存第一轮比赛选手编号容器
	vector<int> v1;

	//保存第一轮晋级选手编号容器
	vector<int> v2;

	vector<int>vVictory;

	//存放编号以及对应具体选手容器
	map<int, Speaker> m_Speaker;

	//存放比赛轮数
	int m_Index;

	//判断文件是否为空
	bool fileIsEmpty;

	//存放往届记录的容器
	map<int, vector<string>> m_Rectord;


};