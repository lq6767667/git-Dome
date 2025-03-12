#include <iostream>
#include "AddressBook.h"

void Address_Menu(void)
{
	cout << "**********************" << endl;
	cout << "*    1.�����ϵ��    *" << endl;
	cout << "*    2.ɾ����ϵ��    *" << endl;
	cout << "*    3.�޸���ϵ��    *" << endl;
	cout << "*    4.������ϵ��    *" << endl;
	cout << "*    5.�����ϵ��    *" << endl;
	cout << "*    6.��ʾ��ϵ��    *" << endl;
	cout << "*    0.�˳�ͨѶ¼    *" << endl;
	cout << "**********************" << endl;
}

void add_Person(AddressBook * abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼���������ʧ�ܣ�" << endl;
		return;
	}
	else
	{
		string name;
		cin.clear();//���cin�Ĵ�����Ϣ
		cin.ignore();//���Ե������������ݣ�ֱ������EOFΪֹ
		cout << "����������:" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].name = name;

		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl << "2---Ů" << endl;
		while(true)
		{
			cin.clear();//���cin�Ĵ�����Ϣ
			cin.ignore();//���Ե������������ݣ�ֱ������EOFΪֹ
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				if (sex == 1)
					abs->personArray[abs->m_Size].m_Sex = "��";
				else
					abs->personArray[abs->m_Size].m_Sex = "Ů";
				break;
			}
			else
				cout << "����������������룡" << endl;
		}

		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		string phonenumber;
		cout << "��������룺" << endl;
		cin >> phonenumber;
		abs->personArray[abs->m_Size].m_phone = phonenumber;

		string addr;
		cout << "�������ַ��" << endl;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;

		//����ͨѶ¼����
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;

		system("pause");
		system("cls");//����
	}

}

void show_Person(const AddressBook abs)
{
	if (abs.m_Size == 0)
	{
		cout << "��ǰͨѶ¼Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		for (int i=0; i<abs.m_Size; i++)
		{
			cout << "������" << abs.personArray[i].name << "\t";
			cout << "�Ա�" << abs.personArray[i].m_Sex << "\t";
			cout << "���䣺" << abs.personArray[i].m_Age << "\t";
			cout << "���룺" << abs.personArray[i].m_phone << "\t";
			cout << "��ַ��" << abs.personArray[i].m_Addr << endl;
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
	cout << "������Ҫɾ������ϵ��������";
	cin >> name;
	int w_person = isExist(*abs, name);

	if (w_person == -1)
	{
		cout << "Ҫɾ������ϵ�˲����ڣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		int select = 0;
		cout << "ȷ��ɾ������ϵ�ˣ�1.ȷ�� 2.ȡ������";
		cin >> select;

		if (select == 1)
		{
			for (int i = w_person; i < abs->m_Size; i++)
			{
				//����ǰ��
				abs->personArray[i] = abs->personArray[i + 1];
			}
			abs->m_Size--;
			cout << "ɾ���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "��ȡ��������" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void find_Person(AddressBook abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ�";
	string f_person;
	cin >> f_person;

	int ret = isExist(abs, f_person);
	if (ret != -1)
	{
		cout << "������" << abs.personArray[ret].name << "\t";
		cout << "�Ա�" << abs.personArray[ret].m_Sex << "\t";
		cout << "���䣺" << abs.personArray[ret].m_Age << "\t";
		cout << "���룺" << abs.personArray[ret].m_phone << "\t";
		cout << "��ַ��" << abs.personArray[ret].m_Addr << endl;

	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
	return;
}

//�޸�
void revise_Person(AddressBook* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�";
	string name;
	cin >> name;
	int ret = isExist(*abs, name);
	if (ret != -1)
	{

			int rev = 0;
			cout << "��������Ҫ�޸ĵ����ݣ�" << endl;
			cout << "1-����" << endl;
			cout << "2-�ձ�" << endl;
			cout << "3-����" << endl;
			cout << "4-�绰" << endl;
			cout << "5-סַ" << endl;
			cin >> rev;

			switch (rev)
			{
			case 1:
			{
				string name;
				cin.clear();//���cin�Ĵ�����Ϣ
				cin.ignore();//���Ե������������ݣ�ֱ������EOFΪֹ
				cout << "�������޸ĺ������:" << endl;
				cin >> name;
				abs->personArray[ret].name = name;
				cout << "�޸ĳɹ�" << endl << endl;
				break;
			}

			case 2:
			{
				int sex = 0;
				cout << "�������޸ĺ���Ա�" << endl;
				cout << "1---��" << endl << "2---Ů" << endl;
				while (true)
				{
					cin.clear();//���cin�Ĵ�����Ϣ
					cin.ignore();//���Ե������������ݣ�ֱ������EOFΪֹ
					cin >> sex;
					if (sex == 1 || sex == 2)
					{
						if (sex == 1)
							abs->personArray[ret].m_Sex = "��";
						else
							abs->personArray[ret].m_Sex = "Ů";
						break;
					}
					else
						cout << "����������������룡" << endl;
				}
				cout << "�޸ĳɹ�" << endl << endl;
				break;
			}

			case 3:
			{
				int age = 0;
				cout << "�������޸ĺ�����䣺" << endl;
				cin >> age;
				abs->personArray[ret].m_Age = age;
				cout << "�޸ĳɹ�" << endl << endl;
				break;
			}
			

			case 4:
			{
				string phonenumber;
				cout << "�������޸ĺ�ĺ��룺" << endl;
				cin >> phonenumber;
				abs->personArray[ret].m_phone = phonenumber;
				cout << "�޸ĳɹ�" << endl << endl;
				break;
			}
			

			case 5:
			{
				string addr;
				cout << "�������޸ĺ�ĵ�ַ��" << endl;
				cin >> addr;
				abs->personArray[ret].m_Addr = addr;
				cout << "�޸ĳɹ�" << endl << endl;
				break;
			}
			

			default:
			{
				cout << "������Ч�����������룡" << endl << endl;
				system("pause");
				system("cls");//����
				break;
			}
				
			}

		system("pause");
		system("cls");//����
		return;
	}
	else
	{
		cout << "���޴���" << endl;
		system("pause");
		system("cls");
		return;
	}
}

void clear_Person(AddressBook* abs)
{
	cout << "ȷ�����ͨѶ¼����1.ȷ�� 2.ȡ����" << endl;
	int sel = 0;
	cin >> sel;

	if (sel == 1)
	{
		abs->m_Size = 0;
		cout << "�����" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "��ȡ��������" << endl;
		system("pause");
		system("cls");
		return;
	}
	
}
