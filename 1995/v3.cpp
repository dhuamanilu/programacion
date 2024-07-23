#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    vector<long double> a(n);
    for (auto &e : a) cin >> e;
    
    ll ans = 0;
    
    for (ll i = n - 2; i >= 0; --i) {
        while (a[i] > a[i + 1]) {
            // Si a[i] es 1 y a[i+1] es 0, no es posible arreglarlo
            if (a[i] == 1) {
                cout << "-1\n";
                return;
            }
            a[i] = sqrt(a[i]);  // Eleva al cuadrado
            ans++;
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}