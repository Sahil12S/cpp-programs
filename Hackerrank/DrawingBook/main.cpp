#include <iostream>
#include <limits>

using namespace std;

/*
 * Complete the pageCount function below.
 *//*
int pageCount(int n, int p) {
    int start = 1, end = n + 1;
    int update = 1;
    int remain = 1;
    int page_turns = 0;

    if(n / p < 2) {
        start = n;
        end = 0;
        update *= -1;
        remain = 0;
    }

    for(; start != end; start += update, page_turns++) {
        // cout << "turn num: " << page_turns << endl;
        // cout << "start: " << start << endl;
        if(start == p) break;
        if(start % 2 == remain) continue;
        else {
            start += update;
            if (start == p) break;
        }
    }
    return page_turns;

}
*/

int pageCount(int n, int p) {
    int total = n/2;
    int right = p/2;
    int left = total - right;

    if(right < left) return right;
    else return left;
}


int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);
    // int result = 0;

    cout << result << "\n";



    return 0;
}
