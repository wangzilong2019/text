/************begin************/
#include<stdio.h>
//�жϾ�λ�����Ƿ�Ϊÿ�����ֶ�����ͬ��
int check(int a[], int n) {
	//���ñ�־λ
	int flag = 1;
	int i = 4;
	int j;
	while (n) {
		a[i++] = n%10;
		n /= 10;
	}
	for (i = 0; i < 9; i++) {
		for (j = i+1; j < 9; j++) {
			if (a[i] == a[j]) {
				flag = 0;
				break;
			}
		}
	}
	return flag;
} 
int main () {
	int i, j, k, m, n;
	int a[9];
	//���м���
	for (i = 5; i <= 9; i++) {
		for(j = 0; j <= 9; j++) {
			//ÿλ��ͬ
			if (i != j) {
				for (k = 0; k <= 9; k++) {
					//ÿλ��ͬ
					if (k != i && k != j) {
						for (m = 0; m <= 9; m++) {
							//ÿλ��ͬ
							if (m != i && m != j && m != k) {
								n = i*1000 + j*100 + k*10 + m;
								a[0] = i;
								a[1] = j;
								a[2] = k;
								a[3] = m; 
								//�жϽ���Ƿ�Ϊ��λ����ͬ������ 
								if (check(a,2*n)) {
									printf("2*%d=%d\n",n, 2*n); 
								}
							} 
						}
					} 
				}
			} 
		}
	} 
	return 0;
}




























/************end************/
