/* Given a time in -hour AM/PM format, convert it to military (24-hour) time.
 * Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
 * - 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    // Write your code here.
    // Approach
    // 1. If string contains AM, then return the original string without 'AM'
    //    But if time is 12:xx:xxAM, then we have to change 12 to 0
    //    and return the string without 'AM'
    // 2. If string contains PM, then we have to convert the hour
    //    By adding 12 to it, and minutes and seconds remaining the same
    //    Then return the string without 'PM'
    
    string hourString = s.substr(0, 2);
    int hour = stoi(hourString);
    size_t pos = s.find("PM");
    if (pos != string::npos){
        if (hour + 12 < 24)
            hourString = to_string(hour+12);
    }
    else{
        if (hour == 12){
            hourString = "00";
        }
    }
    s.erase(s.size()-2);
    s.replace(0, 2, hourString);
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
