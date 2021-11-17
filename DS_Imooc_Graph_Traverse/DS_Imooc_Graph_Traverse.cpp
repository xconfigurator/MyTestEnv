// DS_Imooc_Graph_Traverse.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
         A
       /   \
      B     D
     / \   /  \
    C   F  G- H
     \ /
      E

// 邻接矩阵表示
  A B C D E F G H
A 0 1 0 1 0 0 0 0
B 1 0 1 0 0 1 0 0
C 0 1 0 0 1 0 0 0
D 1 0 0 0 0 0 1 1
E 0 0 1 0 0 1 0 0
F 0 1 0 0 1 0 0 0
G 0 0 0 1 0 0 0 1
H 0 0 0 1 0 0 1 0
*/

#include <iostream>
#include "CMap.h"
using namespace std;

int main()
{
    CMap* pMap = new CMap(8);

    // 顶点
    /*
    Node* pNodeA = new Node('A');
    Node* pNodeB = new Node('B');
    Node* pNodeC = new Node('C');
    Node* pNodeD = new Node('D');
    Node* pNodeE = new Node('E');
    Node* pNodeF = new Node('F');
    Node* pNodeG = new Node('G');
    Node* pNodeH = new Node('H');
    */
    
    // Vertices
    pMap->addNode(new Node('A'));
    pMap->addNode(new Node('B'));
    pMap->addNode(new Node('C'));
    pMap->addNode(new Node('D'));
    pMap->addNode(new Node('E'));
    pMap->addNode(new Node('F'));
    pMap->addNode(new Node('G'));
    pMap->addNode(new Node('H'));

    // Edge
    // 边(无向图 只传入一半即可 这里只传主对角线右上侧三角形)
    pMap->setValueToMatrixForUndirectedGraph(0, 1);
    pMap->setValueToMatrixForUndirectedGraph(0, 3);
    pMap->setValueToMatrixForUndirectedGraph(1, 2);
    pMap->setValueToMatrixForUndirectedGraph(1, 5);
    pMap->setValueToMatrixForUndirectedGraph(3, 6);
    pMap->setValueToMatrixForUndirectedGraph(3, 7);
    pMap->setValueToMatrixForUndirectedGraph(6, 7);
    pMap->setValueToMatrixForUndirectedGraph(2, 4);
    pMap->setValueToMatrixForUndirectedGraph(4, 5);

    pMap->printMatrix();
    cout << endl;
    

    pMap->resetNode();
    pMap->depthFirstTraverse(0);// DFS
    cout << endl;

    pMap->resetNode();
    pMap->breadthFirstTraverse(0);// BFS
    cout << endl;
    return 0;
}