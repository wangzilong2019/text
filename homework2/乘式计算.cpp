#include<stdio.h>
int main () {
	int i, j, k, m, c, e, f;
	int a[4] = {2, 3, 5, 7};
	//循环求此算式
	printf("题目中的乘式为：\n");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				for (m = 0; m < 4; m++) {
					c = a[i]*100 + a[j]*10 + a[k];
					e = a[m];
					f = a[m]*10;
					if (c*e == 2325) {
						printf("%d%d%d\n",a[i], a[j], a[k]);
						printf("x%d%d\n",a[m], a[m]);
						printf("-----\n");
						printf(" %d\n",c*e);
						printf("%d\n",c*e);
						printf("-----\n");
						printf("%d",c*e*10+c*e);
						
					} 
					
				}
			}
		}
	} 
	return 0;
}
