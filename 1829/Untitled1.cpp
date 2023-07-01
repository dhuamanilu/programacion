#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#define endl '\n'
using namespace std;

const int MAXN = 5005;

int n, a[MAXN], dp[MAXN][MAXN];

void compute_dp() {
    for (int i = 0; i < n; i++) {
        dp[i][i] = a[i];
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = min(dp[i][j-1], a[j]);
        }
    }
}

int compute_beauty(int left, int right, unordered_map<int, int>& memo) {
    if (memo.count(left*n + right)) {
        return memo[left*n + right];
    }
    if (left == right) {
        return 0;
    }
    int beauty = INT_MAX;
    for (int k = left; k < right; k++) {
        int left_beauty = compute_beauty(left, k, memo);
        int right_beauty = compute_beauty(k+1, right, memo);
        beauty = min(beauty, left_beauty + right_beauty + dp[left][k] + dp[k+1][right]);
    }
    memo[left*n + right] = beauty;
    return beauty;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        compute_dp();
        unordered_map<int, int> memo;
        int total_beauty = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                total_beauty += compute_beauty(i, j, memo);
            }
        }
        cout << total_beauty << endl;
    }
    return 0;
}


