#include<stdio.h>
#define MAX 1000
int main() {
	int i, j;
	int a[MAX];
	int n;
	int countn = 0;
	//���������ģn
	scanf("%d",&n);
	//����n��ƿ�ӵ�����˳��
	for (i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
	} 
	//�ж�ÿ�����Ƿ���� 
	for (i = 1; i <= n-1; i++) {
		//�ж�ÿһ��ƿ�������˳���Ƿ���� 
		if (a[i] != i) {
			for (j = i; j <= n; j++) {
				if (i == a[j]) {
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
					countn++;
					break;
				} 
			}
		}
	}
	printf("%d",countn);
	return 0;
}
