#include<stdio.h>

//��д�����Ӽ����ж�ȡ���� 
void GetTwoInts(int *n, int *m) {
	scanf("%d %d",n,m);
} 

int main () {
	int a, b;
	int *p, *q;
	p = &a;
	q = &b;
	//���ú����Ӽ����ж�ȡ���� 
	GetTwoInts(p,q);
	printf("%d\n", a+b);
	return 0;
} 
