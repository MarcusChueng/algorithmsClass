#include<iostream>
#include<algorithm>
using namespace std;
#define MAXLENGTH 205
int arr[MAXLENGTH];
void findMaximun(int arr[], int n) {
	for (int i = 1; i <= n; i++) {
		if (i == 1 && arr[i] < 0) {
			arr[i] = 0;
		}
		else {
			if (arr[i] + arr[i - 1] > 0) {
				arr[i] = arr[i] + arr[i - 1];
			}
		}
	}
}
int main() {
	int n,max;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	findMaximun(arr, n);
	max = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	cout << max;
	system("pause");
	return 0;
}