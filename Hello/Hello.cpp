// Hello.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int main()
{
    // 注意！！！ 提高cin和cout处理速度的方法
    ios::sync_with_stdio(false);// 这样可以提高cin和cout的处理速度。
    std::cout << "Hello World!\n";

    // 202111101000
    cout << "#202111101000" << endl;
    int a[] = { -1 , 3, 1, 0, 2, 5, 6 };
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        cout << "a[" << i << " ] = " << a[i] << endl;
        if (!(a[i] == 0)) {
            cout << "foo" << endl;
        }
        else {
            cout << "bar" << endl;
        }
    }

    // 202111101004
    cout << "#202111101004" << endl;
    int arr[][3] = { {1}, {3, 2}, {4, 5, 6}, {0}};
    // TODO 查一下C++怎么输出二维数组
    /*
    for (auto &row : arr) {
        for (auto& col : row) {
            //cout << "row = " << row << "col = " << col << endl;
            cout << "row = " << row << "col = " << col << " row[col] = " << row[col] << "\t";
        }
        cout << endl;
    }
    */
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
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
