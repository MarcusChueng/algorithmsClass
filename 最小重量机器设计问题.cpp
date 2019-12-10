#include<iostream>
#define MAXLENGTH 1005
using namespace std;
int n, m, d, cp = 0, cw = 0, sum = 0;
int c[MAXLENGTH][MAXLENGTH];
int w[MAXLENGTH][MAXLENGTH];
int flag[MAXLENGTH];
int tmp[MAXLENGTH];

void backtrack(int i) {
	if (i > n) {
		if (cw < sum) {
			for (int i = 1; i <= m; i++) {
				flag[i] = tmp[i];
			}
			sum = cw;
		}
		return;
	}
	for (int j = 1; j <= m; j++) {
		tmp[i] = j;
		cw += w[i][j];
		cp += c[i][j];
		if (cw < sum&&cp <= d) {
			backtrack(i + 1);
		}
		cw -= w[i][j];
		cp -= c[i][j];
		tmp[i] = 0;
	}
}

int main() {
	cin >> n >> m >> d;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
		}
		sum += c[i][1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> w[i][j];
		}
	}
	backtrack(1);
	cout << sum << endl;
	for (int k = 1; k <= m; k++) {
		cout << flag[k] << " ";
	};
	cout << endl;
	system("pause");
	return 0;
}
