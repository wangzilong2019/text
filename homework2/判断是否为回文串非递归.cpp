/************begin************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int i, len, flag;
	char ch[100];    //��ż�����ַ���
	scanf("%s",ch); //���ܼ�����ַ���
	
	//���ַ�������
	len = strlen(ch);
	//���־λ����Ϊ���Ĵ�
	flag = 1; 
	//�ж��Ƿ�Ϊ���Ĵ�
	for (i = 0; i < len/2; i++) {
		if (ch[i] != ch[len-1-i]) {
			flag = 0;
			break;
		}
	} 
	//�жϱ�־λ�����
	if (flag) {
		printf("������ǻ��ġ�");
	} 
	else {
		printf("����Ĳ��ǻ��ġ�");
	}
	return 0;
}


/************end************/
