
/**
    并查集
	并查集是一种数据结构，它用来处理一些不相交的集合
	   1、初始化每个个点坐在的集合为自身 
	   2、查找俩个集合号是即为查找祖宗集合号，采用递归的方法查找，祖宗集合号等于自己时即停止
	      在回归时，把当前节点到祖宗路径上的所有节点统一噶为祖宗的集合号
	   3、合并：俩个元素集合号不同时，合并成一个集合 
    
*/

#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
const int N = 100;
int n, m;  //定义节点数和边数 
int father[N];

struct Edge{
	int u, v;  //每条边的俩个顶点 
	int w;  //边的权值 
}e[N*N];

//初始化
void init(int n) {
	for (int i = 1; i <= n; i++) {
		father[i] = i;
	}
} 

//定义排序优先级
bool comp(Edge x, Edge y) {
	return x.w < y.w;
} 

//并查集时找祖宗
int find(int x) {
	//当前集合号不等于祖宗集合号时递归找祖宗
	if (x != father[x]) {
		father[x] = find(father[x]);  //把当前节点到祖宗路径上所有集合号改为祖宗 
	} 
	return father[x]; //返回祖宗节点的集合号 
} 

//合并集合操作
int merge(int a, int b) {
	//分别求出俩者的集合号
	int p = find(a);
	int q = find(b); 
	if (p == q) {
		return 0;
	}
	//将小的集合号赋给大的集合号
	if (p < q) {
		father[q] = p;
	} else {
		father[p] = q;
	}
} 

//Kursal算法
int kurskal() {
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		//可以合并
		if (merge(e[i].u, e[i].v)) {
			ans += e[i].w;
			n--;
			//当合并n-1条边时结束
			if (n == 1) {
				return ans;
			} 
		} 
	}
	return 0;
} 

int main () {
	cout <<"输入图中的节点数n和边数m："<<endl;
	cin >> n >> m;
	cout <<"输入每条边的俩个顶点u和v和权值w："<<endl;
	for (int i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	//初始化
	init(n);
	//将边排序
	sort(e, e + m, comp);
	//kurskal算法
	int ans = kurskal(); 
	cout<<"最小生成树的权值为：" << ans <<endl;
	return 0;
}
