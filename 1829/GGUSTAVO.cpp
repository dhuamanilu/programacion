#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;

ld it(ll k, ld pp[], ll n, ll i, ll counter) {
    if(counter == n) {
        return 1;
    } else if(i == k - 1) {
        if(counter + 1 == n) {
            return pp[i];
        } else {
            return 0;
        }
    }

    return (pp[i] * it(k, pp, n, i + 1, counter + 1)) + ((1 - pp[i]) * it(k, pp, n, i + 1, counter));
}

void solve() {
    ll k, n;
    cin >> k >> n;

    ld pp[k];

    for(int i = 0; i < k; i++) {
        cin >> pp[i];
    }

    cout << it(k, pp, n, 0, 0) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
