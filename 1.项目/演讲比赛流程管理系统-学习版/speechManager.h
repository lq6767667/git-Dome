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

/*����������
1.�ṩ�˵��������û�����
2.���ݽ��������̽��п���
3.���ļ���д����
*/
class SpeechManager
{
public:
	//���캯��
	SpeechManager();
	//��������
	~SpeechManager();

	//չʾ�˵�
	void show_Menu();

	//�˳�ϵͳ
	void exitSystem();

	//��ʼ����Ա����
	void initSpeech();

	//��ʼ������12��ѡ��
	void creatSpeaker();

	//��ʼ����
	void startSpeech();

	//��ǩ
	void speechDraw();

	//����
	void speechContest();

	//��ʾ�ɼ�
	void showScore();

	//���浽�ļ���
	void saveRecord();

	//��ʾ����ļ�¼
	void showRecord();

	//��ȡ��¼
	void loadRecord();

	//��ռ�¼
	void clearRecord();

public:
	//��Ա����
	//�����һ�ֱ���ѡ�ֱ������
	vector<int> v1;

	//�����һ�ֽ���ѡ�ֱ������
	vector<int> v2;

	vector<int>vVictory;

	//��ű���Լ���Ӧ����ѡ������
	map<int, Speaker> m_Speaker;

	//��ű�������
	int m_Index;

	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;

	//��������¼������
	map<int, vector<string>> m_Rectord;


};