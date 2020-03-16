//①二分法求方程解：
//②求解区间连续而且单调f(a)*f(b) < 0 
//f(a)*f(b) < 0 
#include<stdio.h>
#include<math.h>
int main () {
	int a, b, c;
	float x1,x2,x,f1,f2,f;
	scanf("%f %f",&x1,&x2);
	f1 = x1*x1*x1/2 + 2*x1*x1 - 8;
	f2 = x2*x2*x2/2 + 2*x2*x2 - 8;
	if (f1*f2 > 0) {
		printf("无解！");
	}
	else {
		do {
			x = (x1+x2) / 2;
			f = x*x*x/2 + 2*x*x - 8;
			if (f == 0) {
				break;
			}
			if (f1*f > 0) {
				f2 = f;
				x2 = x;
			}
			else {
				f1 = f;
				x1 = x;
			}
		} while (fabs(f) >= 1e-4);
	}
	printf("%f",x);
	return 0;
}
