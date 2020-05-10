#include<iostream>
#include<cstdio>
using namespace std;

const int N = 100001;
int father[N];
int n, m;  //分别记录顶点和边的个数
struct Edge{
	int u, v; //每个边的俩个顶点 
}e[N]; 

//初始化每个顶带你的父节点 
void init() {
	for (int i = 1; i <= n; i++) {
		father[i] = i;
	}
} 

//找祖宗
int find(int x) {
	if (x != father[x]) {
		father[x] = find(father[x]);  //把当前节点到其祖宗节点的集合好全部改为祖宗节点集合号 
	}
	return father[x];  //返回祖宗集合号 
} 

int main () {
	int count = 0;
	//输入顶点和边的个数
	cin >>n >>m;
	//输入每条边的俩个顶点
	for (int i = 1; i <= m; i++) {
		cin>> e[i].u>> e[i].v;
	} 
	init();
	//计算
	for (int i = 1; i <= m; i++) {
		//找到当前俩个顶点的集合号
		int p = find(e[i].u);
		int q = find(e[i].v);
		//若俩个顶点的集合号相同则累加器加1
		if (p == q) {
			count++;
		} else if (p > q) {
			father[p] = q;
		} else {
			father[q] = p;
		}
	} 
	//利用并查集思想，将左右与祖宗节点即1号节点相同的值计数器加1 
	for (int i = 1; i <= n; i++) {
		if (father[i] == 1) {
			count++;
		}
	}
	//输入总数
	cout<<count<<endl; 
	return 0;
} 
