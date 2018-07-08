#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int makeAnagram(string a, string b) {
    int count = 0;
    int a_arr [26] = {};
    int b_arr [26] = {};
    // cout << a_arr[0] << endl;

    for (int i = 0; i < a.length(); i++) {
        a_arr[a[i]-97]++;
    }
    for (int i = 0; i < b.length(); i++) {
        b_arr[b[i]-97]++;
    }

    for (int i = 0; i < 26; i++) {
        if(a_arr[i] - b_arr[i] == 0) {
            continue;
        } else {
            count += abs(a_arr[i] - b_arr[i]);
        }
    }

    return count;
}


int main() {
    // string s = "abs";
    // cout << int(s[1]) - 97 << "\n";

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    cout << res << "\n";

    return 0;
}
