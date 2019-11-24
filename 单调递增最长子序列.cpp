#include<iostream>
#include<algorithm>
using namespace std;
#define MAXLENGTH 1000
int longestArr[MAXLENGTH];
int findLongest(int arr[],int n){
	int maxNum = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				longestArr[i] = max(longestArr[i], longestArr[j] + 1);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (longestArr[i] > maxNum) {
			maxNum = longestArr[i];
		}
	}
	return maxNum;
}
int main() {
	int arr[MAXLENGTH];
	int n;
	for (int i = 0; i < MAXLENGTH; i++) {
		longestArr[i] = 1;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int find = findLongest(arr, n);
	cout << find << endl;
	system("pause");
	return 0;
}