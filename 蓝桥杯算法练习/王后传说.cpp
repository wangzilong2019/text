#include<stdio.h>
#include<math.h>
#define MAX 14
int n, x, y;
int count = 0; //ͳ�ƿ��ŷ�����
int a[MAX][MAX] = {0};
int xf[MAX];

int check2(int xx, int yy) {
	int i;
	int flag = 1;
	int fx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
	int fy[9] = {0, 1, 1, 0, -1, -1, -1, 0, 1};
	for (i = 0; i < 9; i++) {
		if (xx == x+fx[i] && yy == y+fy[i]) {
			flag = 0;
			break;
		}
	}
	return flag;
}


int check(int x1, int y1) {
	//�ж�t�Ƿ���Դ�ţ����Ƿ��� 
	int flag = 1;
	int i;
	if (!check2(x1, y1)) {
		flag = 0;
	} else {
		for (i = 1; i < x1; i++) {
			if (xf[i] == xf[x1] || x1-i == fabs(xf[x1]-xf[i])) {
				flag = 0;
				break;
			}
		}
	}
	return flag;
}

void backtrack (int t) {
	int i;
	//������Ҷ�ӽڵ�ʱ������м�¼��1
	if (t > n) {
		count++;
	} else {
		for (i = 1; i <= n; i++) {
			xf[t] = i;
			if (check(t, xf[t])) {
				backtrack(t + 1);
			}
		}
	}
} 
 
int main () {
	count = 0;
	//�����������Լ���������
	scanf("%d %d %d", &n, &x,&y);
	backtrack(1);
	printf("%d", count);
	return 0;
}
