#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 5000;
bool dp[MAX_N+1];

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> c(n);
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }

        // initialize the dp array
        fill(dp, dp+MAX_N+1, false);
        dp[0] = true;

        // update the dp array
        for (int i = 0; i < n; i++) {
            for (int j = MAX_N-c[i]; j >= 0; j--) {
                if (dp[j]) {
                    dp[j+c[i]] = true;
                }
            }
        }

        // check if the final array can be obtained from the initial array
        bool found = true;
        for (int i = 0; i < n; i++) {
            if (!dp[c[i]]) {
                found = false;
                break;
            }
        }

        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
