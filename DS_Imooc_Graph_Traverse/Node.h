#pragma once

class Node 
{
public:
	Node(char data = 0);
	char m_cData;
	bool m_bIsVisited;// 标识当前节点有没有被访问过
};