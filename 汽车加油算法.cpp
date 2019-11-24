#include<iostream>
using namespace std;
#define MAX 1005
int counter; // 记录最少加油次数
int distances[MAX]; // 记录加油站之间的距离
int canDrive; // 一次加油可以行驶的距离
int num; // 加油站个数

void lessCount() {
	int sum = 0;
	for (int i = 0; i <= num; i++) {
		if (distances[i] > canDrive) {
			cout << "No Solution!" << endl;
			return;
		}
	}
	for (int i = 0; i <=num; i++) {
		sum += distances[i];
		if (sum > canDrive) {
			counter++;
			sum = distances[i];
		}
	}
	cout << counter << endl;
};

int main() {
	cin >> canDrive >> num;
	for (int i = 0; i <= num; i++) {
		cin >> distances[i];
	}
	lessCount();
	system("pause");
	return 0;
}