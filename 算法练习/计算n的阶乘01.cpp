#include<stdio.h>
#define MAX 1000
int main() {
	int i, j;
	int n;
	int a[MAX];
	printf("��������Ҫ����Ľ׳�n��\n");
	scanf("%d",&n);
	a[1] = 1;
	int digit = 1;  //����������λ��
	int num = 0;
	for (i = 2; i <= n ; i++) {
		num = 0;
		for (j = 1; j <= digit; j++) {
			int temp = a[j]*i + num;  //����ÿһλ*i�ӽ�λ�Ľ��
			a[j] = temp % 10;
			num = temp / 10; //�����λ 
		}
		//���½�����ȴ���ԭ��������ȣ����¸�ֵ 
		while (num) {
			digit++;
			a[digit] = num % 10;
			num /= 10;
	
		}	
	}
	for (i = digit; i >= 1; i--) {
		printf("%d",a[i]); 
	} 
	return 0;
}
