#include<iostream>
using namespace std;
int main() {
	int count, tmp, index, num, arr[10];
	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> num;
		arr[i] = num;
	};
	tmp = arr[0];
	index = 0;
	for (int i = 0; i < count; i++) {
		if (arr[i] > tmp) {
			tmp = arr[i];
			index = i;
		}
	};
	cout << tmp << " " << index << endl;
	system("pause");
	return 0;
}