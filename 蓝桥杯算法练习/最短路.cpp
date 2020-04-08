#include<stdio.h>
#define MAX 20001
#define INF 88888
int map[MAX][MAX] = {INF};
int d[MAX];
int p[MAX];
int flag[MAX];
int n;
void dijistra(int u) {
	//��ʼ�������Լ�����
	int i, j;
	int temp, t;
	for (i = i; i <= n; i++) {
		d[i] = map[u][i];
		flag[i] = 0;
		if (d[i] == INF) {
			p[i] = -1;
		}
		else {
			p[i] = u;
		}
	} 
	//����һ���ڵ�������� 
	flag[u] = 1;
	d[u] = 0;
	//�����ҵ����·��
	for (i = 1; i <= n; i++) {
		temp = INF;
		t = u;
		//�ҵ����·����������
		for (j = 1; j <= n; j++) {
			if (!flag[j] && d[j] < temp) {
				t = j;
				temp = d[j];
			}
		} 
		//�Ҳ���t�˳� 
		if (u == t) {
			return ;
		} 
		//�ҵ���t�ڵ����
		flag[t] = 1;
		//���½⼯��v-s����t�ڽӵ㵽Դ��u�ľ���
		for (j = 1; j <= n; j++) {
			if (!flag[j] && map[t][j] < INF) {
				if (d[j] > d[t]+map[t][j]) {
					d[j] = d[t]+map[t][j];
					p[j] = t;
				}
			}
		} 
	} 
	
}
int main () {
	int m;
	int i, j;
	int u, v, w;
	//����ͼ�еĶ�����
	scanf("%d", &n);
	//����ͼ�еı���
	scanf("%d", &m);
	//����ͼ�еĶ����Լ���Ӧ��Ȩֵ
	while (m--) {
		scanf("%d %d %d",&u, &v, &w);
		map[u][v] = w;
	} 
	dijistra(0);
	for (i = 2; i <= n; i++) {
		printf("%d\n",d[i]);
	}
	return 0;
}
