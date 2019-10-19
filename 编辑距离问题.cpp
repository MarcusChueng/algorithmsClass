#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int edit[1000][1000];
char a[1000];
char b[1000];
int editDistance(char a[],char b[]){
	if (strlen(a) == 0 || strlen(b) == 0) {
		return -1;
	}
	for (int i = 0; i < strlen(a)+1; i++) {
		for (int j = 0; j < strlen(b)+1; j++) {
			if (i == 0) {
				edit[i][j] = j;
			}
			else if (j == 0) {
				edit[i][j] = i;
			}
			else {
				if (a[i - 1] == b[j - 1]) {
					edit[i][j] = edit[i - 1][j - 1];
				}
				else {
					edit[i][j] = 1 + min(min(edit[i - 1][j], edit[i][j - 1]), edit[i - 1][j - 1]);
				}
			}
		}
	}
	return edit[strlen(a)][strlen(b)];
}
int main() {
	cin >> a;
	cin >> b;
	cout << editDistance(a, b) << endl;
	system("pause");
	return 0;
}