 // algo8-3.cpp 实现算法8.3的程序
 #include"c1.h"
 typedef char AtomType; // 定义原子类型为字符型
 #include"c8-3.h"
 #include"bo5-51.cpp" 

 static Status CreateMarkGList(GList &L,SString S) // 由bo5-51.cpp改
 { // 采用头尾链表存储结构,由广义表的书写形式串S创建广义表L。设emp="()"
   SString sub,hsub,emp;
   GList p,q;
   StrAssign(emp,"()");
   if(!StrCompare(S,emp))
     L=NULL; // 创建空表
   else
   {
     if(!(L=(GList)malloc(sizeof(GLNode)))) // 建表结点
       exit(OVERFLOW);
     if(StrLength(S)==1) // S为单原子
     {
       L->tag=ATOM;
       L->atom=S[1]; // 创建单原子广义表
       L->mark=0; // 加
     }
     else
     {
       L->tag=LIST;
       L->mark=0; // 加
       p=L;
       SubString(sub,S,2,StrLength(S)-2); // 脱外层括号
       do
       { // 重复建n个子表
         sever(sub,hsub); // 从sub中分离出表头串hsub
         CreateMarkGList(p->ptr.hp,hsub); // 改
         q=p;
         if(!StrEmpty(sub)) // 表尾不空
         {
           if(!(p=(GLNode *)malloc(sizeof(GLNode))))
             exit(OVERFLOW);
           p->tag=LIST;
           p->mark=0; // 加
	   q->ptr.tp=p;
         }
       }while(!StrEmpty(sub));
       q->ptr.tp=NULL;
     }
   }
   return OK;
 }

 static void MarkList(GList GL) // 算法8.3
 { // 遍历非空广义表GL(GL!=NULL且GL->mark==0),对表中所有未加标志的结点加标志。
   GList t,p,q;
   Status finished;
   if(GL!=NULL&&GL->mark==0)
   {
     t=NULL; // t指示p的母表
     p=GL;
     finished=FALSE;
     while(!finished)
     {
       while(p->mark==0)
       {
	 p->mark=1; // MarkHead(p)的细化
         q=p->ptr.hp; // q指向*p的表头
         if(q&&q->mark==0)
           if(q->tag==0)
             q->mark=1; // ATOM,表头为原子结点
           else
           { // 继续遍历子表
             p->ptr.hp=t;
             p->tag=ATOM;
             t=p;
             p=q;
           }
       } // 完成对表头的标志
       q=p->ptr.tp; // q指向*p的表尾
       if(q&&q->mark==0)
       { // 继续遍历表尾
         p->ptr.tp=t;
         t=p;
         p=q;
       }
       else // BackTrack(finished)的细化
       {
         while(t&&t->tag==1) // LIST,表结点,从表尾回溯
         {
           q=t;
           t=q->ptr.tp;
           q->ptr.tp=p;
           p=q;
         }
         if(!t)
           finished=TRUE; // 结束
         else
         { // 从表头回溯
           q=t;
           t=q->ptr.hp;
           q->ptr.hp=p;
           p=q;
           p->tag=LIST;
         } // 继续遍历表尾
       }
     }
   }
 }

 static void Traverse_GL(GList L,void(*v)(GList))
 { // 利用递归算法遍历广义表L,由bo5-5.cpp改
   if(L) // L不空
     if(L->tag==ATOM) // L为单原子
       v(L);
     else // L为广义表
     {
       v(L);
       Traverse_GL(L->ptr.hp,v);
       Traverse_GL(L->ptr.tp,v);
     }
 }

 void visit(GList p)
 {
   if(p->tag==ATOM)
     printf("mark=%d %c\n",p->mark,p->atom);
   else
     printf("mark=%d list\n",p->mark);
 }

 void algo8_3_main()
 {
   char p[80];
   SString t;
   GList l;
   printf("请输入广义表l(书写形式：空表:(),单原子:a,其它:(a,(b),b)):\n");
   gets(p);
   StrAssign(t,p);
   CreateMarkGList(l,t);
   Traverse_GL(l,visit);
   MarkList(l);
   printf("加标志后:\n");
   Traverse_GL(l,visit);
 }
