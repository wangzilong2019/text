#include<stdio.h>
#define MAX 100
int main() {
	int i, j, k, m;
	//i为甲可能的名词 
	for (i = 1; i <= 4; i++) {
		//j为乙可能的名次 
		for (j = 1; j <= 4; j++) {
			if (i != j) {
				//k为丙可能的名词 
				for (k = 1; k <= 4; k++) {
					//m为丁可能的名词
					m = 10 - i - j - k;
					//判断每个人的名次都不同 
					if ((m != i) && (m != j) && (m != k)) {
						//判断条件
						if (((i == 1) + (j == 3) == 1) && ((k == 1) + (m == 4) == 1) && ((m == 2) + (i == 3) == 1)) {
							printf("%d %d %d %d\n",i,j,k,m);
						} 
					}
						
				}
			} 
		}
	}
	return 0;
} 
