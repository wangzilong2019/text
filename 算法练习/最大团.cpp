#include<stdio.h>
#define MAX 100
int n;  //ͼ�еĶ�����
int m;  //ͼ���ж��������ӵı���
int x[MAX];  //��¼ÿ�ζ���
int bestx[MAX];  //��¼��������ֵ
int a[MAX][MAX] = {0};  //��¼ͼ�����������
int cn = 0;  //��¼��ǰ����ͼ�еĶ�������
int bestn;  //��¼���Ŷ�������
//�жϵ�t�������Ƿ���Լ���ͼ��
int place(int t) {
	int ok = 1;
	for (int i = 1; i < t; i++) {
		//�ж��Ƿ��б����� 
		if (x[i] && a[t][i] == 0) {
			ok = 0;
			break;
		}
	}
	return ok;
} 
//��չ�ڵ�
void backTrack(int t) {
	int i, j;
	//��ǰ�ڵ�ΪҶ�ӽڵ㣬���ҵ�һ������ֵ��¼
	if (t > n) {
		for (i = 1; i <= n; i++) {
			bestx[i] = x[i];
		}
		//��¼���������
		bestn = cn;
		return ; 
	} 
	//����������
	if (place(t)) {
		x[t] = 1;
		cn++;
		backTrack(t+1);
		cn--;
	} 
	//����������
	if (cn + n -t > bestn) {
		x[t] = 0;
		backTrack(t+1);
	} 
} 
int main() {
	int u, v, i;
	printf("�����벿�������n������������\n");
	scanf("%d",&n);
	printf("������������֮����Ѻù�ϵm����������\n");
	scanf("%d",&m);
	printf("���Դ������Ѻù�ϵ�������ˣ��б���������������u��v����\n");
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &u, &v);
		a[u][v] = a[v][u] = 1;
	} 
	backTrack(1);
	printf("�����е����������Ϊ��\n");
	printf("%d\n",bestn);
	printf("�����е�������˷ֱ�Ϊ��\n");
	for (i = 1; i <= n; i++) {
		if (bestx[i] == 1) {
			printf("%d ",i);
		}
	}
	return 0;
}  
