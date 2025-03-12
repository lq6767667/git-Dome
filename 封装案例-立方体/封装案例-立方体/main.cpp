#include <iostream>
using namespace std;

class Cube
{
//��Ϊ
public:
	//���á���ȡ�����
	void setL(int l)
	{
		m_L = l;
	}
	int getL(void)
	{
		return m_L;
	}

	void setW(int w)
	{
		m_W = w;
	}
	int getW(void)
	{
		return m_W;
	}

	void setH(int h)
	{
		m_H = h;
	}
	int getH(void)
	{
		return m_H;
	}

	//���
	int area(void)
	{
		return (m_L * m_W + m_L * m_H + m_W * m_H) * 2;
	}
	//���
	int volume(void)
	{
		return m_L * m_W * m_H;
	}

	//ʹ�ó�Ա�����ж��Ƿ���ͬ
	bool m_isSame(Cube c)
	{
		if (m_L == c.getL() && m_H == c.getH() && m_W == c.getW())
		{
			return true;
		}
		return false;
	}

//����
private:
	unsigned int m_L;
	unsigned int m_W;
	unsigned int m_H;
};


//ʹ��ȫ�ֺ����жϣ����������Ƿ����
bool isSame(Cube& c1, Cube& c2)
{
	if (c1.getL() == c2.getL() && c1.getH() == c2.getH() && c1.getW() == c2.getW())
	{
		return true;
	}
	return false;
}

int main()
{
	Cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);

	cout << "c1���Ϊ��" << c1.area() << endl;
	cout << "c1���Ϊ��" << c1.volume() << endl;

	Cube c2;
	c2.setL(10);
	c2.setW(11);
	c2.setH(10);

	bool ret = isSame(c1,c2);
	if (ret)
	{
		cout << "����������ͬ" << endl;
	}
	else
	{
		cout << "��������buͬ" << endl;
	}

	bool ret2 = c1.m_isSame(c2);
	if (ret2)
	{
		cout << "����������ͬ" << endl;
	}
	else
	{
		cout << "��������buͬ" << endl;
	}

	system("pause");
	return 0;
}
