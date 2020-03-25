#include<stdio.h>
int main () {
	int i, j, n;
	int a, b;
	//输入数据区间
	scanf("%d %d",&a, &b);
	for (i = a; i <= b; i++) {
		printf("%d=",i); 
		n = i;
		j = 2;
		while(n != j) {
			//寻找满足条件的质数 
			for (j = 2; j < n; j++) {
				if (n%j == 0 && n != j) {
					printf("%d*",j);
					n /= j;
					break;
				}
			}
		}
		printf("%d\n",n);
	} 
	return 0;
}
