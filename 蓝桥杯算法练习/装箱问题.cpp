#include<stdio.h>
//�������������ֵ
int max(int a, int b) {
	return a>b ? a:b;
} 

int main () {
	int V, n;
	int maxv[31][20001] = {0};  //��ʾǰi����Ʒװ���������Ϊj�����õ�����ֵ 
	int i, j, t;
	//���������������װ��������Ʒ����
	scanf("%d %d", &V, &n);

	for (i = 1; i <= n; i++) {
		//����ÿ�����ӵ����
		scanf("%d", &t);
		//�ж��Ƿ���װ������
		for (j = 1; j <= V; j++) {
			//����װ������
			if (t > j) {
				maxv[i][j] = maxv[i-1][j];
			} 
			//װ��Ʒ�ж��Ǹ��������
			else {
				maxv[i][j] = max(maxv[i-1][j], maxv[i-1][j-t]+t);
			} 
		} 
	}
	//�����Сʣ�����
	printf("%d",V-maxv[n][V]); 
	return 0;
}
