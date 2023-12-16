#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string func;
		cin >> func;
		int num;
		cin >> num;
		deque<int> dq;
		string s;
		cin >> s;
		string temp;

		for (int n = 0; n < s.size(); n++) {
			if (isdigit(s[n])) {
				temp += s[n];
			}
			else {
				if (temp != "") {
					dq.push_back(stoi(temp));
					temp = "";
				}
			}
		}
		int error_check = 0;

		int r = 0;
		for (int n = 0; n < func.size(); n++) {
			if (func[n] == 'R') {
				r++;
			}
			else {
				if (dq.empty()) {
					cout << "error" << "\n";
					error_check = 1;
					break;
				}
				if (r % 2 == 0) {
					dq.pop_front();
				}
				else {
					dq.pop_back();
				}
			}
		}

		if (error_check == 0) {
			cout << "[";
			if (r % 2 == 1) {
				for (int n = dq.size() - 1; n >= 0; n--) {
					cout << dq[n];
					if (n != 0)
						cout << ",";
				}
			}
			else {
				for (int n = 0; n < dq.size(); n++) {
					cout << dq[n];
					if (n != dq.size() - 1)
						cout << ",";
				}
			}
			cout << "]" << "\n";
		}
	}

	return 0;
}