//12865

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int K;
int W[100001];
int V[1001];
int bag[101][100001];//main 안에 넣으면 스택 터진다고 오류남. 전역변수로 하면 왜 안나는지 모르겠음.

int main() {

	//물건 개수와 준수가 들 수 있는 무게
	cin >> N >> K;

	//무게와 가치 입력받기
	for (int i = 1; i <= N; i++)
	{
		cin >> W[i] >> V[i];
	}

	//물건 싹 돌아보기
	for (int i = 1; i <= N; i++)//bag[i-1][j] == [i-1] 번째 물건
	{
		for (int j = 1; j <= K; j++) {
			if (j >= W[i])
			{
				bag[i][j] = max(bag[i - 1][j], V[i] + bag[i - 1][j - W[i]]);
			}
			else
				bag[i][j] = bag[i - 1][j];

		}
	}

	cout << bag[N][K] << endl;

	return 0;
}
