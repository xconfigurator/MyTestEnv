/*
@since 2016/12/16
@Author liuyang
栈
字符串示例：[()]    [()()]    [()[()]]    [[()]	[()]]
编译环境：Visual Studio 2015 Community
*/
#include <iostream>
#include "MyStack.h"
using namespace std;


int main() {
	MyStack<char>* pStack = new MyStack<char>(100);// 
	MyStack<char>* pNeedStack = new MyStack<char>(100);// 急需的字符

	//char str[] = "[()]";
	char str[] = "[()()]";
	//char str[] = "[()[()]]";
	//char str[] = "[[()]";
	//char str[] = "[()]]";// 仅判栈空是有问题的。

	char currentNeed = 0;// 当前需要的字符，储值给一个不可见字符的ASCII值。

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] != currentNeed) {// 读到的不是急需的
			pStack->push(str[i]);
			if (currentNeed != 0) {
				pNeedStack->push(currentNeed);
			}
			switch (str[i]) {
			case '[':
				currentNeed = ']';
				break;
			case '(':
				currentNeed = ')';
				break;
			default:
				cout << "字符串不匹配。" << endl;
				return 0;
			}
		}
		else {// 读到的就是需要的
			char elem;
			pStack->pop(elem);
			if (!pNeedStack->pop(currentNeed)) {
				currentNeed = 0;
			}
		}
	}

	if (pStack->stackEmpty()) {
		cout << "字符串括号匹配" << endl;
	}
	else {
		cout << "字符串括号不匹配" << endl;
	}

	delete pStack;
	pStack = NULL;
	delete pNeedStack;
	pNeedStack = NULL;

	return 0;
}