/************begin************/
#include<stdio.h>
#include<string.h>
#define MAX 100 
char s[MAX];
int len; 
int isPalindrome(int i)  //�����жϺ���
{ 
	//���ж���ɺ���� 
	if (len-2*i == 1 || len-2*i == 0) {
		return 1;
	} 
	//�������������Ҫ��ʱ�˳�ѭ�� 
	if (s[i] != s[len-1-i]) {
		return 0;
	} 
	return isPalindrome(++i);
}
int main()//������
{
	int i;
	
	//�����ַ��� 
	gets(s);
	//���ַ������� 
	len = strlen(s);
	if (isPalindrome(0)) {
		printf("������ǻ��ġ�");
	} 
	else {
		printf("����Ĳ��ǻ��ġ�");
	}
	return 0;
}


/************end************/
