#include<iostream>
using namespace std;
//相邻两个有序子列表的归并
int countr = 0;
void Merge(int data[], int result[], int low, int mid, int high) {
	int i = low;
	int j = mid + 1;
	int k = low;
	while (i <= mid && j <= high) {
		if (data[i] <= data[j]) {
			result[k++] = data[i++];
		}
		else {
			result[k++] = data[j++];
			countr += mid - i + 1;
		}
	};
	while (i <= mid) {
		result[k++] = data[i++];
	};
	while (j <= high) {
		result[k++] = data[j++];
	};
}


void MSort(int data[], int result[], int low, int high) {
	int mid;
	if (high - low == 1)//子序列中只有两元素进行比较
	{
		if (data[low] > data[high])
		{
			int t = data[low];
			data[low] = data[high];
			data[high] = t;
			countr++;
		}
		return;
	}
	else if (high == low) {
		return;
	}
	else {
		mid = (low + high) / 2;
		MSort(data, result, low, mid);
		MSort(data, result, mid + 1, high);
		Merge(data, result, low, mid, high);
		for (int i = low; i <= high; i++) {
			data[i] = result[i];
		};
	};
}

int main() {
	int num;
	int a[1000];
	int r[1000] = { 0 };
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a[i];
	};
	MSort(a, r, 0, num-1);
	cout << countr << endl;
	system("pause");
	return 0;
}
