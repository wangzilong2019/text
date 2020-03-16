//①枚举法暴力求解
//要收敛暴力，线索小范围
#include<stdio.h> 
int main () {
	for (int x = 1; x <= 20; x++) {
		for (int y = 1; y <= 33; y++) {
			if (5*x+3*y+(100-x-y)/3 == 100) {
				if ((100-x-y)%3 == 0) {
					printf("%d %d %d\n",x,y,100-x-y);
				}
			}
		}
	}
	return 0;
} 
