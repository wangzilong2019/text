#include<stdio.h>
#define MAX 1000
int main() {
	int i, j;
	int a[MAX];
	int n;
	int countn = 0;
	//输入问题规模n
	scanf("%d",&n);
	//输入n个瓶子的排列顺序
	for (i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
	} 
	//判断每个数是否相等 
	for (i = 1; i <= n-1; i++) {
		//判断每一个瓶子序号与顺序是否相等 
		if (a[i] != i) {
			for (j = i; j <= n; j++) {
				if (i == a[j]) {
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
					countn++;
					break;
				} 
			}
		}
	}
	printf("%d",countn);
	return 0;
}
