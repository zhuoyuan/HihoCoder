#include <iostream>

using namespace std;
inline bool isLeap(int year) {
    return !(year % 4) && (year % 100) || !(year % 400);
}

int num229(int year, string month, int day) {
    int i = year / 4 - year / 100 + year / 400;
    bool isBeyond = true;

    if(month.compare("January") == 0 || month.compare("February") == 0 && day != 29)
        isBeyond = false;
    if(isLeap(year))
        return i - !isBeyond;
    return i;
}

int main(int argc, char *argv[]) {
    int T = 0;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int begin_year, end_year;;
        int begin_day, end_day;
        string begin_month, end_month;
        char c;

        cin >> begin_month >> begin_day >> c >> begin_year;
        cin >> end_month >> end_day >> c >> end_year;
       
        int count = num229(end_year, end_month, end_day) - num229(begin_year, begin_month, begin_day);
        if(begin_month.compare("February") == 0 && begin_day == 29) count++;
 
        cout << "Case #" << i + 1 << ": " << count << endl;
    }
    return 0;
}
