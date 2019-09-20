#include<iostream>
using namespace std;
int searchMid(int a[],int b[],int n) {
	int low1 = 0, low2 = 0, high1 = n - 1, high2 = n - 1;
	while (low1 < high1&&low2 < high2) {
		int mid1 = (low1 + high1) / 2;
		int mid2 = (low2 + high2) / 2;
		if (a[mid1] == b[mid2]) {
			return a[mid1];
		};
		if (a[mid1] < b[mid2]) {
			if ((low1 + high1) % 2 == 0) {
				low1 = mid1;
				high2 = mid2;
			}
			else {
				low1 = mid1 + 1;
				high2 = mid2 ;
			}
		}
		else {
			if ((low1 + high1) % 2 == 0) {
				high1 = mid1;
				low2 = mid2;
			}
			else {
				high1 = mid1;
				low2 = mid2 +1;
			}
		}
	};
	if (a[low1] < b[low2]) {
		cout << a[low1] << endl;
	}
	else {
		cout << b[low2] << endl;
	}
}

int main() {
	int a[100000];
	int b[100000];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	searchMid(a, b, n);
	system("pause");
	return 0;
}