#include<stdio.h>
#define MAX 31
int main () {
	int c[MAX][MAX] = {0};
	int a[MAX][MAX], b[MAX][MAX], d[MAX][MAX];
	int i, j, k, m, n;
	//�������Ľ���������
	scanf("%d %d",&n ,&m);
	//��������Ԫ��
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d",&a[i][j]);
			b[i][j] = a[i][j]; 
			if (i == j) {
				d[i][j] = 1;
			}
			else {
				d[i][j] = 0;
			}
		}
	} 
	//���m��ֵΪ0
	if (m == 0) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				printf("%d ",d[i][j]);
			}
			printf("\n");
		} 
		return 0;
	}
	//���������˽��
	for (m = m-1; m > 0; m--) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				for (k = 0; k < n; k++) {
					c[i][j] += b[i][k] * a[k][j];
				}
			}
		}
		//������c��ÿ��Ԫ��ֵ��������b���ҽ�����ÿ��Ԫ�ظ�ֵ0 
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				b[i][j] = c[i][j];
				c[i][j] = 0;
			}
		}
	} 
	//������
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ",b[i][j]);
		}
		printf("\n");
	} 
	return 0;
} 
