/************begin************/
#include <stdio.h> 
#include <math.h>

int board[100][100] = {0};//棋盘 
int count = 1;//依次处理方格的顺序 
int dis[4][2] = {{0,0},{0,1},{1,0},{1,1}};//本身，右，下，右下角三个位置 

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
	//处理只有一个格子的情况 
	if(size < 2)
		return ;
	
	size /= 2; 
	num = count++;
	for(i = 0; i < 4; i++)
	{
		//分成四个方块，row,col分别为四个方块的左上角位置 
		row = dis[i][0] * size + tx;
		col = dis[i][1] * size + ty;
		
		//如果缺少的格子不在当前范围，就把新加的残缺格补上 
		if(!(x >= row && x < (row + size) &&\
			 y >= col && y < (col + size)) )
			 {
			 	//r,c 为新加的残缺格位置 
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
	int x,y;//残缺格的位置
	int size = pow(2,k);//棋盘的行数
	
	 
	//cout<<size; 
	
	
	x = 1,y = 1;
	board[x][y] = 0;
	
	Cover(1,1,x,y,size);
	
	show(size);
	return 0;
}













































/************end************/