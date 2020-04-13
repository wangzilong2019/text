#include<stdio.h>
int fx[4] = {1, 0, -1, 0};
int fy[4] = {0, 1, 0, -1}; //下、右、上、左 
int map[8][8] = {{0,0,0,0,0,0,0,0}, {0,1,1,1,1,0,1,0},{0,0,0,0,1,0,1,0},{0,1,0,0,0,0,1,0},{0,1,0,1,1,0,1,0},{0,1,0,0,0,0,1,1},{0,1,0,0,1,0,0,0},{0,1,1,1,1,1,1,0}};
int total;
int best[8][8];
int bestp = 8888;
int check (int i, int j, int k) {
	int flag = 1;
	i = i+fx[k];
	j = j+fy[k];
	//判断是否在墙内
	if (i < 0 || i > 7 || j < 0 || j > 7) {
		flag = 0;
	} else {
		if (map[i][j] != 0) {
			flag = 0;
		}
	}
	return flag;
}

//打印结果
void print () {
	int i, j;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			printf("%d ", best[i][j]);
		}
		printf("\n");
	}
}

//统计步数 
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
	//分别向四个方法遍历
	for (k = 0; k < 4; k++) {
		//判断当前位置是否可以行
		if (check(i, j, k)) {
			x = i+fx[k];
			y = j+fy[k];
			map[x][y] = 2; //设置标志位，表示已经走过 
			//判断是否达到尾处
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
	//四个方向都走不通则置为3 
	map[i][j] = 3;
}



int main () {
	int i, j;
	total = 0;
	printf("初始化地矩阵为：\n");
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	} 
	//初始化起点
	map[0][0] = 2;
	//printf("走通之后的矩阵\n");
	backtrack(0,0); 
	printf("走通之后的矩阵\n");
	print();
	return 0;
}
