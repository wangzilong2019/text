#include<stdio.h>
#include<stdlib.h>
int main () {
	int *array = 0;
	int num;
	int sum, i;
	scanf("%d",&num);
	//��̬��������
	array = (int *)malloc(sizeof(int)*num);
	//�ж϶�̬�����Ƿ�����ʧ��
	if (array == 0) {
		printf("��̬��������ʧ��\n");
		exit(0);
	} 
	sum = 0;
	//����num������
	for (i = 0; i < num; i++) {
		scanf("%d",&array[i]);
		sum += array[i];
	} 
	printf("%d %d\n",sum, sum/num); 
	return 0;
} 
