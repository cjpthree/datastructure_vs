 // bo10-2.cpp ��������ĺ���
 static void QSort(SqList &L,int low,int high)
 { // ��˳���L�е�������L.r[low..high]�����������㷨10.7
   int pivotloc;
   if(low<high)
   { // ���ȴ���1
     pivotloc=Partition(L,low,high); // ��L.r[low..high]һ��Ϊ��
     QSort(L,low,pivotloc-1); // �Ե��ӱ�ݹ�����pivotloc������λ��
     QSort(L,pivotloc+1,high); // �Ը��ӱ�ݹ�����
   }
 }

 static void QuickSort(SqList &L)
 { // ��˳���L�����������㷨10.8
   QSort(L,1,L.length);
 }

 static void print(SqList L)
 {
   int i;
   for(i=1;i<=L.length;i++)
     printf("(%d,%d)",L.r[i].key,L.r[i].otherinfo);
   printf("\n");
 }