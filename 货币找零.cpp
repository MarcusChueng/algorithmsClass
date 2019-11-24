#include<iostream>
using namespace std;
int money[7] = { 100, 50, 20, 10, 5, 2, 1 };
int result[7] = { 0 };
int main() {
	int num; // 付款金额
	int count;  // 消费金额
	int leave;  // 找零金额
	cin >> num >> count;
	leave = num - count;
	for (int i = 0; i < 7; i++) {
		if (leave / money[i] != 0) {
			int current = leave / money[i];
			result[i] = current;
			leave = leave - current * money[i];
		}
	}
	for (int i = 0; i < 7; i++) {
		if (result[i] != 0) {
			cout << money[i] << " " << result[i] << endl;
		}
	}
	system("pause");
	return 0;
}