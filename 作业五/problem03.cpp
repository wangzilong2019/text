#include<stdio.h>
int count;
int a[10];

//�ж��Ƿ�������Ŀ����
int check() {
	int join;  //������ʱ��¼ǰiλ
	int i;
	int flag = 1;
	join = 0;
	for (i = 1; i <= 9; i++) {
		join = join * 10 + a[i];
		//��ǰiλ��i��Ϊ0����ֹ
		if (join % i != 0) {
			flag = 0;
			break;
		} 
	} 
	return flag;
} 

//��ӡ���
void print() {
	int i;
	for (i = 1; i <= 9; i++) {
		printf("%d", a[i]);
	}
	printf("\n");
} 


void backtrack(int t) {
	int temp, i;
	//������Ҷ�ӽڵ�ʱ���
	if (t > 9) {
		//�������������
		if (check()) {
			count++;
			print();
		}
		return ;
	} 
	for (i = t; i <= 9; i++) {
		temp = a[t];
		a[t] = a[i];
		a[i] = temp;
		//�ݹ�
		backtrack(t + 1);
		//����
		temp = a[t];
		a[t] = a[i];
		a[i] = temp; 
	}
}

int main () {
	int i;
	//��ʼ��
	count = 0;
	for (i = 1; i <= 9; i++) {
		a[i] = i;
	}
	backtrack(1);
	printf("һ����%d��", count);
	return 0;
} 
