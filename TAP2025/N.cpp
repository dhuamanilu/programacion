#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> dx{-1, -1,  0, +1, +1, +1,  0, -1};
vector<ll> dy{ 0, +1, +1, +1,  0, -1, -1, -1};

void solve() {
    ll n; cin >> n;
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    const ll BIG = ll(1e18) + 5;
    ll mn_x = BIG;
    ll mx_x = -BIG;
    ll mn_y = BIG;
    ll mx_y = -BIG;
    for(int i = 0; i < n; i++) {
        for(int k = 0; k < 8; k++) {
            ll nx = x[i] + dx[k];
            ll ny = y[i] + dy[k];
            mn_x = min(mn_x, nx);
            mx_x = max(mx_x, nx);
            mn_y = min(mn_y, ny);
            mx_y = max(mx_y, ny);
        }
    }
    ll re = (mx_x - mn_x) + (mx_y - mn_y);
    re *= 2LL;
    cout << re << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    solve();

    return 0;
}