#include <iostream>
using namespace std;
#include <string>

class Student
{
public:
	string name;
	string ID_card;

	void input_name(void)
	{
		cout << "������ѧ��������" << endl;
		cin >> name;
	}

	void input_card(void)
	{
		cout << "������ѧ�ţ�" << endl;
		cin >> ID_card;
	}

	void show_student(void)
	{
		cout << "������" << name << endl;
		cout << "ѧ�ţ�" << ID_card << endl;
	}
};

int main()
{
	Student LQ;
	LQ.input_name();
	LQ.input_card();
	LQ.show_student();

	system("pause");
	return 0;
}
