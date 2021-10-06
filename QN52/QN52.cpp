// QN52.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 多态/52.大学师生类
// 可参考视频：http://www.imooc.com/learn/426

#include <iostream>
#include "school.h"

int main()
{
    //std::cout << "Hello World!\n";

    // 过不去 
    // error C2664: “Student::Student(char *,char *,char *,char *,char *,char *,int,int)”: 无法将参数 1 从“const char [9]”转换为“char *”
    // 粘回VSCode用gcc编吧。
    /*
    Student myStudent(
    "Wangchen"
    , "1234 Park lane"
    , "colorado springs"
    , "co."
    , "80907"
    , "computer science"
    , 1234
    , 4);
    myStudent.Print();

    Staff myStaff(
    "Chenwang"
    , "1234Silver lane"
    , "mauitou springs"
    , "co."
    , "12345"
    , "Electrical Engineer"
    , 7.20);
    myStaff.Print();

    Professor myProfessor(
    "Chenchen"
    , "1234567ABC land"
    , "colorado springs"
    , "co."
    , "80907"
    , "computer science"
    , 80.40000);
    myProfessor.Print();

    StudentStaff myPoor(
    "Wangwang"
    ,"76541234 DEFlane"
    , "colorado springs"
    , "co."
    , "80907"
    , "computer science"
    , 1111
    , 3
    , "Electrical Engineering"
    , 5.80);
    myPoor.Print();
    */

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
