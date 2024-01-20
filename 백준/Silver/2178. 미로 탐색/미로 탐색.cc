#include<iostream>
#include<string>
#include<queue>
using namespace std;

char arr[101][101];
int N, M;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool visited[101][101];
int cnt[101][101];

void bfs(int x, int y) {

	queue<pair<int, int>> Q;
	visited[x][y] = true;
	Q.push({ x,y });
	cnt[x][y] = 1;
	while (!Q.empty())
	{
		int cx = Q.front().first;
		int cy = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (arr[nx][ny]=='1'&& !visited[nx][ny]) {
					cnt[nx][ny] = cnt[cx][cy] + 1;
					visited[nx][ny] = true;
					Q.push({nx,ny});
				}
			}
		}
	}
}

int main()
{


	cin >> N >> M;

	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}

	bfs(0, 0);

	cout << cnt[N - 1][M - 1];

	return 0;
}