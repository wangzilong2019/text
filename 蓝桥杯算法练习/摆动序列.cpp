#include<stdio.h>
#define MAX 1000
int sum;  //��¼���н�
int book[MAX] = {0};
int data[MAX] = {0};
int n;
//������ȱ����ҵ����н⡤
void dfs(int t) {
	int i;
	if (t > 2) {
		//��ֻ����������������
		if (t == 3) {
			sum++;
		} 
		//�����������������ж��Ƿ��������� 
		else {
			//���������� 
			//ע���жϳ˻�Ϊ����һ��Ҫע����ͬλ�ü���� 
			if ((data[t-1]-data[t-3])*(data[t-2]-data[t-3]) < 0) {
				sum++;
			}
			//�������˲��ҵ�����������
			else {
				return ;
			} 
		}
	}
	//�˶δ���Ŀ���ҵ�����ͬ������
	for (i = 1; i <= n; i++) {
		//���ñ�־���жϴ������Ƿ��ù�
		if (book[i] == 0) {
			book[i] = 1;
			data[t] = i;
			dfs(t+1);
			book[i] = 0; 
		} 
	} 
	//�˲����������֧
	return ; 
} 

int main () {
	//��������n
	scanf("%d", &n);
	//��ʼ��
	sum = 0;
	dfs(1);
	printf("%d\n", sum); 
	return 0;
} 


