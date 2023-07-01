#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> a;
    vector<ll> b;
    for(int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;

        a.push_back(tmp);
        b.push_back(tmp);
    }

    sort(b.begin(), b.end());

    map<ll, int> minIndexes;
    for(int i = 0; i < n; i++) {
        if(minIndexes.count(b[i]) == 0) {
            minIndexes[b[i]] = i;
        }
    }

    ll amountHours = -1;
    for(int i = n - 1; i >= 0; i--) {
        if(i > minIndexes[a[i]]) {
            amountHours = max(amountHours, (ll) ceil(((double) (i - minIndexes[a[i]])) / ((double) (k - 1))));
        }
    }

    cout << amountHours << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
