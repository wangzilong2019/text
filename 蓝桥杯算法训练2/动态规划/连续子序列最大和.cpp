#include<iostream>
#include<string>
const int N = 100;
using namespace std;

/**
    ��̬�滮����������������
	 

*/

int main () {
	int arr[N] = {-2, 1, -3, 4, -1, 2, 1};
	int dp[N];  //���������¼���Ž�dp[i[��ʾǰi��Ԫ���о������ĺ� 
	
	//���� ��ʼ��
	dp[0] = arr[0];
	for (int i = 1; i < 7; i++) {
		dp[i] = max(dp[i-1] + arr[i], arr[i]);
	} 
	int max = -999;
	int max_index;
	for (int i = 0; i < 7; i++) {
		//�ҵ����ֵ
		if (max < dp[i]) {
			max = dp[i];
			max_index = i;
		} 
		cout << dp[i] << " ";
	}
	return 0;
}
