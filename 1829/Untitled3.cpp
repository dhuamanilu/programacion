#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

int dp[MAXN][MAXN];

int solve(string s) {
    int n = s.length();
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i+1][j-1];
            } else {
                dp[i][j] = min(dp[i+1][j], min(dp[i][j-1], dp[i+1][j-1])) + 1;
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        string s;
        cin >> s;
        memset(dp, 0, sizeof(dp));
        int ans = solve(s);
        cout << "Prueba " << k << ": " << ans << endl;
    }
    return 0;
}

