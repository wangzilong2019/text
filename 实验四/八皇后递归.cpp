#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define MAX 999 3
int count;
int x[MAX];  //��¼���н��λ��x[i]��ʾ��i��x[i]��

int n;//�ʺ����
void backtrack(int k); //λ�ó��ԣ�Ҫ��ʹ�õݹ�

//�жϵ�t���ʺ���Ƿ������������
int check(int t) {
	int i;
	int flag = 1;
	//�жϵ�t��Ԫ����ǰt-1��Ԫ���Ƿ�ͬ����б�� 
	for (i = 1; i < t; i++) {
		if (x[i] == x[t] || t - i == fabs(x[t] - x[i])) {
			flag = 0;
			break;
		}
	}
	return flag;
} 

//��ӡ��� 
void print() {
	int i;
	printf("\n");
	printf("\n");
	for (i = 1; i <= 8; i++) {
		printf("��%d�ʺ���%d��\n", i, x[i]);
	}
}









void backtrack(int k)   //λ�ó��ԣ�Ҫ��ʹ�õݹ�
{
 	int i;
	//���ҵ�һ�ַ���ʱ
	if (k > n) {
		//���н�������1
		count++;
		//������н�
		print();
		return ; 
	} 
	
	//ȷ��ÿ���ʺ��λ��
	for (i = 1; i <= n; i++) {
		//��t���ʺ����t��x[t]�� 
		x[k] = i;
		//���������ݹ� 
		if (check(k)) {
			backtrack(k + 1);
		}
	}   



}




int main()
{  
	int i;
	printf("������n��");
    scanf("%d",&n);
	count = 0;
	//������н� 
	backtrack(1);
	printf("\n");
	printf("һ����%d�ַ���", count); 
	return 0;



}
