#include<stdio.h>
#define MAX 100
int s[MAX][MAX]={0};  //��¼�����ʽ�λ��
double m[MAX][MAX]={0},g[MAX][MAX];  //m[][]��¼����Ȩֵ��g[][]��¼����Ȩֵ
int n;  //��¼ͼ�ж������
void f() {
	int d,i,j,k;
	for (d = 2; d <= n; d++) {
		for (i = 1; i <= n-d+1; i++) {
			j = i-d+1;
			m[i][j] = m[i+1][j] + g[i-1][i] + g[i][j] + g[i-1][j];
			s[i][j] = i;
			for (k = i+1; k < j; k++) {
				double temp = m[i][k] + m[k][j] + g[i-1][k] + g[k][j] + g[i-1][j];
				if (m[i][j] > temp) {
					m[i][j] = temp;
					s[i][j] = k;
				}
			}
			
		}
	}
} 
//�������·��
void print(int i, int j) {
	if (i == j) {
		return ;
	}
	if (s[i][j] > i) {
		printf("{v%dv%d}",i-1,s[i][j]);
	}
	if (j > s[i][j] + 1) {
		printf("{v%dv%d}",s[i][j],j);
	}
	print(i,s[i][j]);
	print(s[i][j]+1,j);
} 
int main() {
	int i, j;
	printf("�����붥�������\n");
	scanf("%d",&n);
	printf("���Դ��������Ӹ������Ȩֵ��\n");
	for (i = 0; i <= n; i++) {
		for (j = 0; j <=n; j++) {
			scanf("%lf",&g[i][j]);
		}
	}
	printf("���Ȩֵ������ֵ��\n");
	f();
	printf("%lf\n",m[1][n]);
	print(1,n);
	return 0;
} 
