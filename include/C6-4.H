 // c6-4.h ����˫�ױ��洢��ʾ
#pragma once
 #define MAX_TREE_SIZE 100
 struct PTNode
 {
   TElemType data;
   int parent; // ˫��λ����
 };
 struct PTree
 {
   PTNode nodes[MAX_TREE_SIZE];
   int n; // �����
 };