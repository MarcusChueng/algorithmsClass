#include<iostream>
#include<algorithm>
using namespace std;
#define MAXLENGTH 105
int trangle[MAXLENGTH][MAXLENGTH];
void findMaxSum(int trangle[][MAXLENGTH], int n) {
	for (int i = n; i > 0; i--) {
		for(int j = 1; j <= i; j++) {
			int temp = max(trangle[i + 1][j + 1], trangle[i + 1][j]);
			trangle[i][j] = trangle[i][j] + temp;
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> trangle[i][j];
		}
	}
	findMaxSum(trangle, n);
	cout << trangle[1][1] << endl;
	system("pause");
	return 0;
}