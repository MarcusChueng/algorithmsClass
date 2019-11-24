#include<iostream>
#include<queue>
using namespace std;
priority_queue<int> q1; // 从大到小的优先队列
priority_queue<int, vector<int>, greater<int> > q2; // 从小到大的优先队列
int main() { 
	int num;
	int arr[1005];
	cin >> num;
	int maxtime = 0;
	int mintime = 0;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
		q1.push(arr[i]);
		q2.push(arr[i]);
	}

	while (true) {
		if (q1.size() == 1) {
			break;
		}
		else {
			int tmp1 = q1.top();
			q1.pop();
			int tmp2 = q1.top();
			q1.pop();
			maxtime += tmp1 + tmp2 - 1;
			q1.push(tmp1+tmp2);
		}
	}

	while (true) {
		if (q2.size() == 1) {
			break;
		}
		else {
			int tmp1 = q2.top();
			q2.pop();
			int tmp2 = q2.top();
			q2.pop();
			mintime += tmp1 + tmp2 - 1;
			q2.push(tmp1+tmp2);
		}
	}

	cout << maxtime << " " << mintime << endl;
	system("pause");
	return 0;
}