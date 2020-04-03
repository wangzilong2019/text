#include<stdio.h>
#include<stdlib.h>
#define MAX 10001
int maxv(int *p, int n) {
	int temp,i;
	temp = p[0];
	for (i = 1; i < n; i++) {
		if (temp < p[i]) {
			temp = p[i];
		}
	}
	return temp;
}
int main () {
	int n, m;
	int num, max, i, j;
	int *p;
	int second, min, flag;
	//输入水龙头个数和接水人数
	scanf("%d %d",&n, &m);
	//动态申请数组
	p = (int *)malloc(sizeof(int)*n);
	//判断数组是否申请成功
	if(p == NULL) {
		printf("error");
		return 0;
	} 
	//输入每个人的接水量
	for (i = 0; i < n; i++) {
		scanf("%d",&p[i]);
	} 
	//判断人数和水龙头的关系
	if (n <= m) {
		printf("%d", maxv(p,n));
	} 
	if (n > m) {
		second = 0;
		num = 0;
		while (n > m) {
			//找到当前数组最小值
			min = p[0];
			flag = 0;
			for (i = 0; i < m; i++) {
				if (min > p[i]) {
					min = p[i];
					flag = i;
				}
			} 
			for (i = 0; i < m; i++) {
				p[i] = p[i]-min;
			}
			second += min;
			p[flag] = p[m+num];
			num++;
			n--;
			if (n <= m) {
				printf("%d",maxv(p,n)+second);
			}	 
		}
	}
	
	return 0;
}
