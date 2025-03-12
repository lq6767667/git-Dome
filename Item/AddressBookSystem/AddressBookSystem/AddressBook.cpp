#include <iostream>
#include "AddressBook.h"

void Address_Menu(void)
{
	cout << "**********************" << endl;
	cout << "*    1.添加联系人    *" << endl;
	cout << "*    2.删除联系人    *" << endl;
	cout << "*    3.修改联系人    *" << endl;
	cout << "*    4.查找联系人    *" << endl;
	cout << "*    5.清空联系人    *" << endl;
	cout << "*    6.显示联系人    *" << endl;
	cout << "*    0.退出通讯录    *" << endl;
	cout << "**********************" << endl;
}

void add_Person(AddressBook * abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，添加失败！" << endl;
		return;
	}
	else
	{
		string name;
		cin.clear();//清除cin的错误信息
		cin.ignore();//忽略掉缓冲区的内容，直到遇到EOF为止
		cout << "请输入姓名:" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].name = name;

		int sex = 0;
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl << "2---女" << endl;
		while(true)
		{
			cin.clear();//清除cin的错误信息
			cin.ignore();//忽略掉缓冲区的内容，直到遇到EOF为止
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				if (sex == 1)
					abs->personArray[abs->m_Size].m_Sex = "男";
				else
					abs->personArray[abs->m_Size].m_Sex = "女";
				break;
			}
			else
				cout << "输入错误，请重新输入！" << endl;
		}

		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		string phonenumber;
		cout << "请输入号码：" << endl;
		cin >> phonenumber;
		abs->personArray[abs->m_Size].m_phone = phonenumber;

		string addr;
		cout << "请输入地址：" << endl;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;

		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功" << endl;

		system("pause");
		system("cls");//清屏
	}

}

void show_Person(const AddressBook abs)
{
	if (abs.m_Size == 0)
	{
		cout << "当前通讯录为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		for (int i=0; i<abs.m_Size; i++)
		{
			cout << "姓名：" << abs.personArray[i].name << "\t";
			cout << "性别：" << abs.personArray[i].m_Sex << "\t";
			cout << "年龄：" << abs.personArray[i].m_Age << "\t";
			cout << "号码：" << abs.personArray[i].m_phone << "\t";
			cout << "地址：" << abs.personArray[i].m_Addr << endl;
		}
		cout << endl;
		system("pause");
		system("cls");
	}
}

int isExist(AddressBook abs, string name)
{
	if (abs.m_Size != 0)
	{
		for (int i = 0; i < abs.m_Size; i++)
		{
			if (name == abs.personArray[i].name)
			{
				return i;
			}
		}
		return -1;
	}
	else
		return -1;
}

void deletePerson(AddressBook* abs)
{
	string name;
	cout << "请输入要删除的联系人姓名：";
	cin >> name;
	int w_person = isExist(*abs, name);

	if (w_person == -1)
	{
		cout << "要删除的联系人不存在！" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		int select = 0;
		cout << "确定删除该联系人（1.确定 2.取消）：";
		cin >> select;

		if (select == 1)
		{
			for (int i = w_person; i < abs->m_Size; i++)
			{
				//数据前移
				abs->personArray[i] = abs->personArray[i + 1];
			}
			abs->m_Size--;
			cout << "删除成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "已取消操作！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void find_Person(AddressBook abs)
{
	cout << "请输入需要查找的联系人：";
	string f_person;
	cin >> f_person;

	int ret = isExist(abs, f_person);
	if (ret != -1)
	{
		cout << "姓名：" << abs.personArray[ret].name << "\t";
		cout << "性别：" << abs.personArray[ret].m_Sex << "\t";
		cout << "年龄：" << abs.personArray[ret].m_Age << "\t";
		cout << "号码：" << abs.personArray[ret].m_phone << "\t";
		cout << "地址：" << abs.personArray[ret].m_Addr << endl;

	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
	return;
}

//修改
void revise_Person(AddressBook* abs)
{
	cout << "请输入需要修改的联系人：";
	string name;
	cin >> name;
	int ret = isExist(*abs, name);
	if (ret != -1)
	{

			int rev = 0;
			cout << "请输入需要修改的内容：" << endl;
			cout << "1-姓名" << endl;
			cout << "2-姓别" << endl;
			cout << "3-年龄" << endl;
			cout << "4-电话" << endl;
			cout << "5-住址" << endl;
			cin >> rev;

			switch (rev)
			{
			case 1:
			{
				string name;
				cin.clear();//清除cin的错误信息
				cin.ignore();//忽略掉缓冲区的内容，直到遇到EOF为止
				cout << "请输入修改后的姓名:" << endl;
				cin >> name;
				abs->personArray[ret].name = name;
				cout << "修改成功" << endl << endl;
				break;
			}

			case 2:
			{
				int sex = 0;
				cout << "请输入修改后的性别：" << endl;
				cout << "1---男" << endl << "2---女" << endl;
				while (true)
				{
					cin.clear();//清除cin的错误信息
					cin.ignore();//忽略掉缓冲区的内容，直到遇到EOF为止
					cin >> sex;
					if (sex == 1 || sex == 2)
					{
						if (sex == 1)
							abs->personArray[ret].m_Sex = "男";
						else
							abs->personArray[ret].m_Sex = "女";
						break;
					}
					else
						cout << "输入错误，请重新输入！" << endl;
				}
				cout << "修改成功" << endl << endl;
				break;
			}

			case 3:
			{
				int age = 0;
				cout << "请输入修改后的年龄：" << endl;
				cin >> age;
				abs->personArray[ret].m_Age = age;
				cout << "修改成功" << endl << endl;
				break;
			}
			

			case 4:
			{
				string phonenumber;
				cout << "请输入修改后的号码：" << endl;
				cin >> phonenumber;
				abs->personArray[ret].m_phone = phonenumber;
				cout << "修改成功" << endl << endl;
				break;
			}
			

			case 5:
			{
				string addr;
				cout << "请输入修改后的地址：" << endl;
				cin >> addr;
				abs->personArray[ret].m_Addr = addr;
				cout << "修改成功" << endl << endl;
				break;
			}
			

			default:
			{
				cout << "输入无效，请重新输入！" << endl << endl;
				system("pause");
				system("cls");//清屏
				break;
			}
				
			}

		system("pause");
		system("cls");//清屏
		return;
	}
	else
	{
		cout << "查无此人" << endl;
		system("pause");
		system("cls");
		return;
	}
}

void clear_Person(AddressBook* abs)
{
	cout << "确定清空通讯录！（1.确定 2.取消）" << endl;
	int sel = 0;
	cin >> sel;

	if (sel == 1)
	{
		abs->m_Size = 0;
		cout << "已清空" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "已取消操作！" << endl;
		system("pause");
		system("cls");
		return;
	}
	
}
