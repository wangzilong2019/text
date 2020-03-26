#include<stdio.h>
int main () {
	int v1, v2, t, s, l;
	int l1, l2, i;
	//输入数据
	scanf("%d %d %d %d %d",&v1, &v2, &t, &s, &l);
	//初始化兔子和乌龟的跑步距离
	l1 = 0;
	l2 = 0;
	i = 0;
	while (l1 < l && l2 < l) {
		//兔子和乌龟跑步
		l1 += v1;
		l2 += v2;
		i++; 
		if (l1 >= l || l2 >= l){
			break;
		} 
		//领先时兔子睡觉
		if (l1-l2 >= t) {
			l1 = l1 - v1*s;
		} 
	} 
	//判断谁先到达终点
	if (l1 > l2) {
		printf("R\n");
	} 
	else {
		if (l1 == l2) {
			printf("D\n");
		}
		else {
			printf("T\n");
		}
	}
	printf("%d\n",i);
	return 0;
} 
