#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
int dp[MAXN][MAXN];

int main() {
    int n;
    cin>>n;
    for(int it=0;it<n;it++){
        string s;
        cin >> s;
        int n = s.length();
        memset(dp, 0, sizeof(dp));
        for (int len = 1; len < n; len++) {
            for (int i = 0; i + len < n; i++) {
                int j = i + len;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1];
                } else {
                    dp[i][j] = min({ dp[i+1][j-1] + 1, dp[i+1][j] + 1, dp[i][j-1] + 1 });
                }
            }
        }
        cout <<"Prueba "<<it+1<<": "<<dp[0][n-1] << endl;
    }


    return 0;
}



