#include<stdio.h>
#include<stdlib.h>
#define MAX 6
int dep;  //��¼������
int count;  //��¼���н��� 
int map[MAX][MAX] = {0};


//�жϵ�x�� y�Ƿ�ɴ�
int check(int x, int y) {
	int i;
	int flag = 1;
	if (x < 1 || x > 5 || y < 1 || y > 5 || map[x][y] != 0) {
		flag = 0;
	}
	return flag;
} 

//��ӡ���
void print() {
	int i, j;
	for (i = 1; i <= 5; i++) {
		for (j = 1; j <= 5; j++) {
			printf(" %d", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
} 

void search(int x, int y) {
	int xx;
	int yy;
	int i;
	int fx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	int fy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
	//�ֱ𳯰˸�������
	for (i = 0; i < 8; i++) {
		xx = x + fx[i];
		yy = y + fy[i];
		//�жϴ˵��Ƿ������ͨ
		if (check(xx, yy)) {
			dep++;
			map[xx][yy] = dep;
			//�ж��Ƿ񵽴��յ�
			if (dep == 25) {
				count++;
				//��ӡ·��
				print();
			} else {
				search(xx, yy);
			}
			map[xx][yy] = 0;
			dep--;
		} 
	} 
	//����
 
}

int main () {
	count = 0;
	dep = 1;
	map[1][1] = 1;
	search(1, 1);
	printf("·������%d", count);
	return 0;
} 
