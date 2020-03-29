/************begin************/

#include<stdio.h>
#include<stdlib.h>
int ctn = 0;
int count(int i) //位数计算函数
{
	//判断循环退出条件
	if (i/10 == 0) {
		return ctn+1;
	} 
	ctn++;
	//递归
	return count(i/10); 
}
void nxdisp(int i) //逆序输出函数
{
	//递归退出条件 
	if (i/10 == 0) {
		printf("%d",i%10);
		return;
	}
	printf("%d",i%10);
	nxdisp(i/10);
}
void sxdisp(int i)//顺序输出函数
{
	if (i/10 != 0) {
		sxdisp(i/10);
	}
	printf("%d",i%10);
}

int main()
{
     int n;//存放输入的正整数
     //输入正整数
     printf("请输入一个正整数\n");
	 scanf("%d",&n);
	 printf("%d是%d位数\n",n, count(n));
	 printf("逆序打印\n");
	 nxdisp(n);
	 printf("\n");
	 printf("顺序打印\n");
	 sxdisp(n);
}
/************end************/
