#include<iostream>
using namespace std;
#define MAXLENGTH 6005
int relationNum;
int residentNum;
bool enemy[MAXLENGTH][MAXLENGTH] = { false };
int tmpArr[MAXLENGTH];
int maxArr[MAXLENGTH];
int maxx;
int tmpMax;

void search(int t) {
	if (t > residentNum) {
		if (tmpMax > maxx) {
			maxx = tmpMax;
			for (int i = 1; i <= residentNum; i++) {
				maxArr[i] = tmpArr[i];
			}
		}
	}
	else {
		int flag = 0;
		for (int i = 1; i <= t; i++) {
			if (enemy[i][t] && tmpArr[i] == 1) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			tmpArr[t] = 1;
			tmpMax++;
			search(t + 1);
			tmpMax--;
		}
		// 剪枝，如果当前最大值加上剩下的所有人数都小于全局最大值就不用继续遍历
		if ((tmpMax + (residentNum - t + 1)) >= maxx) {
			tmpArr[t] = 0;
			search(t + 1);
		}
	}
}

int main() {
	int x, y;
	cin >> residentNum >> relationNum;
	for (int i = 1; i <= relationNum; i++) {
		cin >> x >> y;
		enemy[x][y] = enemy[y][x] = true;
	}
	search(1);
	cout << maxx << endl;
	for (int i = 1; i <= residentNum; i++) {
		cout << maxArr[i]<<" ";
	}
	cout << endl;
	system("pause");
	return 0;
}