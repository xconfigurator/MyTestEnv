/*
@author liuyang
@since 2021/2/21

������
https://pintia.cn/problem-sets/994805260223102976/problems/994805309963354112

˵����
ʹ��Eratosthenes

һЩ���Ծ��飺
�����þ͵���
�ڴ泬��͵�С
��һЩ����֤�������⣬�Ǿ��Դ��ok��

���⣺
�޷��򿪡�cygwin.S��: �޷���ȡ�ļ�'c:\mingw810\src\gcc-8.1.0\libgcc\config\i386\cygwin.S' (Error: �޷����������ڵ��ļ�"c:\mingw810\src\gcc-8.1.0\libgcc\config\i386\cygwin.S")��

����


�ο���Ƶ��
https://www.bilibili.com/video/BV1Ty4y1n7JH?p=15&spm_id_from=pageDriver

����������
5 27
���������
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/
#include <iostream>
using namespace std;

const int MAX_SIZE = 1000001; // ���Ǹ����о�ֵ�������������ٵ�����
int p[MAX_SIZE] = { 0 };

void findPrime(int n, int prime[]) {
    // int p[MAX_SIZE] = { 0 };
    int num = 0;// ��¼��ǰ�Ѿ���õ���������
    for (int i = 2; i < MAX_SIZE; ++i) {
        if (p[i] == 0) {
            prime[num++] = i;// ��������д���������
            if (num >= n) {
                break;
            }
            for (int j = i + i; j < MAX_SIZE; j += i) {// ɨ������i�ı���
                p[j] = 1;
            }
        }
    }

}

int main(int argc, char const *argv[]) {
    int M, N, count = 0;
    int prime[10000] = { 0 };
    cin >> M >> N;
    findPrime(N, prime);
    for (int i = M; i <= N; ++i) {
        cout << prime[i - 1];
        ++count;
        if (count % 10 != 0 && i < N) {
            cout << "  ";
        }
        else {
            cout << endl;
        }
    }
    return 0;
}