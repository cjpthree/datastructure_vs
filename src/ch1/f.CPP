 // f.cpp 变量的引用类型和非引用类型的区别
 #include<stdio.h>
 static void fa(int a) // 在函数中改变a，将不会带回主调函数(主调函数中的a仍是原值)
 {
   a=5;
   printf("在函数fa中：a=%d\n",a);
 }

 static void fb(int &a) // 由于a为引用类型，在函数中改变a，其值将带回主调函数
 {
   a=5;
   printf("在函数fb中：a=%d\n",a);
 }

 void f_main()
 {
   int n=1;
   printf("在主程中，调用函数fa之前：n=%d\n",n);
   fa(n);
   printf("在主程中，调用函数fa之后,调用函数fb之前：n=%d\n",n);
   fb(n);
   printf("在主程中，调用函数fb之后：n=%d\n",n);
 }
