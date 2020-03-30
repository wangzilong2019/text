#include<stdio.h>
#include<stdlib.h>
#define MAX 100

//数字转制
int reverse(int n) {
	int i = 0;
	char a[MAX];
	//先将数字逆序存放在字符串中
	while (n) {
		a[i++] = n%10+'0';
		n /= 10;
	} 
	//做字符串结束符
	a[i] = '\0';
	n = atoi(a);
	return n; 
} 

//将数字转制且求和
int reverse_sum (int a, int b) {
	int sum;
	a = reverse(a);
	b = reverse(b);
	sum = a+b;
	return sum;
} 

int main () {
	int a, b, sum;
	//输入俩个数字
	scanf("%d %d",&a, &b);
	//数字转制 
	sum = reverse_sum(a, b);
	sum = reverse(sum);
	printf("%d\n",sum);
	return 0;
}
