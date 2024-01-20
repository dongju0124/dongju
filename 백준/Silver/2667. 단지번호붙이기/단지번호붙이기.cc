#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
char map[26][26];
int visited[26][26];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int cnt;
int apt;
vector<int> cntArr;

void dfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (!visited[nx][ny]&&map[nx][ny]=='1')
			{
				visited[nx][ny] = 1;
				cnt++;
				dfs(nx, ny);
			}
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (map[i][j] == '1' && visited[i][j] == 0) {
				visited[i][j] = 1;
				cnt = 1;
				dfs(i, j);
				cntArr.push_back(cnt);
				apt++;
			}
		}
	}

	sort(cntArr.begin(), cntArr.end());

	cout << apt<<"\n";
	for (int i = 0; i < apt; i++)
	{
		cout << cntArr[i]<<"\n";
	}
}