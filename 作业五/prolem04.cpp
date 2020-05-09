/*
Subject:计算机算法设计与分析
Title:例2-5 整数划分问题：输出一个整数的所有划分并统计总划分数
Coder:Hao
Class:计科0906
Num:0304090614
Date:Sept 20th,2011 
*/
 
//#include <iostream>
//using namespace std;
 
#include<stdio.h>
//用于打印(输出)的函数
//result为存储某划分结果的数组，length为此划分所占长度-1（从0开始）
void display(int *result,int length)       
{	
	for(int i=0;i<length;i++)
//		cout<<result[i]<<" ";
		printf("%3d", result[i]);
//	cout<<endl;
	printf("\n");
}
 
//主划分函数q(int n,int m,int *result,int length)
//算法参考了书例2-5并为了打印各划分做了一定修改
//n为待划分整数，m为最大加数上限,result和length意以同display函数同//名变量定义
//将q分成五种情况分类讨论，其中包含递归调用
int q(int n,int m,int *result,int length)
{
//当n>=1并且m=1时，q(n,m,result,length)=q(n-1,m,result,length)	
	 if(n>=0&&m==1)	{
//直至n=0并且m=1时，输出
		if(n==0)
		    display(result,length);
		else {
			result[length]=1;
			q(n-1,m,result,length+1);
		}
		return 1;
	 }
 
 
// 当 n=1并且m>1 时，分解已经完成，进行输出
	else if(n==1&&m>1){
		result[length]=n;
		display(result,length+1);
		return 1;
	}
 
//当n<m时，q(n,m,result,length)=q(n,n,result,length)
	else if(n<m) {
		return q(n,n,result,length);
	}
 
//当n=m时，q(n,m,result,length)=q(n,m-1,result,length)+1（划分数目）
	else if(n==m) {
		result[length]=m;
		display(result,length+1);
		return q(n,m-1,result,length)+1;
	}
 
//当n>m>1时，//q(n,m,result,length)=q(n-m,m,result,length+1)+q(n,m-1,result,length)
	else {
		result[length]=m;
	    return q(n-m,m,result,length+1)+q(n,m-1,result,length);
	}
}
 
 
  int main()
  {

	  int n;                            //定义待划分整数
	  int result[100]={0},length=0;        //初始化
	  printf("n=");
	  scanf("%d",&n);  //获取键入的n的数值
	  //cout<<"please input the integer:";  
	  //cin>>n;
	  //cout<<"整数"<<n<<"的划分个数为"<<q(n,n,result,length)<<endl;
	  printf("total=%d", q(n,n,result,length));
	  return 0;
  }
