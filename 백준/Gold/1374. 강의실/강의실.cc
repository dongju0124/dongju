#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
using namespace std;

struct Lecture {
    int start;
    int end;
};

bool compareStart(const Lecture& a, const Lecture& b) {
    return a.start < b.start;
}

int main() {
    int N;
    cin >> N;

    vector<Lecture> lectures(N);
    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp >> lectures[i].start >> lectures[i].end;
    }

    sort(lectures.begin(), lectures.end(), compareStart);

    priority_queue<int, vector<int>, greater<int>> lastTime;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (lastTime.empty())
        {
            cnt++;
            lastTime.push(lectures[i].end);
        }
        else
        {
            if (lastTime.top() > lectures[i].start)
                cnt++;
            else
                lastTime.pop();

            lastTime.push(lectures[i].end);
        }
    }

    cout << cnt << endl;

    return 0;
}
