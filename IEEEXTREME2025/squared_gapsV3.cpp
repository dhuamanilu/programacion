//#pragma GCC optimize ("Ofast")
//? #pragma GCC target ("avx,avx2")
//#pragma GCC optimize ("trapv")
//#undef _GLIBCXX_DEBUG //? for Stress Testing
#include <bits/stdc++.h>
using namespace std;

//* Debugger
string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(char c) {
    return string(1, c);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A>
string to_string(A v);

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "[";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "]";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define MACRO(code) do {code} while (false)
#define dbg(x)      {auto xd = x; cout << "Line(" << __LINE__ << "): " << "\033[1;34m" << #x << "\033[0;32m = \033[35m" << to_string(xd) << "\033[0m" << endl;}
#define dbg(...)    MACRO(cout << "Line(" << __LINE__ << "): " << "\033[1;34m" << "[" << #__VA_ARGS__ << "]\033[35m:"; debug_out(__VA_ARGS__); cout << "\033[0m";)

#define GA          dbg(0)
#define RAYA        cout << "\033[101m" << "================================" << "\033[0m" << endl;
#else
#define dbg(x)
#define dbg(...)
#define GA
#define RAYA
#endif
//* /Debugger

using ll = long long;
using db = long double; // or double if tight TL
using str = string;

using pi = pair<int,int>;
using pl = pair<ll, ll>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T,SZ>;
using vi = V<int>;
using vl = V<ll>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MOD = 1e9+7;
const db PI = acos((db)-1);
mt19937 rng(0); // or mt19937_64
//* mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; } // set a = max(a,b)

void setIn(string s) { freopen(s.c_str(), "r", stdin); }
//? /Custom Helpers
//? Generator
int rng_int(int L, int R) { assert(L <= R);
	return uniform_int_distribution<int>(L,R)(rng);  }
ll rng_ll(ll L, ll R) { assert(L <= R);
	return uniform_int_distribution<ll>(L,R)(rng);  }
/**
 * Author: Simon Lindholm
 * Date: 2017-04-20
 * License: CC0
 * Source: https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h
 * 
 * Description: Container where you can add lines of the form kx+m, and query maximum values at points x.
 *  Useful for dynamic programming (``convex hull trick'').
 * Time: O(\log N)
 * Status: stress-tested
 */
#pragma once

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
void solve(){
    ll n;
    cin>>n;
    string a;
    cin>>a;

    ll m;
    cin>>m;
    string b;
    cin>>b;

    ll match,mismatch,gap;
    cin>>match>>mismatch>>gap;  

    const ll INF = 1e18;
    vl align_prev(m+1,-INF) , align_cur(m+1,-INF);
    vl maxi_prev(m+1,-INF) , maxi_cur(m+1,-INF);
    
    V<LineContainer> colCHT(m+1);
    align_prev[0] = 0; //D PREV
    maxi_prev[0] = 0; //S PREV

    LineContainer rowCHT;
    rowCHT.add(0, align_prev[0]);

    for (ll j = 1; j <= m; j++) {
        ll H = gap *j * j + rowCHT.query(j);
        maxi_prev[j] = max({-INF, H, -INF});
    }
    colCHT[0].add(0, align_prev[0]);

    for (ll i = 1; i <= n; i++) {
        rowCHT = LineContainer();
        ll V0 = -INF;
        if (!colCHT[0].empty()) V0 = gap * i * i + colCHT[0].query(i);
        maxi_cur[0] = max({-INF, -INF, V0});
        align_cur[0] = -INF;

        for (ll j = 1; j <= m; j++) {
           
            if (align_cur[j - 1] > -INF / 2) {
                ll t = j - 1;
                ll k = -2 * gap * t;
                ll mm = align_cur[t] + gap * t * t;
                rowCHT.add(k, mm);
            }
            
            auto score = [&](char x, char y) -> long long {
                return (x == y) ? match : mismatch;
            };
            ll sc = score(a[i - 1], b[j - 1]);
            ll Dv = (maxi_prev[j - 1] <= -INF / 2) ? -INF : (maxi_prev[j - 1] + sc);
            align_cur[j] = Dv;

            ll H = -INF;
            if (!rowCHT.empty()) H = gap * j * j + rowCHT.query(j);

            ll V = -INF;
            if (!colCHT[j].empty()) V = gap * i * i + colCHT[j].query(i);

            maxi_cur[j] = max({Dv, H, V});
        }

        for (ll j = 0; j <= m; j++) {
            if (align_cur[j] > -INF / 2) {
                ll t = i;
                ll k = -2 * gap * t;
                ll mm = align_cur[j] + gap * t * t;
                colCHT[j].add(k, mm);
            }
        }

        align_prev.swap(align_cur);
        maxi_prev.swap(maxi_cur);
        fill(all(align_cur), -INF);
        fill(all(maxi_cur), -INF);
    }
    cout << maxi_prev[m] << "\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    //cin>>t;
    while(t--) solve();
}