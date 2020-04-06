#include<stdio.h>
#define MAX 1001
//创建结构体
typedef struct {
	int beg;
	int end;
	int flag;
}road; 

int main () {
	int l, m, sum;
	int i, j;
	road a[MAX];
	//输入公路距离
	scanf("%d",&l);
	//输入区间数
	scanf("%d",&m);
	//输入每个区间起始和终点
	for (i = 0; i < m; i++) {
		scanf("%d %d", &(a[i].beg), &(a[i].end));
		a[i].flag = 1;
		//判断每个区间是否有重叠
		for (j = 0; j < i; j++) {
			if (a[i].end >= a[j].beg && a[i].beg <= a[j].end && a[j].flag) {
				a[j].flag = 0;
				if (a[i].beg > a[j].beg) {
					a[i].beg = a[j].beg;
				}
				if (a[i].end < a[j].end) {
					a[i].end = a[j].end;
				}
			}
		} 
	}
	//输入区间
	sum = l+1;
	for (i = 0; i < m; i++) {
		if (a[i].flag) {
			sum = sum-(a[i].end-a[i].beg+1);
		}
	} 
	printf("%d",sum);
}
