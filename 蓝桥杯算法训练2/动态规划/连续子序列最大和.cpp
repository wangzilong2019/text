#include<iostream>
#include<string>
const int N = 100;
using namespace std;

/**
    动态规划求连续子序列最大和
	 

*/

int main () {
	int arr[N] = {-2, 1, -3, 4, -1, 2, 1};
	int dp[N];  //创建数组记录最优解dp[i[表示前i个元素中具有最大的和 
	
	//首先 初始化
	dp[0] = arr[0];
	for (int i = 1; i < 7; i++) {
		dp[i] = max(dp[i-1] + arr[i], arr[i]);
	} 
	int max = -999;
	int max_index;
	for (int i = 0; i < 7; i++) {
		//找到最大值
		if (max < dp[i]) {
			max = dp[i];
			max_index = i;
		} 
		cout << dp[i] << " ";
	}
	return 0;
}
