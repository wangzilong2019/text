#include<stdio.h>
int main () {
	int v1, v2, t, s, l;
	int l1, l2, i;
	//��������
	scanf("%d %d %d %d %d",&v1, &v2, &t, &s, &l);
	//��ʼ�����Ӻ��ڹ���ܲ�����
	l1 = 0;
	l2 = 0;
	i = 0;
	while (l1 < l && l2 < l) {
		//���Ӻ��ڹ��ܲ�
		l1 += v1;
		l2 += v2;
		i++; 
		if (l1 >= l || l2 >= l){
			break;
		} 
		//����ʱ����˯��
		if (l1-l2 >= t) {
			l1 = l1 - v1*s;
		} 
	} 
	//�ж�˭�ȵ����յ�
	if (l1 > l2) {
		printf("R\n");
	} 
	else {
		if (l1 == l2) {
			printf("D\n");
		}
		else {
			printf("T\n");
		}
	}
	printf("%d\n",i);
	return 0;
} 
