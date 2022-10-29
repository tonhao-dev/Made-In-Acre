// 2021-2022 ACM-ICPC Latin American Regional Programming Contest
// https://codeforces.com/gym/103640/problem/I
// I. Invested Money
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define MAX_DAYS 1000000005
#define DAYS_PER_WEEK 7
#define debug(message, x) cout << message << ": " << x << endl

#define lld long long int

using namespace std;

enum WeekDays { Sun = 0,
                Mon,
                Tue,
                Wed,
                Thu,
                Fri,
                Sat };

WeekDays to_week_day(string day) {
    if (day == "Mon") return WeekDays::Mon;
    if (day == "Tue") return WeekDays::Tue;
    if (day == "Wed") return WeekDays::Wed;
    if (day == "Thu") return WeekDays::Thu;
    if (day == "Fri") return WeekDays::Fri;
    if (day == "Sat") return WeekDays::Sat;

    return WeekDays::Sun;
}

WeekDays get_week_day(WeekDays today, lld days) {
    int steps_week_day = (days % DAYS_PER_WEEK);
    int week_day_in_future = (steps_week_day + today) % 7;

    return (WeekDays)week_day_in_future;
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    string today;
    int num_deposits;

    lld resp = MAX_DAYS;

    cin >> today >> num_deposits;

    for (int i = 0; i < num_deposits; i++) {
        lld day, days_to_withdrawal;
        WeekDays week_day_future;

        cin >> day;

        days_to_withdrawal = 30 - day;

        if (days_to_withdrawal < 0) {
            week_day_future = to_week_day(today);
            days_to_withdrawal = day;
        } else {
            week_day_future = get_week_day(to_week_day(today), days_to_withdrawal);
        }

        days_to_withdrawal = week_day_future == WeekDays::Sat ? days_to_withdrawal + 2 : week_day_future == WeekDays::Sun ? days_to_withdrawal + 1
                                                                                                                          : days_to_withdrawal;
        resp = min(resp, days_to_withdrawal);
    }

    cout << resp << endl;

    return 0;
}
