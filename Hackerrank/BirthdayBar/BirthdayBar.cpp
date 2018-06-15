/**
 * Date: June 11, 2018
 * Solved by: SAHIL SHARMA
 * Link: https://www.hackerrank.com/challenges/the-birthday-bar/problem
 */

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
int solve(vector<int> s, int d, int m) {
    int day;
    int month = 0;
    int count = 0;
    for(int i = 0; i < s.size(); i++) {
        day = s[i];
        month = 1;
        for(int j = i+1; month <= m && j < s.size(); j++, month++) {
            if(day == d && month == m) {
                count++;
                break;
            }
            if(j <= s.size()) day += s[j];
            if(day > d) break;
        }
    }
    return count;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split_string(s_temp_temp);

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    string dm_temp;
    getline(cin, dm_temp);

    vector<string> dm = split_string(dm_temp);

    int d = stoi(dm[0]);

    int m = stoi(dm[1]);

    int result = solve(s, d, m);

    cout << result << "\n";

    // fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
