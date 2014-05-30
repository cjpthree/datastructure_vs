 // c6-1.h 二叉树的顺序存储表示
#pragma once
 #define MAX_TREE_SIZE 100 // 二叉树的最大结点数
 typedef TElemType SqBiTree[MAX_TREE_SIZE]; // 0号单元存储根结点

 struct position
 {
   int level,order; // 结点的层,本层序号(按满二叉树计算)
 };

 /* 第一个元素i = 0，双亲节点为(i+1)/2-1，
  * 左子树为2*e+1，右子树为2*e+2
  * 最后的元素的序号值最大为i=pow(2,BiTreeDepth(T)))-2
  * i=(int)pow(2,p.level-1)+p.order-2; // 将层、本层序号转为矩阵的序号
  * 查询方便，但存储效率不高
  */
