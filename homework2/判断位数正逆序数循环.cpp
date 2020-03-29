/************begin************/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int n, sum, m, num;//存放输入的正整数
	int len;
	int a[5];//用来存放逆序每个数字 
	printf("请输入一个五位以内的正整数\n");
	scanf("%d",&n); //获取键入的正整数
	len = 0;
	//用来记录原来输入的数字 
	m = n;
	while (n) {
		n /= 10;
		len++;
	}
	sum = 0;
	//用来记录输入数字的位数 
	num = len;
	n = m;
	while (len) {
		sum += n%10*pow(10, len-1);
		n /= 10;
		len--;
	}
	printf("所输入的数字是一个%d位数\n",num); 
	printf("按顺序输出为：\n%d\n",m);
	printf("按逆序输出为：\n%d",sum);
	
}
/************end************/
