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
//* Template
/**
 * Description: Barrett reduction computes $a \% b$ about 4 times faster than usual
 	* where $b>1$ is constant but not known at compile time. Division by $b$ is replaced
 	* by multiplication by $m$ and shifting right 64 bits.
 * Source: KACTL
 	* https://github.com/kth-competitive-programming/kactl/blob/master/content/various/FastMod.h
 	* https://en.wikipedia.org/wiki/Barrett_reduction
 * Verification: http://www.usaco.org/index.php?page=viewproblem2&cpid=1045
 */

using ul = uint64_t; using L = __uint128_t;
struct FastMod {
	ul b, m; FastMod(ul b) : b(b), m(-1ULL / b) {}
	ul reduce(ul a) {
		ul q = (ul)((__uint128_t(m) * a) >> 64), r = a - q * b;
		return r - (r >= b) * b; }
};

/**
 * Description: modular arithmetic operations
 * Source:
	* KACTL
	* https://codeforces.com/blog/entry/63903
	* https://codeforces.com/contest/1261/submission/65632855 (tourist)
	* https://codeforces.com/contest/1264/submission/66344993 (ksun)
	* also see https://github.com/ecnerwala/cp-book/blob/master/src/modnum.hpp (ecnerwal)
	* https://github.com/atcoder/ac-library/blob/master/atcoder/modint.hpp
 * Verification:
	* https://open.kattis.com/problems/modulararithmetic
 */

template<int id> struct mint {
	static FastMod MF;
	static int mod() { return (int)MF.b; }
	static void set_mod(int m) { assert(1 <= m); MF = FastMod(m); }
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	mint() { v = 0; }
	mint(ll _v) { v = int((-mod() < _v && _v < mod()) ? _v : _v % mod());
		if (v < 0) v += mod(); }
	friend bool operator==(const mint& a, const mint& b) {
		return a.v == b.v; }
	friend bool operator!=(const mint& a, const mint& b) {
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) {
		return a.v < b.v; }
	//friend void re(mint& a) { ll x; re(x); a = mint(x); }
	//friend str ts(mint a) { return ts(a.v); }
    friend ostream &operator<<(ostream &os, mint a) {
		os << ts(a);
		return os;
	}

	mint& operator+=(const mint& m) {
		if ((v += m.v) >= mod()) v -= mod();
		return *this; }
	mint& operator-=(const mint& m) {
		if ((v -= m.v) < 0) v += mod();
		return *this; }
	mint& operator*=(const mint& m) {
		v = (int)MF.reduce((ll)v*m.v); return *this; }
	mint& operator/=(const mint& m) { return (*this) *= inv(m); }
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0);
		return pow(a,mod()-2); }

	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};
template<int id> FastMod mint<id>::MF = FastMod(1);

typedef mint<0> mi; // 5 is primitive root for both common mods
typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;

vector<vmi> scmb; // small combinations
void genComb(int SZ) {
	scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
	FOR(i,1,SZ) F0R(j,i+1)
		scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}
void solve(){
    ll aT,bT,pT,x1T,y1T,x2T,y2T;
    cin>>aT>>bT>>pT>>x1T>>y1T>>x2T>>y2T;
    //mi::set_mod(xd)
    mi::set_mod(pT);
    mi a = aT , b = bT , x1 = x1T , y1 = y1T , x2 = x2T , y2 = y2T;
    if(x1 == x2 && (y1 + y2) == mi(0)){
        cout << "POINT_AT_INFINITY\n";
        return;
    }

    mi pend ,guardaNum,guardaDen;
    if(x1 == x2 && y1 == y2){
        mi num = (mi(3) * x1 * x1) + a;
        mi den = mi(2) * y1;
        if(den == mi(0)){
            cout << "POINT_AT_INFINITY\n";
            return;
        }
        guardaNum = num;
        guardaDen = den;
    }
    else{
        //SON DISTINTOS
        mi num = y2 - y1;
        mi den = x2 - x1;
        if(den == mi(0)){
            cout << "POINT_AT_INFINITY\n";
            return;
        }
        guardaNum = num;
        guardaDen = den;
    }
    pend = guardaNum * inv(guardaDen);
    mi x3 = (pend * pend) - (x1 + x2);
    mi y3 = (pend * (x1 - x3)) - y1;
    cout<<x3.v<<" "<<y3.v<<"\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    cin>>t;
    while(t--) solve();
}