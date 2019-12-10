#include<iostream>
using namespace std;
#define MAXLENGTH 10005
int arr[MAXLENGTH]; // 存储数组
bool haveUsed[MAXLENGTH]; // 存储数组各个元素当前状态
int value; // 存储当前值
bool isPrint = false;

void count(int i,int num,int sum) {
	if (i > num||isPrint) {
		return;
	};
	haveUsed[i] = true;
	value += arr[i];

	if (value == sum&&!isPrint) {
		for (int j = 0; j < num; j++) {
			if (haveUsed[j]==true) {
				cout << arr[j]<<" ";
			}
		};
		isPrint = true;
		return;
	}
	else if(value<sum){
		count(i + 1, num, sum);
	}
	
	if (isPrint) {
		return;
	}

	haveUsed[i] = false;
	value -= arr[i];

	count(i + 1, num, sum);
	return;
}
int main() {
	int num, sum;
	int tmp = 0;
	cin >> num >> sum;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
		tmp += arr[i];
	}
	if (tmp < sum) {
		cout << "No Solution!" << endl;
		return 0;
	}
	count(0, num, sum);
	if (!isPrint) {
		cout << "No Solution!" << endl;
	}
	system("pause");
	return 0;
}