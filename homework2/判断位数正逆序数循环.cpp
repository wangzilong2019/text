/************begin************/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int n, sum, m, num;//��������������
	int len;
	int a[5];//�����������ÿ������ 
	printf("������һ����λ���ڵ�������\n");
	scanf("%d",&n); //��ȡ�����������
	len = 0;
	//������¼ԭ����������� 
	m = n;
	while (n) {
		n /= 10;
		len++;
	}
	sum = 0;
	//������¼�������ֵ�λ�� 
	num = len;
	n = m;
	while (len) {
		sum += n%10*pow(10, len-1);
		n /= 10;
		len--;
	}
	printf("�������������һ��%dλ��\n",num); 
	printf("��˳�����Ϊ��\n%d\n",m);
	printf("���������Ϊ��\n%d",sum);
	
}
/************end************/
