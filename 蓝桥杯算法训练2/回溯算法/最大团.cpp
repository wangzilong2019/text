#include<iostream>
using namespace std;
int const N = 1000;

int cn = 0;  //记录当前加入节点数
int fn = 0;  //记录剩余节点数
int bestx[N]; 
int x[N];
int n, m;
int map[N][N];

//判断第t个顶点是否可以加入 
int check(int t) {
	bool flag = true;
	for (int i = 1; i < t; i++) {
		if (x[i] && map[i][t] == 0) {  //第t个顶点与前t-1个无边相连且前t个顶点在集合中 
			flag = false;
			break;
		}
	}
	return flag;
}

void backtrack(int t) {
	//当达到叶子节点时
	if (t > n) {
		for (int i = 1;)
	} 
} 



int main () {
	int u, v; 
	cout <<"输入图中的节点数n:"<<endl;
	cin >> n;
	cout <<"输入图中的边数m:" <<endl;
	cin >> m;
	cout <<"输入图中相连边的俩个顶点u和v:" <<endl;
	for (int i = 1; i <= m; i++) {
		cin >> u;
		cin >> v;
		map[u][v] = map[v][u] = 1;
	} 
	//初始化
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = 0;
		}
	} 
	backtrack(1);
	return 0;
} 
