#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
#define MAXLENGTH 1005
double waiting[MAXLENGTH];
int main() {
	int num;
	double sum = 0.0; // 等待总时间
	double average;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> waiting[i];
	}
	sort(waiting, waiting + num);
	for (int i = 0; i < num; i++) {
		sum += (num - 1 - i)*waiting[i];
	}
	average = sum / num;
	cout <<fixed<<setprecision(2)<< average << endl;
	system("pause");
	return 0;
}