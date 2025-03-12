#include <iostream>
using namespace std;

//��������(�����ÿ������)
//CPU
class CPU
{
public:
	virtual void calculate() = 0;
};

//�Կ�videoCard
class VideoCard
{
public:
	virtual void display() = 0;
};

//�ڴ���Memory
class Memory
{
public:
	virtual void storage() = 0;
};
//===============
//����
class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vd, Memory* mem)
	{
		c_cpu = cpu;
		c_vd = vd;
		c_mem = mem;
	}

	//���Թ���
	void work()
	{
		c_cpu->calculate();
		c_vd->display();
		c_mem->storage();
	}

	//�ͷ��ڶѴ����Ķ���
	~Computer()
	{
		if (c_cpu != NULL)
		{
			delete c_cpu;
			c_cpu = NULL;
		}
		if (c_vd != NULL)
		{
			delete c_vd;
			c_vd = NULL;
		}
		if (c_mem != NULL)
		{
			delete c_mem;
			c_mem = NULL;
		}
	}

private:
	CPU* c_cpu;
	VideoCard* c_vd;
	Memory* c_mem;
};

//=====================
//����Intel
class IntelCpu : public CPU
{
public:
	void calculate()
	{
		cout << "Intel��cpu��ʼ����" << endl;
	}
};

class IntelVideoCard : public VideoCard
{
public:
	void display()
	{
		cout << "Intel���Կ���ʼ����" << endl;
	}
};

class IntelMemory : public Memory
{
public:
	void storage()
	{
		cout << "Intel���ڴ�����ʼ����" << endl;
	}
};
//==================================
//����Lenovo
class LenovoCpu : public CPU
{
public:
	void calculate()
	{
		cout << "Lenovo��cpu��ʼ����" << endl;
	}
};

class LenovoVideoCard : public VideoCard
{
public:
	void display()
	{
		cout << "Lenovo���Կ���ʼ����" << endl;
	}
};

class LenovoMemory : public Memory
{
public:
	void storage()
	{
		cout << "Lenovo���ڴ�����ʼ����" << endl;
	}
};
//=========================================

void test()
{
	//��̬�ص�֮һ������ָ�������ָ���������
	//Intel���̵����
	CPU* cpu = new IntelCpu;
	VideoCard* vd = new IntelVideoCard;
	Memory* mem = new IntelMemory;

	//����1
	Computer* com1 = new Computer(cpu, vd, mem);
	com1->work();
	delete com1;

	cout << "--------------------" << endl;

	//����2
	Computer* com2 = new Computer(new LenovoCpu, new LenovoVideoCard, new LenovoMemory);
	com2->work();
	delete com2;

	cout << "--------------------" << endl;

	//����2
	Computer* com3 = new Computer(new LenovoCpu, new IntelVideoCard, new LenovoMemory);
	com3->work();
	delete com3;
}
int main()
{
	test();
	system("pause");
	return 0;
}
