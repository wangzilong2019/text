#include<stdio.h>

//�ݹ鷨ת��Ϊ�˽���
void f(int n) {
	if (n < 8) {
		printf("%d",n);
	}
	else {
		f(n/8);
		printf("%d",n%8);
	}
} 

int main () {
	int n;
	scanf("%d",&n);
	f(n);
	return 0;
}
