/************begin************/

#include<stdio.h>
#include<stdlib.h>
int ctn = 0;
int count(int i) //λ�����㺯��
{
	//�ж�ѭ���˳�����
	if (i/10 == 0) {
		return ctn+1;
	} 
	ctn++;
	//�ݹ�
	return count(i/10); 
}
void nxdisp(int i) //�����������
{
	//�ݹ��˳����� 
	if (i/10 == 0) {
		printf("%d",i%10);
		return;
	}
	printf("%d",i%10);
	nxdisp(i/10);
}
void sxdisp(int i)//˳���������
{
	if (i/10 != 0) {
		sxdisp(i/10);
	}
	printf("%d",i%10);
}

int main()
{
     int n;//��������������
     //����������
     printf("������һ��������\n");
	 scanf("%d",&n);
	 printf("%d��%dλ��\n",n, count(n));
	 printf("�����ӡ\n");
	 nxdisp(n);
	 printf("\n");
	 printf("˳���ӡ\n");
	 sxdisp(n);
}
/************end************/
