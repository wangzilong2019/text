#include<stdio.h>
#include<string.h>
#define MAX 100
int r[MAX][MAX],m[MAX][MAX];  //��¼i��jվ�����
int s[MAX][MAX];  //��¼i��jվ֮���ͣ��վ̨
int n;  //����վ̨�� 
void rent() {
	int d,k,i,j;
	//���㾭������������n�����������·��
	 
	for (d = 3; d <=n; d++) {
		for (i = 1; i <= n-d+1; i++) {
			j = i+d-1;
			for (k = i+1; k < j; k++) {
				int temp = m[i][k] + m[k][j];
				if (temp < m[i][j]) {
					m[i][j] = temp;
					s[i][j] = k;
				}
			}
		}
	}
}
//��¼���·��
void print(int i, int j) {
	if (s[i][j] == 0) {
		printf("%d-",j);
		return ;
	}
	print(i, s[i][j]);
	print(s[i][j],j);
} 
int main() {
	int i,j;
	printf("��������ͧͣ����վ̨��n��\n");
	scanf("%d",&n);
	printf("�������վ̨֮��ķ��ã�\n");
	for (i = 1; i <= n; i++) {
		for (j = i+1; j <= n; j++) {
			scanf("%d", &r[i][j]);
			m[i][j] = r[i][j];
		}
	}
	//�������ŷ���
	rent();
	printf("���Ż��ѣ�\n");
	printf("%d\n",m[1][n]);
	printf("��������·����\n");
	printf("1-"); 
	print(1, n); 
	return 0;
}  
