// test_stdarg.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

// TODO 为啥这个运行出来的结果跟使用gcc的不一样？ 202310161911
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <iomanip>

void show_array(const double ar[], int n);
double* new_d_array(int n, ...);

int main() {
    double* p1;
    double* p2;
    p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
    show_array(p1, 5);
    show_array(p2, 4);
    free(p1);
    free(p2);
    
    return 0;
}

void show_array(const double ar[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%.2lf ", ar[i]);
    }
    printf("\n");
}

double* new_d_array(int n, ...) {
    double* ar = (double*)malloc(n * sizeof(int));

    va_list ap;
    va_start(ap, n);// 读取参数列表中的参数个数
    for (int i = 0; i < n; ++i) {
        ar[i] = va_arg(ap, double);
    }
    va_end(ap);
    return ar;
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
