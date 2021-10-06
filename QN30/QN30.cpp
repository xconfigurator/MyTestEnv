// QN30.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 简单类/30. 单词和词典类
/*
def.h       单词类定义
def.cpp     单词类的实现
diction.h   词典类定义
diction.cpp 词典类的实现

书上给出的程序不能通过编译，加了一些const之后就过了。202110061932
*/

#include <iostream>
#include "diction.h"
using namespace std;

int main()
{
    //std::cout << "Hello World!\n";
    Dictionary d(5);    // the d dictionary include maximum of 5 words
    
    const char* word1 = "class";
    const char* indef1[] = {"班级", "[计算机]类", "阶级", "课", "等级", 0};

    const char* word2 = "object";
    const char* indef2[] = {"目的", "对象", "物体", "[语法]宾语", "[哲学]客观", 0};

    const char* word3 = "snow";
    const char* indef3[] = {"雪", "雪花效应", 0};

    Definition def1(word1, indef1);
    Definition def2(word2, indef2);
    Definition def3(word3, indef3);

    d.AddWord(def1);
    d.AddWord(def2);
    d.AddWord(def3);

    d.Print(word1);
    d.Print(word2);
    d.Print(word3);

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
