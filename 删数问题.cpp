#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	int num;// 删除的数字个数
	cin >> s >> num;
	while (num > 0) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] > s[i + 1]) {
				s.erase(i, 1);
				break;
			}
		}
		num--;
	};

	for (int i = 0; i < s.size(); i++) {
		if (s[0] == '0') {
			s.erase(0, 1);
		}
	}
	cout << s << endl;

	system("pause");
	return 0;
}