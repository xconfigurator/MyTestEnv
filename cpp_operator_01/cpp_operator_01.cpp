// cpp_operator_01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}
*/
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class StrType {
public:
    StrType() { *s = '\0'; }
    StrType(const char* p) { strcpy(s, p); }
    char* Get() { return s; }
    StrType& operator + (StrType& s2);
    StrType& operator = (StrType& s2);
    int operator < (StrType& s2);
    int operator > (StrType& s2);
    int operator == (StrType& s2);
private:
    char s[80];
};

StrType& StrType::operator + (StrType& s2) {
    StrType* t = new StrType();
    strcpy(t->s, s);
    strcat(t->s, s2.s);
    return *t;
}

StrType& StrType::operator = (StrType& s2) {
    strcpy(s, s2.s);// Setmentation fault
    return *this;
}

int StrType::operator < (StrType& s2) {
    return strcmp(s, s2.s) < 0;
}

int StrType::operator > (StrType& s2) {
    return strcmp(s, s2.s) > 0;
}

int StrType::operator == (StrType& s2) {
    return strcmp(s, s2.s) == 0;
}

int main(int argc, char const* argv[]) {
    StrType o1("Hello"), o2("There"), o3;
    cout << "o1 = " << o1.Get() << endl;
    cout << "o2 = " << o2.Get() << endl;
    o3 = o1 + o2;
    cout << "o3 = o1 + o2 = " << o3.Get() << endl;

    o3 = o1;
    cout << "o1 = o3" << endl;
    if (o1 == o3) cout << "o1 equals o3" << endl;

    if (o1 > o2) cout << "o1 > o2" << endl;

    if (o1 < o2) cout << "o1 < o2" << endl;
    return 0;
}