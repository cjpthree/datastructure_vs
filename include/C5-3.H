 // c5-3.h ϡ��������Ԫ�����߼����ӵ�˳����洢��ʾ
#pragma once
 #define MAXSIZE 100 // ����Ԫ���������ֵ
 #define MAXRC 20 // ���������
 struct Triple // ͬc5-2.h
 {
   int i,j; // ���±�,���±�
   ElemType e; // ����Ԫ��ֵ
 };
 struct RLSMatrix
 {
   Triple data[MAXSIZE+1]; // ����Ԫ��Ԫ���,data[0]δ��
   int rpos[MAXRC+1]; // ���е�һ������Ԫ�ص�λ�ñ�,��c5-2.h���ӵ���
   int mu,nu,tu; // ����������������ͷ���Ԫ����
 };