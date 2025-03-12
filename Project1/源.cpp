#include <iostream>
using namespace std;
#define ADDRESS 0x123

int main(int argc, char* argv[])
{
    int* ptr = (int*)ADDRESS; // 将地址强制转换为int指针类型

   // printf("&ADDRESS = %p\n", (void*)&ADDRESS);
   // printf("ADDRESS = %d\n", ADDRESS);

    cout << "&ADDRESS = %p\n" << (void*)ADDRESS << endl;
    cout << "&ADDRESS = %p\n" << ADDRESS << endl;
    //*ptr = 1; // 在指定地址上写入数值1

    cout << "&ptr = %p\n" << (void*)ADDRESS << endl;
    cout << "&ptr = %p\n" << *ptr << endl;

   // printf("ptr = %p\n", (void*)ptr);
   // printf("ptr = %d\n", *ptr);
    system("pause");
    return 0;
}
