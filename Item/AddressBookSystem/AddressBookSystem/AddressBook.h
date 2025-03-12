#pragma once
#ifndef __ADDRESSBOOKSYSTEM_H
#define __ADDRESSBOOKSYSTEM_H

#include <string>
using namespace std;
#define MAX 1000

//联系人信息
struct person_info
{
	string name;
	string m_Sex;
	int m_Age;
	string m_phone;//电话
	string m_Addr;//住址

};

//通讯录
struct AddressBook
{
	struct person_info personArray[MAX];//通讯录中保存的联系人数组
	int m_Size;//人员个数

};

void Address_Menu(void);
void add_Person(struct AddressBook*);
void show_Person(const AddressBook abs);
void find_Person(AddressBook abs);
void deletePerson(AddressBook* abs);
void revise_Person(AddressBook* abs);
void clear_Person(AddressBook* abs);
#endif;
