#include<iostream>
#include<algorithm>
using namespace std;
#define MAXLENGTH 1005
int program[MAXLENGTH];
int main() {
	int num; // 文件个数
	int length; // 磁带长度
	int sum = 0; // 可存的程序的长度
	int counter = 0; // 计数器
	cin >> num >> length;
	for (int i = 0; i < num; i++) {
		cin >> program[i];
	};
	sort(program, program + num);
	for (int i = 0; i < num; i++) {
		sum += program[i];
		if (sum <= length) {
			counter++;
		}
		else {
			break;
		}
	}
	cout << counter << endl;
	system("pause");
	return 0;
}