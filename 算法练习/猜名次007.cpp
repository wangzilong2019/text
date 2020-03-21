#include<stdio.h>
int main () {
	//定义a，b，c，d，e分别代表5个人的名次
	int a, b, c, d, e;
	//a的名次 
	for (a = 1; a <= 5; a++) {
		//b的名次 
		for (b = 1; b <= 5; b++) {
			//没有重复名次 
			if (a != b) {
				//c的名次
				for (c = 1; c <= 5; c++) {
					//无重复名次 
					if (c != a && c != b) {
						//d的名次 
						for (d = 1; d <= 5; d++) {
							//无重复名次
							if (d != a && d != b && d != c) {
								//e的名次
								e = 15 - a - b - c - d;
								//无重复名次
								if (e != a && e != b && e != c && e != d) {
									//利用逻辑表达式判断是否每个人说的话只说对了一半
									 if(((b == 3) + (c == 5)) == 1 && 
									 	((d == 2) + (e ==4 )) == 1 && 
										((b == 1) + (e == 4)) == 1 && 
										((c == 1) + (b == 2)) == 1 && 
										((d == 2) + (a == 3)) == 1) {
											printf("A是第%d名\n",a);
											printf("B是第%d名\n",b);
											printf("C是第%d名\n",c);
											printf("D是第%d名\n",d);
											printf("E是第%d名\n",e);
										} 
								} 
							} 
						}
					} 
				} 
			} 
		}
	} 
	return 0;
} 
