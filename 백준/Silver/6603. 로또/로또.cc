#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[14];
int lotto[7];
// Visited 없는 이유 같은 수를 또 써야하기 때문에

void dfs(int num, int cnt)
{
    if (cnt == 6){
        for (int i = 0; i < 6; i++)
            cout << lotto[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = num; i < n; i++)
    {
            lotto[cnt] = arr[i];
            dfs(i + 1, cnt + 1); 
    }
}

int main() {
    while(cin >> n && n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        dfs(0, 0);
        cout << "\n";
    }
    
    return 0;
}