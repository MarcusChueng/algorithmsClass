#include<iostream>
using namespace std;
#define MAXLENGTH 10000
double cost[MAXLENGTH][MAXLENGTH];
void findCheapest(double cost[][MAXLENGTH],int n) {
	for (int r = 2; r <= n; r++) {
		//步长，先从长度为2的开始逐步找最优解，比如说1到2，2到3就是长度为2的，一直到长度为n
		for (int i = 1; i <= n-r+1; i++) {
			//i从第一个开始，一直到最后一个
			int j = r + i - 1;
			//i到j的长度就是r
			for (int k = i; k <= j; k++) {
				//在i到j的中途找某一站，使得i到j的花费最少
				int temp = cost[i][k] + cost[k][j];
				if (temp < cost[i][j]) {
					cost[i][j] = temp;
				}
			}
		}
	}
}
int main() {
	int n;//站点数
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			cin >> cost[i][j];
		}
	}
	for (int i = 1; i < n; i++) {
		cost[i][i] = 0;
	}
	findCheapest(cost, n);
	cout << cost[1][n] << endl;
	system("pause");
	return 0;
}