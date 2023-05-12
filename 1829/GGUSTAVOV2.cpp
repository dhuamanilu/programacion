#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;
using ld = long double;

ld dfs(ll k, ld pp[], ll n, ll i, ll points) {
    if(i == k) {
        if(points >= n) {
            return 1;
        } else {
            return 0;
        }
    }

    return max((pp[i]          * dfs(k, pp, n, i + 1, points + 1))
                + ((1 - pp[i]) * dfs(k, pp, n, i + 1, points - 1))
            , (pp[i + 1]          * dfs(k, pp, n, i + 1, points))
                + (1 - pp[i + 1]) * dfs(k, pp, n, i + 1, points));
}

void solve() {
    ll k, n;
    cin >> k >> n;

    ld pp[k];

    for(int i = 0; i < k; i++) {
        cin >> pp[i];
    }

    cout << dfs(k, pp, n, 0, 0) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
