#include<stdio.h>
#define MAX 1001
//�����ṹ��
typedef struct {
	int beg;
	int end;
	int flag;
}road; 

int main () {
	int l, m, sum;
	int i, j;
	road a[MAX];
	//���빫·����
	scanf("%d",&l);
	//����������
	scanf("%d",&m);
	//����ÿ��������ʼ���յ�
	for (i = 0; i < m; i++) {
		scanf("%d %d", &(a[i].beg), &(a[i].end));
		a[i].flag = 1;
		//�ж�ÿ�������Ƿ����ص�
		for (j = 0; j < i; j++) {
			if (a[i].end >= a[j].beg && a[i].beg <= a[j].end && a[j].flag) {
				a[j].flag = 0;
				if (a[i].beg > a[j].beg) {
					a[i].beg = a[j].beg;
				}
				if (a[i].end < a[j].end) {
					a[i].end = a[j].end;
				}
			}
		} 
	}
	//��������
	sum = l+1;
	for (i = 0; i < m; i++) {
		if (a[i].flag) {
			sum = sum-(a[i].end-a[i].beg+1);
		}
	} 
	printf("%d",sum);
}
