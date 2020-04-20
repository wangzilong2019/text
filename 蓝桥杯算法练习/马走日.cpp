#include<stdio.h>
#define MAX 101
int dp[MAX][MAX] = {0};
int fx[8] = {2, 1, -1, -2, -2, -1, 1, 2}; //��¼����
int fy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int n, m;//���ӵ����������� 
//�ж��Ƿ���磬�Ƿ��������
int check(int x, int y) {
	int flag = 1;
	//�ж��Ƿ����
	if (x < 0 || y < 0 || x > n-1 || y > m - 1) {
		flag = 0;
	} else {
		//������ʱ�жϴ�·���Ƿ������
		if (dp[x][y] != 0) {
			flag = 0;
		} 
	}
	return flag;
} 

//��ӡ·��
void print() {
	int i, j;
	printf("\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
} 

//�����㷨
void backtrack (int x, int y, int dep) {
	int i;
	int xx, yy;//��¼��֮��ķ������� 
	//�ֱ���˸�������
	for (i = 0; i < 8; i++) {
		xx = x + fx[i];
		yy = y + fy[i];
		//���˷���δ�߹�(�Ƿ���磬�Ƿ��������)
		if (check(xx, yy)) {
			dp[xx][yy] = dep;
			//�ж��Ƿ񵽴��յ�
			if (dep == n*m) {
				print();
			} else {
				backtrack(xx, yy, dep + 1);
			}
			dp[xx][yy] = 0;//���� 
		} 
	} 
} 
 
int main () {
	//������������������
	scanf("%d %d", &n, &m); 
	dp[0][0] = 1;
	backtrack(0, 0, 2);
	return 0;
}
