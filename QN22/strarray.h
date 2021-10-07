#pragma once
typedef char* String;

int ReadString(String& s);// 返回1表示成功读入

void Insert(String strList[], String& s);

void Output(String strList[]);

int Search(String strList[], String& str);