#include<stdio.h>
int map[6][7] = {{16, 4, 3, 12, 6, 0, 3},{4, -5, 6, 7, 0, 0, 2},{6, 0, -1, -2, 3, 6, 8},{5, 3, 4, 0, 0, -2, 7},{-1, 7, 4, 0, 7, -5, 6},{0, -1, 3, 4, 12, 4, 2}};
int sumcost;
int best;

//判断x，y是否可以走通 
int check(int x, int y) {
	int flag = 1;
	if (x < 0 || x > 6 || y < 0 || y > 5) {
		flag = 0;
	}
	return flag;
}

void backtrack(int t, int f) {
	int fx[5] = {-1, -1, -1, -1, -1};
	int fy[5] = {-2, -1, 0, 1, 2};
	int i;
	int xx, yy;
	
	//分别向五个方向遍历
	for (i = 0; i < 5; i++) {
		//计算下一步走的坐标
		xx = t + fx[i];
		yy = f + fy[i];
		//判断是否可以走通
		if (check(xx, yy)) {
			//当前节点权值相加 
			sumcost += map[xx][yy];
			//到达终端节点 
			if (xx == 0) {
				//找到最优解
				if (sumcost > best) {
					best = sumcost;
				} 
			} else {
				backtrack(xx, yy);
			}
			sumcost = sumcost - map[xx][yy];
		} 
		
	} 
} 

int main () {
	sumcost = 0;
	best = 0;
	backtrack(6, 3);
	printf("最大路径和是%d", best);
	return 0;
} 
