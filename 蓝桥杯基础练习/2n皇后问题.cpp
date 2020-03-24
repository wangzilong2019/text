/**1������Ľ���˼·�������뵽n�ʺ�����
   2�������ȷ��úڻʺ󣬺ڻʺ����������ٷ��ð׻ʺ󡢰׻ʺ�����������Ϊһ����¼ 

*/ 
#include<stdio.h>
#include<math.h>
#define MAX 1000
int posB[MAX];  //��źڻʺ��λ��
int posW[MAX];  //��Ű׻ʺ��λ��
int map[MAX][MAX];  //��ŵ�ͼ
int n;  //��¼������ɫ�Ļʺ����
int ans = 0;  //������¼���еĽ���
//�ڻʺ������ɺ󣬷��ð׻ʺ�
//�жϰ׻ʺ�ķ���λ���Ƿ�Ϸ�
int checkW(int cur) {
	int flag;
	int i;
	flag = 1;
	//�жϵ�cur���ʺ���ǰcur-1���Ƿ�ͬ��ͬб��
	for (i = 1; i < cur; i++) {
		if (posW[i] == posW[cur] || fabs(posW[cur] - posW[i]) == cur - i) {
			flag = 0;
			break;
		}
	} 
	return flag;
} 
void dfs_w(int cur) {
	int i, j;
	//�ж��Ƿ񵽴�Ҷ�ӽڵ�
	if (cur == n+1) {
		ans++;
	} 
	else {
		for (i = 1; i <= n; i++) {
			//�жϷ���λ���Ƿ񱻺ڻʺ���� 
			if (posB[cur] == i) {
				continue;
			}
			//�жϵ�ǰλ���Ƿ�Ϸ� 
			posW[cur] = i;
			if (map[cur][i] == 0) {
				continue;
			}
			//�ж��Ƿ�����ʺ���ù���
			if (checkW(cur)) {
				dfs_w(cur+1);
			} 
		}
	} 
} 
//�жϺڻʺ�ķ���λ���Ƿ�Ϸ�
int checkB(int cur) {
	int flag;
	int i;
	flag = 1;
	//�жϵ�cur���ʺ���ǰcur-1���Ƿ�ͬ��ͬб��
	for (i = 1; i < cur; i++) {
		if (posB[i] == posB[cur] || fabs(posB[cur] - posB[i]) == cur - i) {
			flag = 0;
			break;
		}
	} 
	return flag;
} 
//��չ��ǰ�ڵ� 
void dfs_b(int cur) {
	int i, j;
	//�жϵ�ǰ�ڵ��Ƿ񵽴�Ҷ�ӽڵ�
	if (cur == n+1) {
		//���ð׻ʺ�
		dfs_w(1);	
	} 
	else {
		//���úڻʺ�
		for (i = 1; i <= n; i++) {
			//�жϷ���λ���Ƿ�Ϸ�
			if (map[cur][i] == 0) {
				continue;
			} 
			//�Ϸ����¼����Ԫ�ص�λ��
			posB[cur] = i;
			//�ж��Ƿ�����ʺ���ù���
			if (checkB(cur)) {
				dfs_b(cur+1);
			} 
		} 
	}
} 
int main () {
	int i, j;
	//���뵥����ɫ�ʺ�ĸ���
	scanf("%d",&n);
	//�����ͼ��·��
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d",&map[i][j]);
		}
	} 
	//�ȷ��úڻʺ�
	dfs_b(1); 
	printf("%d",ans); 
	return 0;
}
