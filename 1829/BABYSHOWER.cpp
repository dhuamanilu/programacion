#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1005;
int dp[MAXN][MAXN];

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        string s;
        cin >> s;
        int n = s.length();
        memset(dp, 0, sizeof(dp));
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n-len+1; i++) {
                int j = i+len-1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1];
                } else {
                    dp[i][j] = min(dp[i+1][j], min(dp[i][j-1], dp[i+1][j-1])) + 1;
                }
            }
        }
        cout << "Prueba "<< t << ": " << dp[0][n-1] << endl;
    }
    return 0;
}
