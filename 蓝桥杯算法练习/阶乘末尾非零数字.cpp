#include<stdio.h>
int main () {
	int n, num, i;
	//�����������
	scanf("%d", &n);
	//��׳�
	num = 1;
	for (i = n; i >= 1; i--) {
		num *= i;
		//����β��0��ȥ��
		if (num%10 == 0) {
			num /= 10;
		} 
		//ֻ������λ
		if (num/100 > 0) {
			num %= 100;
		} 
	} 
	//������һ���������
	printf("%d\n",num%10); 
	return 0;
}
