#include <iostream>
using namespace std;

//创建父类(抽象出每个两件)
//CPU
class CPU
{
public:
	virtual void calculate() = 0;
};

//显卡videoCard
class VideoCard
{
public:
	virtual void display() = 0;
};

//内存条Memory
class Memory
{
public:
	virtual void storage() = 0;
};
//===============
//电脑
class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vd, Memory* mem)
	{
		c_cpu = cpu;
		c_vd = vd;
		c_mem = mem;
	}

	//电脑工作
	void work()
	{
		c_cpu->calculate();
		c_vd->display();
		c_mem->storage();
	}

	//释放在堆创建的对象
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
//厂商Intel
class IntelCpu : public CPU
{
public:
	void calculate()
	{
		cout << "Intel的cpu开始工作" << endl;
	}
};

class IntelVideoCard : public VideoCard
{
public:
	void display()
	{
		cout << "Intel的显卡开始工作" << endl;
	}
};

class IntelMemory : public Memory
{
public:
	void storage()
	{
		cout << "Intel的内存条开始工作" << endl;
	}
};
//==================================
//厂商Lenovo
class LenovoCpu : public CPU
{
public:
	void calculate()
	{
		cout << "Lenovo的cpu开始工作" << endl;
	}
};

class LenovoVideoCard : public VideoCard
{
public:
	void display()
	{
		cout << "Lenovo的显卡开始工作" << endl;
	}
};

class LenovoMemory : public Memory
{
public:
	void storage()
	{
		cout << "Lenovo的内存条开始工作" << endl;
	}
};
//=========================================

void test()
{
	//多态特点之一：父类指针或引用指向子类对象
	//Intel厂商的零件
	CPU* cpu = new IntelCpu;
	VideoCard* vd = new IntelVideoCard;
	Memory* mem = new IntelMemory;

	//电脑1
	Computer* com1 = new Computer(cpu, vd, mem);
	com1->work();
	delete com1;

	cout << "--------------------" << endl;

	//电脑2
	Computer* com2 = new Computer(new LenovoCpu, new LenovoVideoCard, new LenovoMemory);
	com2->work();
	delete com2;

	cout << "--------------------" << endl;

	//电脑2
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
