#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int sum = 0;
    bool isValley = false;
    int valleyCount = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == 'U') sum += 1;
        else if(s[i] == 'D') sum -= 1;

        if (sum < 0 && !isValley) {
            isValley = true;
            valleyCount++;
        }
        else if(sum >= 0 && isValley) {
            isValley = false;
        }
    }
    return valleyCount;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    cout << result << "\n";

    return 0;
}
