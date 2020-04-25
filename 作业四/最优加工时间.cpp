#include<stdio.h>
#define INF 8888
struct node{
	int x, y; //ÿ������ڵ�һ̨�����͵ڶ�̥�����ӹ�ʱ�� 
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
	//����ÿ�������ڵ�һ̨�͵ڶ�̨�ӹ�ʱ��
	for (i = 1; i <= 6; i++) {
		scanf("%d %d", &T[i].x, &T[i].y);
		x[i] = i;
	} 
	bestf = INF;
	f1 = f2 = 0;
	backtrack(1);
	printf("����%d��", bestf);
	return 0;
}
