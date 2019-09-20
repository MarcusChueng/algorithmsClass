#include<iostream>
using namespace std;
int binarySearch(int arr[], int x, int low, int high) {
	if (low > high) {
		return low;
	};
	int mid = (low + high) / 2;
	if (arr[mid] == x) {
		return mid;
	};
	if (arr[mid] > x) {
		return binarySearch(arr, x, low, mid - 1);
	}
	else {
		return binarySearch(arr, x, mid + 1, high);
	}
}

int main() {
	int len;
	int arr[100000];
	int x;
	cin >> len;
	cin >> x;
	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	};
	int index = binarySearch(arr, x, 0, len - 1);
	if (arr[index] == x) {
		cout << index << " " << index << endl;
	}
	else {
		cout << index - 1 << " " << index << endl;
	}
	system("pause");
	return 0;
}