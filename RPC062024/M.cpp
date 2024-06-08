#pragma GCC optimize(3,"Ofast","inline")
 
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debugICPC.h"
#define chk(...) if (!(__VA_ARGS__)) cerr << "\033[41m" << "Line(" << __LINE__ << ") -> function(" \
	 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\033[0m" << "\n", exit(0);

#define MACRO(code) do {code} while (false)
#define RAYA MACRO(cerr << "\033[101m" << "================================" << "\033[0m" << endl;)
#else
#define dbg(...)

#define chk(...)
#define RAYA
#endif
 
#define tcT template<class T
 
using ll = long long;
using ld = long double;       // or double if tight TL
using str = string;         // yay python!
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T, SZ>;
 
#define mp  make_pair
#define F   first
#define S   second
 
#define sz(x)   int((x).size())
#define bg(x)   begin(x)
#define all(x)  bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x)  sort(all(x))
#define rsz     resize
#define ins     insert
#define pb      push_back
#define eb      emplace_back
#define ft      front()
#define bk      back()
 
#define lb lower_bound
#define ub upper_bound
 
const int MOD = (int)1e9 + 7;   // 998244353;
const ld PI = acos((ld)-1);
mt19937 rng(0); // or mt19937_64
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  // for every grid problem!!
const char n_l = '\n';
 
template <typename T>
ostream& operator <<(ostream &os, const vector<T>& v) {
    os << "[";
 
    for(int i = 0; i < sz(v); i++) {
        if (i > 0) os << " ";
        os << v[i];
    }
    return os << "]";
}
 
const long double EPS = (long double)(1e-9);
 
bool eq(double A, double B) {
    return A - B < EPS;
}
 
using db = long double;
void solve() {
    long double l, r; cin >> l >> r;
    dbg(l, r);

    auto rd = [&](db x) {
        return (x * PI) / db(180);
    };

    auto ff = [&](double x) {
        return (
            db(2) * l * l * (l * cos(x - rd(180)) + r) * sin(x - rd(180)) * sin(x - rd(180))
            - r * r * r * (db(1) / cos(x - rd(180))) * (db(1) / cos(x - rd(180)))
            - l * cos(x - rd(180)) * (l * cos(x - rd(180) + r)) * (l * cos(x - rd(180) + r))
        );
    };
 
    auto check = [&](double x) {
        return ff(x) < 0.0;
    };
 
        // Bolzano's Theorem
        if(true) {
            double l_real = 0.0, r_real = PI - EPS;
            long long l = reinterpret_cast<long long&>(l_real);
            long long r = reinterpret_cast<long long&>(r_real);
            while (l < r) {
                long long mid = l + (r - l) / 2;
                if (check(reinterpret_cast<double&>(mid)))
                    r = mid;
                else
                    l = mid + 1;
            }
 
            double ans = reinterpret_cast<double&>(l);
            cout << ans << n_l;
        }
}
 
int main() {
    cout << fixed << setprecision(12);
 
    int t; cin >> t; dbg(t);
    for(int i = 0; i < t; i++) { 
        solve();
    }

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    return 0;
}