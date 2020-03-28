#include<stdio.h>
#include<stdlib.h>
int main () {
	int *array = 0;
	int num;
	int sum, i;
	scanf("%d",&num);
	//动态申请数组
	array = (int *)malloc(sizeof(int)*num);
	//判断动态数组是否申请失败
	if (array == 0) {
		printf("动态数组申请失败\n");
		exit(0);
	} 
	sum = 0;
	//输入num个数据
	for (i = 0; i < num; i++) {
		scanf("%d",&array[i]);
		sum += array[i];
	} 
	printf("%d %d\n",sum, sum/num); 
	return 0;
} 
