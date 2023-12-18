#include <iostream>

using namespace std;

int paper[129][129];//종이의 크기
int blue;//파란종이 수
int white;//흰종이 수
int N;// 한변의 길이

void check(int x, int y, int n)
{
	int color = paper[x][y];
	for (int i = x; i < x + n; i++){
		for (int j = y; j < y + n; j++){
			if (color != paper[i][j]){
				check(x, y, n / 2);//0,0에서 출발
				check(x + n / 2, y, n / 2);///n+2, 0에서 출발
				check(x, y + n / 2, n / 2);//0,n+2에서 출발
				check(x + n / 2, y + n / 2, n / 2);//n+2,n+2 에서 출발
				return;
			}
		}
	}
	if (color == 1)blue++; //위에서 if문이 틀리면 같은거니까 종이 색 구별
	else white++;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)//행부터 입력
	{
		for (int j = 0; j < N; j++)//열 입력
		{
			cin >> paper[i][j];
		}
	}

	check(0, 0, N);//시작은 0,0부터
	cout << white << endl;
	cout << blue << endl;


	return 0;
}