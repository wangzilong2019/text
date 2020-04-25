#include "stdio.h" 
int main()
{

   //A、B、C拥有的机器数和盈利情况的对应关系
    int A[6]={0,3,8,9,12,13};
    int B[6]={0,5,10,11,11,11};
    int C[6]={0,4,6,11,12,12};
   /************begin************/
    int bestf = 0;
	int sum, x, y, z;
	int i, j, k;

	for (i = 0; i <= 5; i++) {
		for (j = 0; j <= 5; j++) {
			k = 5-i-j;
			if (k >= 0) {
				sum = A[i] + B[j] + C[k]; //sum代表盈利总额 
				//记录最优解 
				if (sum > bestf) {
					x = i;
					y = j;
					z = k;
					bestf = sum;
				}
			}

		}
	}
	printf("A B C最优分配机器数依次为 %d %d %d\n", x, y, z);
	printf("最大盈利值为%d", bestf);
	return 0;

/************end************/
}
