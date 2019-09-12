#include<iostream>
#include <iomanip> 
using namespace std;
double pie[1000];
int pieNum;
int friendNum;
double maxPie = 0;
#define PI 3.1415926
/*
判断是否能整取
*/
bool check(double m) {
	int num=0;
	for (int i = 0; i < pieNum; i++) {
		num += int(pie[i] / m);
	};
	if (num >= friendNum+1) {
		return true;
	}
	else {
		return false;
	}
}

/*找出最大可分体积*/
double findMax(double low, double high) {
	if (high - low <= 0.0001) {
		return high;
	};
	double mid = (low + high) / 2.0;
	if (check(mid)) {
		return findMax(mid,high);
	} else {
		return findMax(low, mid);
	}
}

int main() {
 	cin >> pieNum >> friendNum;
	for (int i = 0; i < pieNum; i++) {
		cin >> pie[i];
		pie[i] = pie[i] * PI * pie[i];
		if (pie[i] > maxPie) {
			maxPie = pie[i];
		}
	};
	double max=findMax(0.0, maxPie);
	cout << setiosflags(ios::fixed) << setprecision(3) << max;
	system("pause");
	return 0;
}