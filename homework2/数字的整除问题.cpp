/************begin************/

#include<stdio.h>
int main()
{
	long n; //存放键入的整数值
	int a[3] = {4, 7, 9};
	int flag[3];
	int i, k;
	k = 0;
	printf("请输入一个整数：");
	scanf("%ld",&n);//获取键入的整数值
	for (i = 0; i < 3; i++) {
		if (n%a[i] == 0) {
			flag[k++] = a[i];
		}
	}
	if (k == 1) {
		printf("这个数能被%d整除",flag[0]);
	} 
	else {
		printf("这个数能同时被");
		for (i = 0; i < k-1; i++) {
			printf("%d,",flag[i]);
		}
		printf("%d整除",flag[k-1]);
	}
	return 0; 
}

/************end************/
