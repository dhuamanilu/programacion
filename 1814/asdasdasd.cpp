#include <bits/stdc++.h>
//https://codeforces.com/contest/1809/submission/198764545
using i64 = long long;
const int N=1000+3;

void solve() {
    int n, k;
    std::cin >> n >> k;

    int x = 0;
    while ((x + 1) * (x + 2) / 2 <= k) {
        x += 1;
    }

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        if (i < x) {
            a[i] = 2;
        } else if (i == x) {
            a[i] = -2 * x - 1 + 2 * (k - x * (x + 1) / 2);
        } else {
            a[i] = -1000;
        }
        std::cout << a[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
