#include<stdio.h>
#define MAX 100
#define INF 8888
int n;  //��¼ʯ�Ӷ���
int a[MAX];  //��¼ÿ��ʯ������
int sum[MAX];  //��¼ǰi��ʯ��������
int Max[MAX][MAX],Min[MAX][MAX];  //��¼·���淨��i��j��ʯ��������С����
int min_circular,max_circular;  //��¼�ٳ��淨������С���� 
int max(int a,int b) {
	return a > b ? a : b;
}
int min(int a,int b) {
	return a < b ? a : b; 
}
//ֱ����ʯ�Ӻϲ� 
void straight(int a[],int n) {
	int d,k,i,j;
	//���ȴ�����ʯ��֪��n��
	for (d = 2; d <= n; d++) {
		for (i = 1; i <= n-d+1; i++) {
			j = i+d-1;
			Max[i][j] = -1;
			Min[i][j] = INF;
			//��¼��i�ѵ�j��֮���ʯ������ 
			int temp = sum[j] - sum[i-1];
			for (k = i; k < j; k++) {
				Max[i][j] = max(Max[i][j], Max[i][k] + Max[k+1][j] + temp);
				Min[i][j] = min(Min[i][j], Min[i][k] + Min[k+1][j] + temp);
			}
		}
	} 
}
//Բ��ʯ�Ӻϲ�
void circular(int a[],int n) {
	int i,j;
	//��ʯ�������б�����ֵ
	for (i = 1; i <= n-1; i++) {
		a[n+i] = a[i];
	} 
	//���㱶�����ʯ��������
	n = 2*n -1;
	straight(a,n);
	n = (n+1)/2;
	//�����1�ѵ�n��ʯ�������С����
	min_circular = Min[1][n];
	max_circular = Max[1][n];
	for (i = 2; i <= n; i++) {
		if (max_circular < Max[i][i+n-1]) {
			max_circular = Max[i][i+n-1];
		}
		if (min_circular > Min[i][i+n-1]) {
			min_circular = Min[i][i+n-1];
		}
	}
} 
int main() {
	int i;
	printf("������ʯ�Ӷ���n��\n");
	scanf("%d",&n);
	printf("������ÿ��ʯ�ӵ�������\n");
	for (i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
	}
	sum[0] = 0;
	//��ʼ��sum[i]
	for (i = 1; i <= n; i++) {
		sum[i] = sum[i-1] + a[i];
	}
	//��ʼ��Min[i][j],Min[i][j]
	for (i = 1; i <= n; i++) {
		Min[i][i] = 0;
		Max[i][i] = 0;
	}
	straight(a,n);
	printf("·���淨���õ�������Ϊ��%d\n",Max[1][n]);
	printf("·���淨���õ���С����Ϊ��%d\n",Min[1][n]);
	circular(a,n);
	printf("�ٳ��淨���õ�������Ϊ��%d\n",max_circular);
	printf("�ٳ��淨���õ���С����Ϊ��%d\n",min_circular); 
	return 0;
} 
