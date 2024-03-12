#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> ans(N);
	vector<int> line (N);

	for (int i = 0; i < N; i++)
	{
		cin >> line[i];
	}

	for (int i = 0; i < N; i++)
	{
		int cnt = 0;
		for (int j = 0; j < N; j++)
		{
			if (line[i] == cnt)
			{
				//ans가 0으로 비어있다면 값 입력, 아니라면 오른쪽으로 한칸 더 이동
				if (!ans[j])
				{
					//N은 >= 1 이기 때문에
					ans[j] = i + 1;
					break;
				}
			}
			else
			{
				if (!ans[j])
					cnt++;
			}

		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << " ";

	}
}