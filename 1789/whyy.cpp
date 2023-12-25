#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <iomanip>
#include <random>
#include <cstdlib>
#include <queue>
#include <stack>
#include <utility>
#include <bitset>
#include <string>
#include <deque>
#include <algorithm>
#include <numeric>
 
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
 
const int INF = 1e9, MOD = 1e9 + 7;
const string yes = "YES\n", no = "NO\n";
 
mt19937 rnd(time(0));
 
istream& operator>>(istream& in, vi& v) {
    for (int& i : v) {
        in >> i;
    }
    return in;
}
 
ostream& operator<<(ostream& out, const vi& v) {
    for (int i : v) {
        out << i << ' ';
    }
    return out;
}
 
istream& operator>>(istream& in, vll& v) {
    for (ll& i : v) {
        in >> i;
    }
    return in;
}
 
ostream& operator<<(ostream& out, const vll& v) {
    for (ll i : v) {
        out << i << ' ';
    }
    return out;
}
 
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
 
ll c2(int n) {
    return n * 1LL * (n - 1) / 2;
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n), k(n + m + 1, 0), prev(n + m + 1, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        prev[a[i]] = 0;
    }
    vi p(m), v(m);
    for (int i = 0; i < m; ++i) {
        cin >> p[i] >> v[i];
        --p[i];
        k[a[p[i]]] += i + 1 - prev[a[p[i]]];
        a[p[i]] = v[i];
        prev[v[i]] = i + 1;
    }
    for (int i : a) {
        k[i] += m + 1 - prev[i];
    }
    cout<<a<<"\n";
 	cout<<k<<"\n"<<prev<<"\n";
    ll res = c2(m + 1) * (n + m);
    for (int i = 1; i <= n + m; ++i) {
        res -= c2(m + 1 - k[i]);
    }
    cout << res << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
    for (; t; --t) {
        solve();
    }
 
    return 0;
}








