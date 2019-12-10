#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
#define MAXLENGTH 1005
int bestPath = INT_MAX;
int arr[MAXLENGTH];
int value[MAXLENGTH];
int currentPath;
int processNum;
int machineNum;

void findPath(int t,int machineNum) {
	if (t >= processNum) { // 到达叶子结点
		int tmp = INT_MIN;
		for (int j = 0; j < machineNum; j++) {
			if (value[j] > tmp) {
				tmp = value[j]; // 获得当前所有机器运行最大的时间
			}
		}

		currentPath = tmp; // 更新最佳时间
		if (currentPath < bestPath) {
			bestPath = currentPath;
		}
		return;
	}
	else {
		for (int i = 0; i < machineNum; i++) {
			value[i] += arr[t];
			if (value[i] < bestPath) { // 假如大于最佳值就可以不用继续遍历
				findPath(t + 1, machineNum);
			}
			value[i] -= arr[t];
		}
	}
}


int main() {
	cin >> processNum >> machineNum;
	for (int i = 0; i < processNum; i++) {
		cin >> arr[i];
	}
	findPath(0, machineNum);
	cout << bestPath << endl;
	system("pause");
	return 0;
}