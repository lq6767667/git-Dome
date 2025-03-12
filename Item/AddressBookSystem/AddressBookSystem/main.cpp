#include <iostream>
#include "AddressBook.h"

//通讯录管理系统，采用的是数组的形式，非链表形式

int main()
{
	struct AddressBook abs;//创建通讯录

	abs.m_Size = 0;

	int select = 0;

	while (true)
	{
		Address_Menu();

		cin >> select;

		switch (select)
		{
			case 1://添加
				add_Person(&abs);
				break;
	
			case 2://删除
				deletePerson(&abs);
				break;

			case 3://修改
				revise_Person(&abs);
				break;

			case 4://查找
				find_Person(abs);
				break;

			case 5://清空
				clear_Person(&abs);
				break;
	
			case 6://显示
				show_Person(abs);
				break;

			case 0:
				cout << "欢迎下次使用\n" << endl;
				system("pause");
				return 0;
				break;
		}
	}
}
