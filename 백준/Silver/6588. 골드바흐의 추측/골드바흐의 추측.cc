#include <iostream>
using namespace  std;

int arr[1000001] = { 1,1,1,0, };

int main() {
    int n, left, right;

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);


    //에라토스테네스의 체
    for (int i = 2; i * i < 1000000; i++)
    {
        if (arr[i] == 0)
            for (int j = i * i; j < 1000000; j += i)
            {
                arr[j] = 1;
            }
    }

    while (1)
    {

        cin >> n;
        //n이 0이면 종료
        if (!n) 
            break;

        left = 3;
        right = n - 3;

        while (left <= right)
        {
            if (!arr[left] && !arr[right])
                if ((left + right) == n)
                    break;
            left += 2;
            right -= 2;
        }

        if (left > right)  
            cout << "Goldbach's conjecture is wrong.";
        else 
            cout << n << " = " << left << " + " << right << '\n';
    }
}