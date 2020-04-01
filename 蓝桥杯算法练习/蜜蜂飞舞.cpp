#include<stdio.h>
#include<math.h>
#define MAX 1000 
int main () {
	int a[MAX], b[MAX], c[MAX], d[MAX], e[MAX], f[MAX], t[MAX];
	int x1, x2, y1, y2, z1, z2;
	int i, n;
	double len;
	//输入n
	scanf("%d",&n);
	for (i = 0; i < n; i++) {
		scanf("%d %d %d %d %d %d %d",&a[i], &b[i], &c[i], &d[i], &e[i], &f[i], &t[i]);
	}
	//读入初始坐标
	scanf("%d %d %d %d %d %d",&x1, &y1, &z1, &x2, &y2, &z2);
	//计算最终坐标
	for (i = 0; i < n; i++) {
		x1 = x1+a[i]*t[i];
		y1 = y1+b[i]*t[i];
		z1 = z1+c[i]*t[i];
		x2 = x2+d[i]*t[i];
		y2 = y2+e[i]*t[i];
		z2 = z2+f[i]*t[i];
	} 
	len = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
	printf("%.4lf", len);
	return 0;
}
