#include<stdio.h>
#include<stdlib.h>
//��Χ��Ȩֵ֮��
int sum (int w[], int x, int y) {
	int i;
	int res = 0;
	for (i = x; i <= y; i++) {
		res += w[i];
	}
	return res;
} 

//��Χ�ڸ��ӵ����Ȩֵ
int max(int w[], int x, int y) {
	int maxv = w[x];
	int i;
	for (i = x+1; i <= y; i++) {
		if (maxv < w[i]) {
			maxv = w[i];
		}
	}
	return maxv;
} 
int main () {
	int n, m;
	int i, j, k;
	int *w, *p, *x, *y, *v;
	//����n��m
	scanf("%d %d", &n, &m);
	//������̬���� 
	w = (int *)malloc(sizeof(int)*n);
	p = (int *)malloc(sizeof(int)*m);
	x = (int *)malloc(sizeof(int)*m);
	y = (int *)malloc(sizeof(int)*m);
	v = (int *)malloc(sizeof(int)*m);
	//����ÿ�����ӵ�Ȩֵ
	for (i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	} 
	//�����������
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &p[i], &x[i], &y[i]);
	} 
	//������
	k = 0;
	for (i = 0; i < m; i++) {
		//�жϲ�������
		if (p[i] == 1) {
			w[x[i]-1] = y[i];
		} 
		if (p[i] == 2) {
			v[k++] = sum(w, x[i]-1, y[i]-1);
		}
		if (p[i] == 3) {
			v[k++] = max(w, x[i]-1, y[i]-1);
		}
	}  
	//������
	for (i = 0; i < k; i++) {
		printf("%d\n", v[i]);
	} 
	return 0;
} 
