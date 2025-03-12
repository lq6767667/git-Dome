#include <iostream>
using namespace std;

//动物类（基类）
class Animal
{
public:
	//虚函数
	virtual void spack()
	{
		cout << "动物在说话" << endl;
	}
};

//猫类（子类）
class Cat : public Animal
{
public:
	//重写： 函数返回值 函数名 参数列表	要完全与父类虚函数相同，virtual关键词可写可不写
	void spack()
	{
		cout << "猫在说话" << endl;
	}
};

//狗类（子类）
class Dog : public Animal
{
public:
	void spack()
	{
		cout << "狗在说话" << endl;
	}
};
//==============================================================//

//地址早绑定  就是在编译阶段确定函数地址
//如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，也就是地址晚绑定

//动态多态满足条件
//1. 有继承关系
//2. 子类重写父类的虚函数

//多态的使用
//父类指针或引用指向子类对象
void doSpack(Animal& animal)// Animal & animal = cat
{
	animal.spack();
}

void test()
{
	Cat cat;
	doSpack(cat);

	Dog dog;
	doSpack(dog);
}

int main()
{
	test();
	system("pause");
	return 0;
}
