#include<stdio.h>
#define MAX 100
int w[MAX];  //��¼ÿ����Ʒ������
int v[MAX];  //��¼ÿ����Ʒ�ļ�ֵ
int n;  //������Ʒ������
int W;  //���ﳵ��������
int c[MAX][MAX];  //c[i][j]ǰj����Ʒ������j�Ĺ��ﳵ������ֵ
int x[MAX];  //��¼��i����Ʒ�Ƿ���빺�ﳵ�� 
int max(int a,int b) {
	return a > b ? a : b;
} 
int main() {
	int i, j;
	printf("�����빺�ﳵ������w��\n");
	scanf("%d",&W);
	printf("��������Ʒ�ĸ���n��\n");
	scanf("%d",&n);
	printf("������ÿ����Ʒ������w�ͼ�ֵv��\n");
	for (i = 1; i <= n; i++) {
		scanf("%d %d",&w[i],&v[i]);
	}
	//��ʼ��c[i][j]
	for (i = 0; i <= n; i++) {
		c[i][0] = 0;
	} 
	for (j = 0; j <= W; j++) {
		c[0][j] = 0;
	} 
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= W; j++) {
			//��ǰ��Ʒ�������ڹ��ﳵ���������� 
			if (w[i] > j) {
				c[i][j] = c[i-1][j];
			}
			//������ȽϷŴ���Ʒ���ǲ��Ŵ���Ʒ��ֵ�� 
			else {
				c[i][j] = max(c[i-1][j], c[i-1][j-w[i]] + v[i]);
			}
		}
	}
	printf("���빺�ﳵ�е���Ʒ������ֵΪ��%d\n",c[n][W]);
	//���������Ž�
	j = W;
	for (i = n; i >= 1; i--) {
		//�жϵ�i����Ʒ�Ƿ�װ�빺�ﳵ�� 
		if (c[i][j] > c[i-1][j]) {
			j -= w[i];
			x[i] = 1;
		}
		else {
			x[i] = 0;
		}
	} 
	//������Ž�
	for (i = 1; i <= n; i++) {
		if (x[i] == 1) {
			printf("װ�빺�ﳵ����ƷΪ��%d\n",i);
		}
	} 
	return 0;
} 
