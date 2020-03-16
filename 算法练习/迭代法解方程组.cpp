//①牛顿迭代法求方程解 
//②有解条件：迭代且收敛 
//x(n+1) = x(n) - f(x(n))/(f‘x(n))；
 

#include<stdio.h>
#include<math.h> 
int main () {
	int f1, f;
	float x1, x0;
	int a, b, c, d;
	x1 = 1;
	printf("请输入系数a，b，c，d：\n"); 
	scanf("%d %d %d %d",&a, &b, &c, &d);
	do {
		x0 = x1;
		f = ((a*x0+b)*x0+c)*x0+d;
		f1 = (3*a*x0+2*b)*x0+c;
		x1 = x0 - f/f1;
	} while (fabs(x1-x0) >= 1e-4);
	printf("%f",x1);
	return 0;
} 
