#include<stdio.h>
#define MAX 1000
int main () {
	float d1, c, d2, p;
	int n;
	float dis[MAX], price[MAX];
	float max_len, total, remain;
	int i, j;
	int flag = 1;
	//输入总距离、邮箱容量、每升油行驶距离、出发点每升油价格、加油站数
	scanf("%f %f %f %f %d", &d1, &c, &d2, &p, &n);
	max_len = c*d2;
	//输入沿途加油站距离以及油价 
	for (i = 1; i <= n; i++) {
		scanf("%f %f", &dis[i],&price[i]);
		if (dis[i]-dis[i-1] > max_len) {
			flag = 0;
			break;
		}
	} 
	if ( !flag ) {
		printf("No Solution");
		return 0;
	}
	//初始化 
	dis[0] = 0;
	price[0] = p;
	dis[n+1] = d1;
	price[n+1] = 0;
	for (i = 0; i <= n; i = j) { //i为当前加油站，j为下一个， 令j为当前，重新循环
		for (j = i+1; j <= n+1; j++) {
			//如果不能行驶到必当比当前便宜的加油站 
			if (dis[j]-dis[i] > max_len) {
				j--;
				break;
			}
			//找到比当前 便宜的加油站
			if (price[j] <= price[i]) {
				break;
			} 
		} 
		
		//如果找到比当前便宜的加油站
		if (price[j] <= price[i]) {
			total += ((dis[j]-dis[i])/d2 - remain)*price[i];
			remain = 0;
		} 
		
		//如果找不到或是不能到达
		else {
			total += (c- remain)*price[i];
			remain = c - (dis[j]-dis[i])/d2;
		} 
		
	}
	printf("%.2f", total);
	return 0;
}
