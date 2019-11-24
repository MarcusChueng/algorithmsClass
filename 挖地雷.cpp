#include<iostream>
using namespace std;
#define MAXLENGTH 200
int n;
int cellar[MAXLENGTH];
bool isAccess[MAXLENGTH][MAXLENGTH];
void landmine(int n,bool isAccess[][MAXLENGTH],int cellar[]) {
	int tmp[MAXLENGTH] = { 0 };
	tmp[n] = cellar[n];
	int k1, k2;
	cin >> k1 >> k2;
	while (k1&&k2) {
		isAccess[k1][k2] = true;
		cin >> k1 >> k2;
	}
	int path[MAXLENGTH] = { 0 };
	for (int i = n - 1; i >= 1; i--) {
		int k = 0, max = 0;
		for (int j = i + 1; j <= n; j++) {
			if (isAccess[i][j] && tmp[j] > max) {
				max = tmp[j];
				k = j;
			}
		}
		tmp[i] = max + cellar[i];
		path[i] = k;
	}

	int fmax = 0, fk = 1;
	for (int i = 1; i <= n; i++) {
		if (tmp[i] > fmax) {
			fmax = tmp[i];
			fk = i;
		}
	}
	cout << fk;
	while (path[fk]) {
		cout <<"-"<< path[fk];
		fk = path[fk];
	}
	cout << endl;
	cout << fmax << endl;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cellar[i];
	}
	landmine(n, isAccess, cellar);
	system("pause");
	return 0;
}