/*
4.1.c �ַ�����ͳ����
���дһ��C�������ն��ü��������ַ�������Ctrl+Z��ϼ���ʾ������ϡ�
ͳ��������ַ����пո�����Ʊ�������з��ĸ���������ʾͳ�ƵĽ����
*/
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
int main() {
    char c;
    int space = 0, table = 0, enter = 0;
    // printf("EOF == %d", EOF);
    printf("Please input a string: \n");
    // scanf("%c", &c);
    while ((c = getchar()) != EOF) {
        switch (c) {
        case 32:
            space++;
            break;
        case 9:
            table++;
            break;
        case 10:
            enter++;
            break;
        default:
            break;
        }
        // scanf("%c", &c);
    }
    printf("The number of space: %d\n", space);
    printf("The number of table: %d\n", table);
    printf("The number of enter: %d\n", enter);
    getchar();
    return 0;
}