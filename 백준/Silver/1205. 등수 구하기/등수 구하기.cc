#include<iostream>
#include<algorithm>
#include<vector>	
using namespace std;

int N, S, P;//Num, Score,Point
vector<long long> Scores;

int main()
{
	cin >> N >> S >> P;

	Scores.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> Scores[i];
	}
	
    // 랭킹이 꽉 찼을 때 마지막 등수의 점수보다 작거나 같으면 -1
    if (N == P && Scores[N - 1] >= S) {
        cout << -1;
        return 0;
    }

    // 등수 계산
    int rank = 1;
    for (int i = 0; i < N; i++) {
        if (Scores[i] > S) {
            rank++;
        }
        else {
            break;
        }
    }

    // 랭킹 리스트에 들어갈 수 있는지 확인
    if (rank > P) {
        cout << -1;
    }
    else {
        cout << rank;
    }

    return 0;
}