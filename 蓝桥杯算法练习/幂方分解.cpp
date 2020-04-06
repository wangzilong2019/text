#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 1001

//n进制转换成十进制
int trans(int n, char m[]) {
	int len = strlen(m);
	int i, k;
	int sum = 0;
	k = 0;
	for (i = len-1; i >= 0; i--) {
		sum = sum + (m[i]-'0')*pow(n,k);
		k++;
	}
	return sum;
} 

int main () {
	int n;
	char m[MAX];
	//输入进制和数字
	scanf("%d",&n);
	gets(m);
	//将此数字转换成十进制数字 
	printf("%d",trans(n, m));
	return 0;
}
