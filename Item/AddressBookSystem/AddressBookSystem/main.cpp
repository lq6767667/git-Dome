#include <iostream>
#include "AddressBook.h"

//ͨѶ¼����ϵͳ�����õ����������ʽ����������ʽ

int main()
{
	struct AddressBook abs;//����ͨѶ¼

	abs.m_Size = 0;

	int select = 0;

	while (true)
	{
		Address_Menu();

		cin >> select;

		switch (select)
		{
			case 1://���
				add_Person(&abs);
				break;
	
			case 2://ɾ��
				deletePerson(&abs);
				break;

			case 3://�޸�
				revise_Person(&abs);
				break;

			case 4://����
				find_Person(abs);
				break;

			case 5://���
				clear_Person(&abs);
				break;
	
			case 6://��ʾ
				show_Person(abs);
				break;

			case 0:
				cout << "��ӭ�´�ʹ��\n" << endl;
				system("pause");
				return 0;
				break;
		}
	}
}
