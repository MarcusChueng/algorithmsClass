#include<iostream>
#include<algorithm>
using namespace std;
#define MAXLENGTH 105
//cost[i][j]表示从i到j所需要的最小费用

void minimumCost(int n, int cost[][MAXLENGTH]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// 入口点的情况
			if (i == 1 && j == 1) {
				cost[i][j] = cost[i][j];
			}
			// 最上面一行的情况
			else if (i == 1 && j != 1) {
				cost[i][j] = cost[i][j] + cost[i][j - 1];
			}
			// 最左边一列的情况
			else if (i != 1 && j == 1) {
				cost[i][j] = cost[i][j] + cost[i - 1][j];
			}
			//其余情况
			else {
				cost[i][j] = min(cost[i][j - 1], cost[i - 1][j])+cost[i][j];
			}
		}
	}
	cout << cost[n][n] << endl;
}

int main() {
	int cost[MAXLENGTH][MAXLENGTH] = { 0 };
	int n;//正方形的宽度
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> cost[i][j];
		}
	}
	minimumCost(n, cost);
	system("pause");
	return 0;
}