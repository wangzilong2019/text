#include<stdio.h>
#include<math.h>
#define MAX 1000
#define MOD 1000000 
//���ַ���ÿ������Ԫ���д����ֳ��ȴ���1 
int main() {
	int a[MAX];
	int n;
	int i, j;
	int sum = 0;  //���õ�ǰ��λΪ0
	int start;
	printf("������Ҫ����Ľ׳�n��\n");
	scanf("%d",&n);
	int m = log(n)*n/6+2;  //����׳�n�Ľ������ 
	a[1] = 1;
	for (i = 2; i <= m; i++) {
		a[i] = 0;
	}
	//���ѭ������׳�
	for (i = 2; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			int temp = a[j]*i + sum;
			a[j] = temp % MOD;
			sum = temp / MOD;
		}
		if (sum != 0) {
			a[j] = sum;
		}
	} 
	//�ҵ���һ����Ϊ�������Ԫ�� 
	for (i = m; i >= 1; i--) {
		if (a[i] == 0) {
			continue;
		}
		else {
			start = i;
			break;
		}
	}
	for (i = start; i >= 1; i--) {
		printf("%d",a[i]);
	}
	return 0;
} 
