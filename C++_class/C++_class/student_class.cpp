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
		cout << "请输入学生姓名：" << endl;
		cin >> name;
	}

	void input_card(void)
	{
		cout << "请输入学号：" << endl;
		cin >> ID_card;
	}

	void show_student(void)
	{
		cout << "姓名：" << name << endl;
		cout << "学号：" << ID_card << endl;
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
