#include<iostream>
#include<algorithm>
using namespace std;
struct Section {
	int left;
	int right;
}sections[1000];

bool cmp(Section a,Section b) {
	if (a.right == b.right) {
		return a.left > b.left;
	}else{
		return a.right < b.right;
	}
}

int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> sections[i].left >> sections[i].right;
	}
	sort(sections, sections + num, cmp);
	int counter = 1;
	int pointer = sections[0].right;
	for (int i = 1; i < num; i++) {
		if (sections[i].left > pointer) {
			pointer = sections[i].right;
			counter++;
		}
	}
	cout << counter << endl;
	system("pause");
	return 0;
}