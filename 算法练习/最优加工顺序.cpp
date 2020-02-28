#include<stdio.h>
#define MAX 100
//����ÿ������ӹ�ʱ��ṹ�� 
struct node {
	int x;  //�ڵ�һ�������ϵļӹ�ʱ�� 
	int y;  //�ڵڶ��������ϵļӹ�ʱ�� 
}a[MAX];
int f1 = 0;  //����ڵ�һ�������ӹ�����ʱ��
int f2 = 0;  // ����ڵڶ��������ӹ�����ʱ��
int n;  //���ӹ������
int x[MAX];  //�����������
int bestx[MAX];  //������������ 
int bestf = 8888;  //��������ֵ 
//�����ֵ
int max(int a, int b) {
	return a > b ? a : b;
} 

//��������
void backTrack(int t) {
	int i, j;
	//��ǰ�ڵ�ΪҶ�ӽڵ�
	if (t > n) {
		for (i = 1; i <= n; i++) {
			bestx[i] = x[i]; 
		}
		bestf = f2;
		return ;
	} 
	else {
		for (i = t; i<= n; i++) {
			f1 += a[x[i]].x;
			int temp = f2;
			f2 = max(f1, f2) + a[x[i]].y;
			//�޽�����
			if (f2 < bestf) {
				int tp = x[i];
				x[i] = x[t];
				x[t] = tp;
				backTrack(t+1);
				tp = x[i];
				x[i] = x[t];
				x[t] = tp;
			} 
			f1 -= a[x[i]].x;
			f2 = temp;
		}
	}
} 
int main() {
	int i, j;
	printf("������ӹ��������n��\n");
	scanf("%d",&n);
	printf("������ÿ������ڵ�һ�������͵ڶ��������ϵļӹ�ʱ�䣺\n");
	for (i = 1; i <=n; i++) {
		scanf("%d %d",&a[i].x, &a[i].y);
		x[i] = i;
	}
	backTrack(1);
	printf("��������żӹ�ʱ��bestf��\n");
	printf("%d\n",bestf);
	printf("��������мӹ�˳��\n");
	for (i = 1; i <= n; i++) {
		printf("%d ",bestx[i]);
	}
	return 0;
} 
