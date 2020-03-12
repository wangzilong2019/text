#include<stdio.h>
#define MAX 10	
//检测天数是否正确
void check(char year1,char year2,char month1,char month2,int day1,int day2) {
	int y;
	y = 2000 + (year1-48)*10 + year2-48;
	int m = (month1-48)*10+month2-48;
	if (2000 <= y && y <= 2059) {
		if (1 <= m <= 12) {
			if (( y % 400 == 0) || ( y % 4 == 0 && y % 100 != 0)) {
				if (1 <= (day1-48)*10 + day2-48 <=29) {
					printf("%d-%d-%d\n",y,m,(day1-48)*10 + day2-48);
				}
				else {
					
				}
			}
			else {
				if (1 <= (day1-48)*10 + day2-48 <=28) {
					printf("%d-%d-%d\n",y,m,(day1-48)*10 + day2-48);
				}
				else {
					
				}
			}
		}
		else {
			
		}
	}
	y = 1900 + (year1-48)*10 + year2-48;
	if (1960 <= y && y <= 1999) {
		if (1 <= m <= 12) {
			if (( y % 400 == 0) || ( y % 4 == 0 && y % 100 != 0)) {
				if (1 <= (day1-48)*10 + day2-48 <=29) {
					printf("%d-%d-%d\n",y,m,(day1-48)*10 + day2-48);
				}
				else {
					
				}
			}
			else {
				if (1 <= (day1-48)*10 + day2-48 <=28) {
					printf("%d-%d-%d\n",y,m,(day1-48)*10 + day2-48);
				}
				else {
					
				}
			}
		}
		else {
			
		}
	}
} 

int main() {
	char str[MAX];
	char year[MAX];
	char month[MAX];
	char day[MAX];
	//输入时间
	gets(str);
	//假设取年份 
	year[1] = str[0];
	year[2] = str[1];
	//假设取月份
	month[1] = str[3];
	month[2] = str[4];
	//假设取日
	day[1] = str[6];
	day[2] = str[7]; 
	check(year[1],year[2],month[1],month[2],day[1],day[2]);
	check(day[1],day[2],year[1],year[2],month[1],month[2]);
	check(day[1],day[2],month[1],month[2],year[1],year[2]);
	return 0;
}
