 // c6-1.h ��������˳��洢��ʾ
#pragma once
 #define MAX_TREE_SIZE 100 // ���������������
 typedef TElemType SqBiTree[MAX_TREE_SIZE]; // 0�ŵ�Ԫ�洢�����

 struct position
 {
   int level,order; // ���Ĳ�,�������(��������������)
 };

 /* ��һ��Ԫ��i = 0��˫�׽ڵ�Ϊ(i+1)/2-1��
  * ������Ϊ2*e+1��������Ϊ2*e+2
  * ����Ԫ�ص����ֵ���Ϊi=pow(2,BiTreeDepth(T)))-2
  * i=(int)pow(2,p.level-1)+p.order-2; // ���㡢�������תΪ��������
  * ��ѯ���㣬���洢Ч�ʲ���
  */