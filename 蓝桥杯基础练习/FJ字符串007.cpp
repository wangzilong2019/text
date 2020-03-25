#include<stdio.h>
void print(int n) {
	//判断递归条件
	if (n == 1) {
		printf("A");
	} 
	else {
		print(n-1);
		printf("%c",'A'+n-1);
		print(n-1);
	}
}
int main () {
	int n;
	//输入n的个数
	scanf("%d",&n);
	//打印字符串 
	print(n); 
	return 0;
} 
