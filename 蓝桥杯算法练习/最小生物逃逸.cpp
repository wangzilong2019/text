#include<stdio.h>
#define MAX 101
int main () {
	int n, m;
	int i, j, count, f, sum;
	int a[MAX][4], b[MAX][3];  //����a��ÿ�д洢�����������Ͱ뾶������b�д洢�����������
	//������������������
	scanf("%d %d", &n, &m);
	//�ֱ�������������뾶����������
	for (i = 0; i < n+m; i++) {
		//���������������
		if (i < n) {
			for (j = 0; j < 4; j++) {
				scanf("%d", &a[i][j]);
			}
		} else {
			for (j = 0; j < 3; j++) {
				scanf("%d", &b[i-n][j]);
			}
		}
	} 
	//����
	for (i = 0; i < m; i++) {
		//���ݲ������� 
		count = 0;
		for (j = 0; j < n; j++) {
			sum  = 0;  //��������������ƽ��
			f = 2;
			do{
				sum += (a[j][f]-b[i][f])*(a[j][f]-b[i][f]);
			} while (f--);
			//�жϴ˾���Ͱ뾶��ֵ��ƽ��
			if (sum < a[j][3]*a[j][3]) {
				count++;
			} 
		}
		printf("%d ", count);
	} 
	return 0;
}
