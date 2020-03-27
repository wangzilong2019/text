#include<stdio.h>

//编写函数从键盘中读取数字 
void GetTwoInts(int *n, int *m) {
	scanf("%d %d",n,m);
} 

int main () {
	int a, b;
	int *p, *q;
	p = &a;
	q = &b;
	//调用函数从键盘中读取数字 
	GetTwoInts(p,q);
	printf("%d\n", a+b);
	return 0;
} 
