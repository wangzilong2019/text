#include<stdio.h>
#include<stdlib.h>
#define MAX 10001
int maxv(int *p, int n) {
	int temp,i;
	temp = p[0];
	for (i = 1; i < n; i++) {
		if (temp < p[i]) {
			temp = p[i];
		}
	}
	return temp;
}
int main () {
	int n, m;
	int num, max, i, j;
	int *p;
	int second, min, flag;
	//����ˮ��ͷ�����ͽ�ˮ����
	scanf("%d %d",&n, &m);
	//��̬��������
	p = (int *)malloc(sizeof(int)*n);
	//�ж������Ƿ�����ɹ�
	if(p == NULL) {
		printf("error");
		return 0;
	} 
	//����ÿ���˵Ľ�ˮ��
	for (i = 0; i < n; i++) {
		scanf("%d",&p[i]);
	} 
	//�ж�������ˮ��ͷ�Ĺ�ϵ
	if (n <= m) {
		printf("%d", maxv(p,n));
	} 
	if (n > m) {
		second = 0;
		num = 0;
		while (n > m) {
			//�ҵ���ǰ������Сֵ
			min = p[0];
			flag = 0;
			for (i = 0; i < m; i++) {
				if (min > p[i]) {
					min = p[i];
					flag = i;
				}
			} 
			for (i = 0; i < m; i++) {
				p[i] = p[i]-min;
			}
			second += min;
			p[flag] = p[m+num];
			num++;
			n--;
			if (n <= m) {
				printf("%d",maxv(p,n)+second);
			}	 
		}
	}
	
	return 0;
}
