#include "stdio.h"
int	map[8][8]={{0, 0, 0, 1, 0, 0, 0, 0},{0, 1, 1, 1, 1, 1, 1, 1},{0, 0, 0, 1, 0, 0, 0, 1},{0, 1, 0, 1, 0, 1, 0, 1},{0, 1, 0, 0, 0, 1, 0, 1},{0, 1, 1, 1, 1, 1, 0, 1},{0, 1, 0, 0, 0, 1, 0, 0},{0, 1, 0, 0, 0, 0, 1, 0}};
int dep;
int count;
void search(int i,int j);  //·��Ѱ�ң�Ҫ��ʹ�õݹ�

//�ж�·�Ƿ������
int check(int x, int y) {
	int i, j;
	int flag = 1;
	//��������߲�ͨ
	if (x < 0 || x > 7 || y < 0 || y > 7) {
		flag = 0;
	} else {
		//��·����·�Ѿ����߹�
		if (map[x][y] != 0) {
			flag = 0;
		} 
	}
	return flag;
} 

//��ӡ���н�
void print() {
	int i, j;
	for (i = 0; i < 8; i++) {
		printf("\n");
		for (j = 0; j < 8; j++) {
			printf("  %d", map[i][j]);
		}
	} 
} 


int main() {

	count = 0;  //��¼���н� 
	dep = 2;
	map[0][0] = 1;
	search(0, 0);
	printf("\n����%d�ַ���", count);
	return 0;
}

void search(int i, int j) { 
	//�����ҡ��¡������ĸ����� 
	int fx[4] = {0, 1, 0, -1};
	int fy[4] = {1, 0, -1, 0};
	int k, xx, yy;
	//�ֱ�����ĸ�����
	for (k = 0; k < 4; k++) {
		//��ǰһ��Ҫ�ߵ�����
		xx = i + fx[k];
		yy = j + fy[k];
		//����·������
		if (check(xx, yy)) {
			map[xx][yy] = dep++;  //����s����2
			//�����յ����
			if (xx == 7 && yy == 7) {
				count++;
				print();
			} else {
				search(xx, yy);
			}

		} 
	} 
	map[i][j] = 0; //����
    dep--;
	 
}
