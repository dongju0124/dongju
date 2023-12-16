#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int getCount(string a, string b, string c) {
	int cnt = 0;
	for (int i = 0; i < a.size(); i++) {
		cnt += (a[i] != b[i]) + (b[i] != c[i]) + (c[i] != a[i]);
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;

	cin >> T;

	while (T--)
	{
		vector<string> mbti;
		int N;
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			string MBTI;
			cin >> MBTI;
			mbti.push_back(MBTI);
		}

		if (N>32)
		{
			cout << 0 << "\n";
		}
		else
		{
			int dif_count = 99999;

			for (int i = 0; i < mbti.size()-2; i++){
				for (int k = i + 1; k < mbti.size()-1; k++){
					for (int j = k + 1; j < mbti.size(); j++){
						dif_count = min(dif_count, getCount(mbti[i], mbti[k], mbti[j]));
					}
				}
			}

			cout << dif_count << "\n";
		}
		
	}

	return 0;
}
