#include<iostream>
using namespace std;
int N;
int arr[1001][6];
int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= 5; j++)
            cin >> arr[i][j];
    int maxCnt = 0, ans = 1;
    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int j = 1; j <= N; j++) {
            if (i == j) 
                continue;
            for (int k = 1; k <= 5; k++) {
                if (arr[i][k] == arr[j][k]) {
                    cnt++;
                    break;
                }
            }
        }
        if (cnt > maxCnt) {
            maxCnt = cnt;
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}