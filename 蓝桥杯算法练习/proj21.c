/************begin************/
#include <stdio.h> 
#include <math.h>

int board[100][100] = {0};//���� 
int count = 1;//���δ������˳�� 
int dis[4][2] = {{0,0},{0,1},{1,0},{1,1}};//�����ң��£����½�����λ�� 

void show(int size)
{
	int i = 1,j = 1;
	for(i = 1; i <= size; i++)
	{
		for(j = 1; j <= size; j++)
			printf("%2d ",board[i][j]);
		printf("\n");
	}
}

void Cover(int tx,int ty,int x,int y,int size)
{
	int num = 0;
	int i = 1;
	int row = 0,col = 0;
	int r = 0, c = 0;
	//����ֻ��һ�����ӵ���� 
	if(size < 2)
		return ;
	
	size /= 2; 
	num = count++;
	for(i = 0; i < 4; i++)
	{
		//�ֳ��ĸ����飬row,col�ֱ�Ϊ�ĸ���������Ͻ�λ�� 
		row = dis[i][0] * size + tx;
		col = dis[i][1] * size + ty;
		
		//���ȱ�ٵĸ��Ӳ��ڵ�ǰ��Χ���Ͱ��¼ӵĲ�ȱ���� 
		if(!(x >= row && x < (row + size) &&\
			 y >= col && y < (col + size)) )
			 {
			 	//r,c Ϊ�¼ӵĲ�ȱ��λ�� 
			 	r = dis[3 - i][0] * (size-1) + row;
			 	c = dis[3 - i][1] * (size-1) + col;
				board[r][c] = num; 
				Cover(row,col,r,c,size); 
			 }
		else
			Cover(row,col,x,y,size);
	} 
}

int main()
{
	int k = 3;
	int x,y;//��ȱ���λ��
	int size = pow(2,k);//���̵�����
	
	 
	//cout<<size; 
	
	
	x = 1,y = 1;
	board[x][y] = 0;
	
	Cover(1,1,x,y,size);
	
	show(size);
	return 0;
}













































/************end************/