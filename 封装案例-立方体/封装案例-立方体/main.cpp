#include <iostream>
using namespace std;

class Cube
{
//行为
public:
	//设置、获取长宽高
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

	//面积
	int area(void)
	{
		return (m_L * m_W + m_L * m_H + m_W * m_H) * 2;
	}
	//体积
	int volume(void)
	{
		return m_L * m_W * m_H;
	}

	//使用成员函数判断是否相同
	bool m_isSame(Cube c)
	{
		if (m_L == c.getL() && m_H == c.getH() && m_W == c.getW())
		{
			return true;
		}
		return false;
	}

//属性
private:
	unsigned int m_L;
	unsigned int m_W;
	unsigned int m_H;
};


//使用全局函数判断，两立方体是否相等
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

	cout << "c1面积为：" << c1.area() << endl;
	cout << "c1体积为：" << c1.volume() << endl;

	Cube c2;
	c2.setL(10);
	c2.setW(11);
	c2.setH(10);

	bool ret = isSame(c1,c2);
	if (ret)
	{
		cout << "两立方体相同" << endl;
	}
	else
	{
		cout << "两立方体bu同" << endl;
	}

	bool ret2 = c1.m_isSame(c2);
	if (ret2)
	{
		cout << "两立方体相同" << endl;
	}
	else
	{
		cout << "两立方体bu同" << endl;
	}

	system("pause");
	return 0;
}
