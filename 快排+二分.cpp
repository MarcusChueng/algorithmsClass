#include<iostream>
using namespace std;
int partition(int a[], int left, int right) {
	int x = a[left];
	while (left < right) {
		while (left < right&&a[right] >= x) {
			right--;
		};
		a[left] = a[right];
		while (left < right&&a[left] <= x) {
			left++;
		};
		a[right] = a[left];
	};
	a[left] = x;
	return left;
}
/*
通过调用partition函数获得划分点，判断划分点是否第k小，若不是，递归调用find函数继续在左段或右段查找；
有点像二分查找（就是吧！）
*/
int find(int a[], int left, int right, int k) {
	int point = partition(a, left, right);
	if (point == k - 1) {
		return point;
	}
	else if (point < k - 1) {
		return find(a, point + 1, right, k);
	}
	else if (point > k - 1) {
		return find(a, left, point - 1, k);
	}
	return 0;
}

int main() {
	int n, k;
	cin >> n >> k;
	int a[10000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	};
	cout << a[find(a, 0, n - 1, k)] << endl;
	system("pause");
	return 0;
}