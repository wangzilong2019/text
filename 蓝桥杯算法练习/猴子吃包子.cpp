#include<stdio.h>
int main () {
	int x, y, z, x1, y1, z1, p;
	int r, s, t;
	//输入数据
	scanf("%d %d %d %d %d %d %d", &x, &y, &z, &x1, &y1, &z1, &p);
	//首先输出整数位
	r = (x1*y*z + y1*x*z + z1*x*y) / (x*y*z);
	printf("%d.", r);
	//记录尾数
	s = (x1*y*z + y1*x*z + z1*x*y) % (x*y*z);
	//循环计算结果
	while (p--) {
		s = s*10;  //将尾数扩大10倍以此整除得到第i位 
		t = s/(x*y*z); //得到尾数第i位 
		s = s%(x*y*z); //得到尾数部分
		//判断当为最后一位
		if (p == 0) {
			s = s*10/(x*y*z);
			//判断是否要四舍五入
			if (s >= 5) {
				t++;
			}
			
			 
		} 
		//输出
		printf("%d", t); 
	} 
	return 0;
}
