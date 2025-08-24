#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

int monthDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

long long getTotalDays(int year, int month, int day) {
    long long total = 0;
    
    for (int y = 1; y < year; y++) {
        total += 365 + (isLeapYear(y) ? 1 : 0);
    }
    
    for (int m = 1; m < month; m++) {
        total += monthDays[m];
        if (m == 2 && isLeapYear(year)) total++;
    }
    
    total += day;
    
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int y1, m1, d1, y2, m2, d2;
    cin >> y1 >> m1 >> d1;    // 시작일
    cin >> y2 >> m2 >> d2;    // D-Day
    
    if (y2 - y1 > 1000 || (y2 - y1 == 1000 && 
        (m2 > m1 || (m2 == m1 && d2 >= d1)))) {
        cout << "gg\n";
        return 0;
    }
    
    long long days1 = getTotalDays(y1, m1, d1);
    long long days2 = getTotalDays(y2, m2, d2);
    
    cout << "D-" << days2 - days1 << '\n';
    
    return 0;
}