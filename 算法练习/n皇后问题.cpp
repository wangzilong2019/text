#include<stdio.h>
#include<math.h>
#define MAX 100
int n;  //��¼�ʺ����
int x[MAX];  //��¼��i��Ԫ�ص��к�
int countn = 0;  //��¼���н�ĸ���
//�жϵ�t���ʺ���Ƿ���Է���λ��
int place(int t) {
	int i;
	int ok = 1;
	//�жϵ�t���ʺ���ǰ����Ƿ�ͬ�в�ͬб�� 
	for (i = 1; i < t; i++) {
		if (x[t] == x[i] || t-i == fabs(x[t]-x[i])) {
			ok = 0;
			break;
		}
	} 
	return ok;
} 
//��������
void backTrack(int t) {
	int i, j;
	//��ǰ�ڵ�ΪҶ�ӽڵ㣬���ҵ�һ�����н�
	if (t > n) {
		countn++;
		printf("��%d�з���Ϊ��\n",countn);
		for (i = 1; i <= n; i++) {
			printf("%d ",x[i]);
		}
		printf("\n");
	} 
	else {
		//�ҵ�ÿ���ʺ��ں��ʵ��к�
		for (i = 1; i <= n; i++) {
			x[t] = i;
			if (place(t)) {
				backTrack(t+1);
			}
		} 
	}
} 
int main() {
	printf("������ʺ�ĸ���n��\n");
	scanf("%d",&n);
	backTrack(1);
	return 0;
} 
