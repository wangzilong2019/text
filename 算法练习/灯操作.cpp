#include<stdio.h>
#define MAX 1000
int main() {
	int i, j;
	int n;
	int status[MAX] = {1};  //��ʼʱ���õ�ȫ��
	printf("������ƺ��˵ĸ���n��\n");
	scanf("%d",&n);
	//1��ͬѧ����ȫ���ص�
	for (i = 1; i <= n; i++) {
		status[i] = 1 - status[i];
	} 
	//2��ͬѧ�������Ϊ2�ı����ĵƴ�
	for (i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			status[i] = 1 - status[i];
		}
	} 
	//����ͬѧ�������Ϊ�Լ���������ŵ����෴����
	for (i = 3; i <= n; i++) {
		//���Ϊiͬѧ�Եƽ��в���
		for (j = 1; j <= n; j++) {
			if (j % i == 0) {
				status[j] = 1 - status[j];
			}
		} 
	} 
	//������ո����Ƶ�״̬
	for (i = 1; i <= n; i++) {
		printf("%d ",status[i]);
	} 
	return 0;
} 
