/************begin************/

#include<stdio.h>
int main()
{
	long n; //��ż��������ֵ
	int a[3] = {4, 7, 9};
	int flag[3];
	int i, k;
	k = 0;
	printf("������һ��������");
	scanf("%ld",&n);//��ȡ���������ֵ
	for (i = 0; i < 3; i++) {
		if (n%a[i] == 0) {
			flag[k++] = a[i];
		}
	}
	if (k == 1) {
		printf("������ܱ�%d����",flag[0]);
	} 
	else {
		printf("�������ͬʱ��");
		for (i = 0; i < k-1; i++) {
			printf("%d,",flag[i]);
		}
		printf("%d����",flag[k-1]);
	}
	return 0; 
}

/************end************/
