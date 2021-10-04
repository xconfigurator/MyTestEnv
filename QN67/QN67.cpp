// QN67.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 模板/67. 双向链表模板类 P146
/*
请设计一个双向链表模板类容器（container）。
通过采用一个指向容器对象的指针，让该类避免不必要的对象拷贝。
*/

#include <iostream>
#include "dlinktemplate.h"
using namespace std;

int main()
{
    //std::cout << "Hello World!\n";
    DLink<double> list1;
    //list1.Add(34.5);// 非常量引用的初始值必须为左值
    //list1.Add(57.8);
    //list1.Add(22.6);
    double d1 = 34.5, d2 = 57.8, d3 = 22.6;
    list1.Add(d1);
    list1.Add(d2);
    list1.Add(d3);
    list1.PrintFList();
    list1.PrintLList();

    DLink<int> list2;
    int i1 = 23, i2 = 58, i3 = 69, i4 = 77, i5 = 91;
    list2.Add(i1);
    list2.Add(i2);
    list2.Add(i3);
    list2.Add(i4);
    list2.Add(i5);
    list2.PrintFList();
    int i = 77;
    list2.Remove(i);
    list2.PrintFList();
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
