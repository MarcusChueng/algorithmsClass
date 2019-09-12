#include<iostream>
using namespace std;
//求单峰数组最大值
int findMax(int a[], int low, int high) {
	int mid = (low + high) / 2;
	if (low == high) {
		return mid;
	};
	if (a[mid] >= a[mid + 1] && a[mid] >= a[mid - 1]) {
		return mid;
	}
	else if (a[mid] > a[mid - 1] && a[mid + 1] > a[mid]) {
		return findMax(a,mid+1, high);
	}
	else if (a[mid] < a[mid - 1] && a[mid + 1] < a[mid]) {
		return findMax(a, low, mid);
	}
}
int main() {
	int num;
	int arr[10000];
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	int index = findMax(arr, 0, num - 1);
	cout << arr[index];
	system("pause");
	return 0;
}