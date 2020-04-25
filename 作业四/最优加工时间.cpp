#include<stdio.h>
#define INF 8888
struct node{
	int x, y; //每个零件在第一台机器和第二胎机器加工时间 
}T[7];

int bestf;
int f1, f2;
int x[7];

int max (int a, int b) {
	return a>b ? a:b;
}

void backtrack(int t) {
	int i, temp, tp;
	if (t > 6) {
		bestf = f2;
		return ;
	}
	for (i = t; i <= 6; i++) {
		f1 = f1 + T[x[i]].x;
		temp = f2;
		f2 = max(f1, f2) + T[x[i]].y;
		if (f2 < bestf) {
			tp = x[t];
			x[t] = x[i];
			x[i] = tp;
			backtrack(t+1);
			tp = x[t];
			x[t] = x[i];
			x[i] = tp;
		}
		f1 = f1 - T[x[i]].x;
		f2 = temp;
	}
}

int main () {
	int i;
	//输入每个机器在第一台和第二台加工时间
	for (i = 1; i <= 6; i++) {
		scanf("%d %d", &T[i].x, &T[i].y);
		x[i] = i;
	} 
	bestf = INF;
	f1 = f2 = 0;
	backtrack(1);
	printf("最少%d天", bestf);
	return 0;
}
