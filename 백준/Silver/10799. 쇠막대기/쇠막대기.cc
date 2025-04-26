#include<iostream>
#include<string>
using namespace std;

int main()
{
    string St;
    cin >> St;

    int cnt = 0;
    int bars = 0;

    for (int i = 0; i < St.size(); i++)
    {
        if (St[i] == '(')
        {
            bars++;
        }
        else
        {
            bars--;

            if (St[i - 1] == '(')
            {
                cnt += bars;
            }
            else
            {
                cnt += 1;
            }
        }
    }

    cout << cnt;
}
