#include <iostream>
using namespace std;

bool btn[10];

int able(int n) {
	if (n == 0) {
		if (btn[n]) {
			return 0;
		}
		else
		{
			return 1;
		}
	}

	int len = 0;
	while (n > 0) {
		if (btn[n % 10]) {
			return 0;
		}
			
		len += 1;
		n = n / 10;
	}
	return len;
}

int main() {

	int ch;
	cin >> ch;

	int bk;
	cin >> bk;
	if (bk > 0) {
		for (int i = 0; i < bk; i++)
		{
			int N;
			cin >> N;
			btn[N] = true;
		}
	}

	int times = abs(ch - 100);
	for (int i = 0; i <= 1000000; i++)
	{
		int x = i;
		int len = able(x);


		if (len>0) {
			int cnt = abs(x - ch);
			if (times > len + cnt){
				times = len + cnt;
			}
			
		}
	}

	cout << times;

	return 0;


}