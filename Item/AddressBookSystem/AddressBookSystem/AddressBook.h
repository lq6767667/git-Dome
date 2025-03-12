#pragma once
#ifndef __ADDRESSBOOKSYSTEM_H
#define __ADDRESSBOOKSYSTEM_H

#include <string>
using namespace std;
#define MAX 1000

//��ϵ����Ϣ
struct person_info
{
	string name;
	string m_Sex;
	int m_Age;
	string m_phone;//�绰
	string m_Addr;//סַ

};

//ͨѶ¼
struct AddressBook
{
	struct person_info personArray[MAX];//ͨѶ¼�б������ϵ������
	int m_Size;//��Ա����

};

void Address_Menu(void);
void add_Person(struct AddressBook*);
void show_Person(const AddressBook abs);
void find_Person(AddressBook abs);
void deletePerson(AddressBook* abs);
void revise_Person(AddressBook* abs);
void clear_Person(AddressBook* abs);
#endif;
