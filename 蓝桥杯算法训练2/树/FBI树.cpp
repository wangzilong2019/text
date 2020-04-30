#include<iostream>
#include<cmath>
#include<string>
using namespace std;
string s;

//输出字符串
void print(int left, int right) {
	int type0 = 0;
	int type1 = 0;
	for (int i = left; i <= right; i++) {
		if (s[i] == '0') {
			type0++;
		} else {
			if (s[i] == '1') {
				type1++;
			}
		}
	}
	//当全为1字符时 
	if (type0 == 0 && type1 != 0) {
		printf("I");
	} else {
		if (type0 != 0 && type1 == 0) {
			printf("B");
		} else {
			printf("F");
		}
	}
} 

void struct1(int left, int right) {
	print(left, right);
	if (left != right) {
		struct1(left, (left + right) / 2);
		struct1((left + right) / 2 + 1, right);
	}
	
}

int main () {
	int n;
	//输入n
	cin>>n;
	//输入字符串
	cin>>s;
	//构造树且输出 
	struct1(0, pow(2, n) - 1); 
	return 0;
} 
