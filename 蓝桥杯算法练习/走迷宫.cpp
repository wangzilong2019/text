#include<stdio.h>
int fx[4] = {1, 0, -1, 0};
int fy[4] = {0, 1, 0, -1}; //�¡��ҡ��ϡ��� 
int map[8][8] = {{0,0,0,0,0,0,0,0}, {0,1,1,1,1,0,1,0},{0,0,0,0,1,0,1,0},{0,1,0,0,0,0,1,0},{0,1,0,1,1,0,1,0},{0,1,0,0,0,0,1,1},{0,1,0,0,1,0,0,0},{0,1,1,1,1,1,1,0}};
int total;
int best[8][8];
int bestp = 8888;
int check (int i, int j, int k) {
	int flag = 1;
	i = i+fx[k];
	j = j+fy[k];
	//�ж��Ƿ���ǽ��
	if (i < 0 || i > 7 || j < 0 || j > 7) {
		flag = 0;
	} else {
		if (map[i][j] != 0) {
			flag = 0;
		}
	}
	return flag;
}

//��ӡ���
void print () {
	int i, j;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			printf("%d ", best[i][j]);
		}
		printf("\n");
	}
}

//ͳ�Ʋ��� 
int countf() {
	int i, j;
	int count = 0;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (map[i][j] == 2) {
				count++;
			}
		}
	}
	return count;
} 

void backtrack (int i, int j) {
	int x, y, k;
	int count; 
	int a, b;
	//�ֱ����ĸ���������
	for (k = 0; k < 4; k++) {
		//�жϵ�ǰλ���Ƿ������
		if (check(i, j, k)) {
			x = i+fx[k];
			y = j+fy[k];
			map[x][y] = 2; //���ñ�־λ����ʾ�Ѿ��߹� 
			//�ж��Ƿ�ﵽβ��
			if (x == 7 && y == 7) {
				count = countf();
				if (count < bestp) {
					bestp = count;
					for (a = 0; a < 8; a++) {
						for (b = 0; b < 8; b++) {
							best[a][b] = map[a][b];
						}
					}
				}
			//	print();
			} else {
				backtrack(x, y);
			}
		}
	} 
	//�ĸ������߲�ͨ����Ϊ3 
	map[i][j] = 3;
}



int main () {
	int i, j;
	total = 0;
	printf("��ʼ���ؾ���Ϊ��\n");
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	} 
	//��ʼ�����
	map[0][0] = 2;
	//printf("��֮ͨ��ľ���\n");
	backtrack(0,0); 
	printf("��֮ͨ��ľ���\n");
	print();
	return 0;
}
