/*
Subject:������㷨��������
Title:��2-5 �����������⣺���һ�����������л��ֲ�ͳ���ܻ�����
Coder:Hao
Class:�ƿ�0906
Num:0304090614
Date:Sept 20th,2011 
*/
 
//#include <iostream>
//using namespace std;
 
#include<stdio.h>
//���ڴ�ӡ(���)�ĺ���
//resultΪ�洢ĳ���ֽ�������飬lengthΪ�˻�����ռ����-1����0��ʼ��
void display(int *result,int length)       
{	
	for(int i=0;i<length;i++)
//		cout<<result[i]<<" ";
		printf("%3d", result[i]);
//	cout<<endl;
	printf("\n");
}
 
//�����ֺ���q(int n,int m,int *result,int length)
//�㷨�ο�������2-5��Ϊ�˴�ӡ����������һ���޸�
//nΪ������������mΪ����������,result��length����ͬdisplay����ͬ//����������
//��q�ֳ���������������ۣ����а����ݹ����
int q(int n,int m,int *result,int length)
{
//��n>=1����m=1ʱ��q(n,m,result,length)=q(n-1,m,result,length)	
	 if(n>=0&&m==1)	{
//ֱ��n=0����m=1ʱ�����
		if(n==0)
		    display(result,length);
		else {
			result[length]=1;
			q(n-1,m,result,length+1);
		}
		return 1;
	 }
 
 
// �� n=1����m>1 ʱ���ֽ��Ѿ���ɣ��������
	else if(n==1&&m>1){
		result[length]=n;
		display(result,length+1);
		return 1;
	}
 
//��n<mʱ��q(n,m,result,length)=q(n,n,result,length)
	else if(n<m) {
		return q(n,n,result,length);
	}
 
//��n=mʱ��q(n,m,result,length)=q(n,m-1,result,length)+1��������Ŀ��
	else if(n==m) {
		result[length]=m;
		display(result,length+1);
		return q(n,m-1,result,length)+1;
	}
 
//��n>m>1ʱ��//q(n,m,result,length)=q(n-m,m,result,length+1)+q(n,m-1,result,length)
	else {
		result[length]=m;
	    return q(n-m,m,result,length+1)+q(n,m-1,result,length);
	}
}
 
 
  int main()
  {

	  int n;                            //�������������
	  int result[100]={0},length=0;        //��ʼ��
	  printf("n=");
	  scanf("%d",&n);  //��ȡ�����n����ֵ
	  //cout<<"please input the integer:";  
	  //cin>>n;
	  //cout<<"����"<<n<<"�Ļ��ָ���Ϊ"<<q(n,n,result,length)<<endl;
	  printf("total=%d", q(n,n,result,length));
	  return 0;
  }
