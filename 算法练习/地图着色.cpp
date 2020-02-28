#include<stdio.h>
#define MAX 100
int n;  //��¼��ͼ�еĶ�����
int edge;  //��¼��ͼ�еı���
int m;  //��¼�ɻ��Ƶ���ɫ���� 
int map[MAX][MAX] = {0};  //����ͼ���ڽӾ���
int x[MAX];  //��¼�ɻ��Ƶ���ɫ
int sum = 0; //��¼���з������� 
//��ʼ����ͼ���ڽӾ���
void creatMap() {
	int i, j;
	int u, v;
	for (i = 1; i <= edge; i++) {
		scanf("%d %d",&u,&v);
		map[u][v] = map[v][u] = 1;
	}
} 
//�жϵ�ǰ�����Ƿ������չ
int place(int t) {
	int i, j;
	int ok = 1;
	//�жϵ�ǰ�����Ƿ����Ѿ���ɫ�����ұ��������Ƿ���ɫ��ͬ 
	for (i = 1; i < t; i++) {
		if (map[t][i] == 1) {
			if (x[t] == x[i]) {
				ok = 0;
				break;
			}
		}
	}
	return ok;
} 
//��������
void backTrack(int t) {
	int i, j;
	//��ǰ�ڵ�ΪҶ�ӽڵ㣬�ҵ�һ�ֿ��з��������
	if (t > n) {
		sum++;
		printf("��%d�ַ�����ɫΪ��\n",sum);
		for (i = 1; i <= n; i++) {
			printf("%d ",x[i]);
		}
		printf("\n");
	} 
	else {
		//ÿ��������Ʋ�ͬ��ɫ
		for (i = 1; i <= m; i++) {
			x[t] = i;
			//�������������� 
			if (place(t)) {
				backTrack(t+1);
			}
		} 
	}
} 
int main() {
	int i, j;
	printf("�������ͼ�еĶ�����n��\n");
	scanf("%d",&n);
	printf("������ͼ�еıߵ�����edge��\n");
	scanf("%d",&edge);
	printf("������ɻ��Ƶ���ɫ����m��\n");
	scanf("%d",&m);
	printf("������ͼ�������ߵĶ���u��v��\n");
	creatMap();
	backTrack(1); 
	return 0;
} 
