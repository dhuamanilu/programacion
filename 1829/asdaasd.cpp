#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int h, w, t, si, sj, gi, gj;
char a[305][305];
int candy[20][2];
int candy_count = 0;
int dp[1 << 18][305][305];

int dfs(int bitmask, int i, int j) {
    if (dp[bitmask][i][j] != -1) {
        return dp[bitmask][i][j];
    }
    if (bitmask == (1 << candy_count) - 1) {
        return dp[bitmask][i][j] = abs(i - gi) + abs(j - gj);
    }
    int res = INF;
    for (int k = 0; k < candy_count; k++) {
        if ((bitmask & (1 << k)) == 0) {
            int ci = candy[k][0], cj = candy[k][1];
            if (dp[bitmask | (1 << k)][ci][cj] == -1) {
                dp[bitmask | (1 << k)][ci][cj] = dfs(bitmask | (1 << k), ci, cj);
            }
            res = min(res, abs(i - ci) + abs(j - cj) + dp[bitmask | (1 << k)][ci][cj]);
        }
    }
    return dp[bitmask][i][j] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> h >> w >> t;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                si = i;
                sj = j;
            } else if (a[i][j] == 'G') {
                gi = i;
                gj = j;
            } else if (a[i][j] == 'o') {
                candy[candy_count][0] = i;
                candy[candy_count][1] = j;
                candy_count++;
            }
        }
    }

    memset(dp, -1, sizeof(dp));
    int ans = -1;
    for (int i = 0; i < (1 << candy_count); i++) {
        int mask_count = __builtin_popcount(i);
        if (mask_count > ans) {
            int dist = dfs(i, si, sj);
            if (dist <= t) {
                ans = mask_count;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
