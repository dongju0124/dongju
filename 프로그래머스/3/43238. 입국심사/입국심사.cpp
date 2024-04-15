#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());

    long long left = 1;
    long long right = n * (long long)times.back();

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long temp = 0;

        for (int i = 0; i < times.size(); i++) {
            temp += (mid / (long long)times[i]);
        }

        if (temp >= n) {
            right = mid - 1;
            answer = mid;
        }
        else left = mid + 1;
    }
    return answer;
}