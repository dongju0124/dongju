#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, C, P; //num, cost, price
vector<int> tree;
int pay;
long long ans = 0;
int main()
{

	cin >> N >> C >> P;

	for (int i = 0; i < N; i++)
	{
		int temp;

		cin >> temp;
		tree.push_back(temp);
	}
	
	sort(tree.begin(), tree.end());
	for (int i = 1; i <= tree[N-1]; i++)
	{
		long long temp = 0;
		for (int j = 0; j < N; j++)
		{
			if (tree[j] >= i)
			{
				int piece = tree[j] / i;
				int cut = 0;

				if (tree[j] % i == 0)
					cut = 1;

				if(piece * P * i - (piece - cut) * C>0)
					temp += piece * P * i - (piece - cut) * C;
			}
				
		}
		ans = max(temp, ans);
	}

	cout << ans;
}