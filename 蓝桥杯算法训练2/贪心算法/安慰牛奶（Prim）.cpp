#include<stdio.h>
#define MAX 100001
#define INF 888888
int flag[MAX];  //�������������ǽڵ�i�Ƿ���缯��U
int lowCost[MAX];  //��ʾ��i����������Ȩֵ��С�ıߵ�Ȩֵ
int closeSet[MAX];  //��ʾ��i������Ȩֵ��С�ıߵ�ǰ�� 
void Prim(int n, int u0, int map[MAX][MAX]) {
	int i, j, temp, t;
	//��u0���뼯��U��
	flag[u0] = 1;
	//��ʼ������ 
	for (i = 1; i <= n; i++) {
		if (i != u0) {
			lowCost[i] = map[u0][i];
			closeSet[i] = u0;
			flag[i] = 0;
		} else {
			lowCost[i] = 0;
		}
	}
	
	for (i = 1; i <= n; i++) {
		temp = INF;
		t = u0;
		//��V-U�������ҵ���U����������̵ĵ�
		for (j = 1; j <= n; j++) {
			if ( (!flag[j]) && (lowCost[j] < temp)) {
				t = j;
				temp = lowCost[j];
			}
		} 
		//��û�ҵ����Ƴ�
		if (t == u0) {
			break;
		} 
		//�������U��
		flag[t] = 1;
		//���¼���
		for (j = 1; j <= n; j++) {
			if ((!flag[j]) && (lowCost[j] > map[t][j])) {
				lowCost[j] = map[t][j];
				closeSet[j] = t;
			}
		} 
	}
}

int main () {
	int n, p; //��¼�������ͱ���
	int c[MAX];  //��¼ÿ�������Ȩֵ(��οʱ��)
	int map[MAX][MAX];  //��¼����i��j֮��Ļ���ʱ��
	int u, v, w;
	int minc = INF;

	int sum, temp, t;
	int i, j;
	//����ڵ�����ͱߵĸ��� 
	scanf("%d %d", &n, &p);
	//��ʼ����Ȩͼ�ľ��� 
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			map[i][j] = INF;
		}
	}
	//����ÿ���ڵ��Ȩֵ����οÿ����ţ��ʱ�䣩
	for (i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		if (minc > c[i]) {
			minc = c[i];
		}
	} 
	for (i  = 1; i <= p; i++) {
		scanf("%d %d %d", &u, &v, &w);
		map[u][v] = map[v][u] = 2 * w + c[u] + c[v];
	}
	
	Prim(n, 1, map);
	sum = minc;
	//������С�������ߵ�Ȩֵ֮�ͼ���С�ڵ��Ȩֵ��Ϊ��οţ��
	for (i = 1; i <= n; i++) {
		sum += lowCost[i];
	} 
	printf("%d", sum);
	return 0;
}
