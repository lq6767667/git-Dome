#include <iostream>
using namespace std;
#define ADDRESS 0x123

int main(int argc, char* argv[])
{
    int* ptr = (int*)ADDRESS; // ����ַǿ��ת��Ϊintָ������

   // printf("&ADDRESS = %p\n", (void*)&ADDRESS);
   // printf("ADDRESS = %d\n", ADDRESS);

    cout << "&ADDRESS = %p\n" << (void*)ADDRESS << endl;
    cout << "&ADDRESS = %p\n" << ADDRESS << endl;
    //*ptr = 1; // ��ָ����ַ��д����ֵ1

    cout << "&ptr = %p\n" << (void*)ADDRESS << endl;
    cout << "&ptr = %p\n" << *ptr << endl;

   // printf("ptr = %p\n", (void*)ptr);
   // printf("ptr = %d\n", *ptr);
    system("pause");
    return 0;
}
