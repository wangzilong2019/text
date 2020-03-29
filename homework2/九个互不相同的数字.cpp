/************begin************/
#include<stdio.h>
//判断九位数字是否为每个数字都不相同·
int check(int a[], int n) {
	//设置标志位
	int flag = 1;
	int i = 4;
	int j;
	while (n) {
		a[i++] = n%10;
		n /= 10;
	}
	for (i = 0; i < 9; i++) {
		for (j = i+1; j < 9; j++) {
			if (a[i] == a[j]) {
				flag = 0;
				break;
			}
		}
	}
	return flag;
} 
int main () {
	int i, j, k, m, n;
	int a[9];
	//进行计算
	for (i = 5; i <= 9; i++) {
		for(j = 0; j <= 9; j++) {
			//每位不同
			if (i != j) {
				for (k = 0; k <= 9; k++) {
					//每位不同
					if (k != i && k != j) {
						for (m = 0; m <= 9; m++) {
							//每位不同
							if (m != i && m != j && m != k) {
								n = i*1000 + j*100 + k*10 + m;
								a[0] = i;
								a[1] = j;
								a[2] = k;
								a[3] = m; 
								//判断结果是否为九位不相同的数字 
								if (check(a,2*n)) {
									printf("2*%d=%d\n",n, 2*n); 
								}
							} 
						}
					} 
				}
			} 
		}
	} 
	return 0;
}




























/************end************/
