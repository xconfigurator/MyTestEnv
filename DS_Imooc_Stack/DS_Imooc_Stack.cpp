/*
@since 2016/12/16
@Author liuyang

先说结论：imooc的这个stack实现非常别扭。不需要再看了，还是直接用stl的吧。

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
	//char str[] = "[()()]";
	//char str[] = "[()[()]]";
	//char str[] = "[[()]";
	char str[] = "[()]]";// 在imooc的栈实现中，仅判栈空是有问题的。通过swith中的语句在修复。这个就很别扭了。所以放弃imooc的这个stack的实现吧。看stl的或者是larry的。

	char currentNeed = 0;// 当前需要的字符，储值给一个不可见字符的ASCII值。

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] != currentNeed) {// 读到的不是急需的
			pStack->push(str[i]);
			switch (str[i]) {
			case '[':
				if (currentNeed != 0) {
					pNeedStack->push(currentNeed);
				}
				currentNeed = ']';
				break;
			case '(':
				if (currentNeed != 0) {
					pNeedStack->push(currentNeed);
				}
				currentNeed = ')';
				break;
			default:// fix 
				cout << "字符串括号不匹配" << endl;
				return 0;
			}
		}
		else {// 读到的就是需要的
			char elem;
			pStack->pop(elem);
			if (!pNeedStack->pop(currentNeed)) {// fix 如果出栈不正常。
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