#include<iostream>
#include<cstring>
using namespace std;

int ruleA[65][65];
int ruleB[65][65];
bool Room[65][65];
int state[65][65]; // 0은 B 1은 A
int visited[2][4][65][65];// A인지 B인지, 각도, X, Y
int dustMove = 0;
int cleanMove = 0;
int H, W;

// 각도에 따라 각도가 0이면 위로 한칸, 1이면 오른쪽으로 2면 아래로, 3이면 왼쪽으로 이동
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int rotate(int D, int rotate)
{
	return (D + rotate) % 4;
}

int main()
{
	int R, C, D;
	cin >> H >> W;
	cin >> R >> C >> D;
	for (int i = 0; i < H; i++)
	{
		string rule;
		cin >> rule;
		for (int j = 0; j < W; j++)
		{
			ruleA[i][j] = rule[j] - '0';
		}
	}

	for (int i = 0; i < H; i++)
	{
		string rule;
		cin >> rule;
		for (int j = 0; j < W; j++)
		{
			ruleB[i][j] = rule[j] - '0';
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < H; k++) {
				fill(visited[i][j][k], visited[i][j][k] + W, 0);
			}
		}
	}

	for (int i = 0; i < 65; ++i) {
		for (int j = 0; j < 65; ++j) {
			state[i][j] = 1;
		}
	}



	while(true)
	{
		if (R < 0 || R >= H || C < 0 || C >= W || 64*64 <= visited[state[R][C]][D][R][C])
		{
			break;
		}

		visited[state[R][C]][D][R][C]++;
		dustMove++;

		if (state[R][C])
		{
			cleanMove = 0;
			D = rotate(D, ruleA[R][C]);
			state[R][C] = 0;
		}
		else
		{
			cleanMove++;
			D = rotate(D, ruleB[R][C]);
		}

		C += dx[D];
		R += dy[D];
		
	}

	cout << dustMove - cleanMove;

}