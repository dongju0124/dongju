#include<iostream>
#include<algorithm>
using namespace std;

long long liquid[100001];
int N;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> liquid[i];
	}
	sort(liquid, liquid + N);

	int left = 0;
	int right = N - 1;
	int minSum = 2000000000;

	int a, b;

	while (left < right) {
		int sum = liquid[left] + liquid[right];
		if (abs(sum) < minSum) {
			minSum = abs(sum);
			a = liquid[left];
			b = liquid[right];
		}
		if (sum < 0) {
			left++;
		}
		else if (sum > 0) {
			right--;
		}
		else {
			break;
		}
	}

	cout << a << " " << b << "\n";
}