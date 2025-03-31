//* sometimes pragmas don't work, if so, just comment it!
#pragma GCC optimize ("Ofast")
//? #pragma GCC target ("avx,avx2")
//! #pragma GCC optimize ("trapv")

//! #undef _GLIBCXX_DEBUG //? for Stress Testing

#include <bits/stdc++.h>
using namespace std;



#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)     0
    #define chk(...)     0

    #define RAYA         0
#endif



const auto beg_time = std::chrono::high_resolution_clock::now();
double time_elapsed() { return chrono::duration<double>(std::chrono::high_resolution_clock::now() - beg_time) .count(); }



// building blocks
using ll  = long long;
using db  = long double;
using str = string;

//? priority_queue for minimum
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

using ull  = unsigned long long;
//? using i64  = long long;
//? using u64  = uint64_t;
//? using i128 = __int128;
//? using u128 = __uint128_t;
//? using f128 = __float128;



// pairs
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;

#define mp make_pair
#define f  first
#define s  second



#define tcT template <class T
#define tcTU tcT, class U

tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;

using vvi = V<vi>;
using vvl = V<vl>;
using vvb = V<vb>;



// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()
#define ts to_string

#define lb lower_bound
#define ub upper_bound



// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)



ll cdiv(ll a, ll b) {
	return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
	return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

tcT > bool ckmin(T &a, const T &b) {
	return b < a ? a = b, 1 : 0;
}  // set a = min(a,b)
tcT > bool ckmax(T &a, const T &b) {
	return a < b ? a = b, 1 : 0;
}  // set a = max(a,b)

tcT > void remDup(vector<T> &v) {  // sort and remove duplicates
	sort(all(v));
	v.erase(unique(all(v)), end(v));
}
tcTU > void safeErase(T &t, const U &u) {
	auto it = t.find(u);
	assert(it != end(t));
	t.erase(it);
}



//? Custom Helpers
template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

//? __builtin_popcountll
ll GetBit(ll mask, ll bit) { return (mask >> bit) & 1LL; }
void TurnOn(ll& mask, ll bit) { mask = mask | (1LL << bit); }
void TurnOff(ll& mask, ll bit) { mask = mask & (~(1LL << bit)); }

const int dddx[8]{1, 0, -1,  0, 1,  1, -1, -1};
const int dddy[8]{0, 1,  0, -1, 1, -1,  1, -1};

using vvi = V<vi>;
using vvl = V<vl>;
using vvb = V<vb>;

const int MOD = 998244353;
const int MX = (int)2e5 + 5;
const ll BIG = 1e18;  //? not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  //? for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int rng_int(int L, int R) { assert(L <= R);
	return uniform_int_distribution<int>(L,R)(rng);  }
ll rng_ll(ll L, ll R) { assert(L <= R);
	return uniform_int_distribution<ll>(L,R)(rng);  }
//? /Custom Helpers

//? Template
//? /Template

/**
 * Description: modular arithmetic operations 
 * Source: 
	* KACTL
	* https://codeforces.com/blog/entry/63903
	* https://codeforces.com/contest/1261/submission/65632855 (tourist)
	* https://codeforces.com/contest/1264/submission/66344993 (ksun)
	* also see https://github.com/ecnerwala/cp-book/blob/master/src/modnum.hpp (ecnerwal)
 * Verification: 
	* https://open.kattis.com/problems/modulararithmetic
 */

 #pragma once

 template<int MOD, int RT> struct mint {
     static const int mod = MOD;
     static constexpr mint rt() { return RT; } // primitive root for FFT
     int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
     mint():v(0) {}
     mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
         if (v < 0) v += MOD; }
     bool operator==(const mint& o) const {
         return v == o.v; }
     friend bool operator!=(const mint& a, const mint& b) { 
         return !(a == b); }
     friend bool operator<(const mint& a, const mint& b) { 
         return a.v < b.v; }
     friend str ts(mint a) { return ts(a.v); }
    
     mint& operator+=(const mint& o) { 
         if ((v += o.v) >= MOD) v -= MOD; 
         return *this; }
     mint& operator-=(const mint& o) { 
         if ((v -= o.v) < 0) v += MOD; 
         return *this; }
     mint& operator*=(const mint& o) { 
         v = int((ll)v*o.v%MOD); return *this; }
     mint& operator/=(const mint& o) { return (*this) *= inv(o); }
     friend mint pow(mint a, ll p) {
         mint ans = 1; assert(p >= 0);
         for (; p; p /= 2, a *= a) if (p&1) ans *= a;
         return ans; }
     friend mint inv(const mint& a) { assert(a.v != 0); 
         return pow(a,MOD-2); }
         
     mint operator-() const { return mint(-v); }
     mint& operator++() { return *this += 1; }
     mint& operator--() { return *this -= 1; }
     friend mint operator+(mint a, const mint& b) { return a += b; }
     friend mint operator-(mint a, const mint& b) { return a -= b; }
     friend mint operator*(mint a, const mint& b) { return a *= b; }
     friend mint operator/(mint a, const mint& b) { return a /= b; }
 };
 
 using mi = mint<MOD,5>; // 5 is primitive root for both common mods
 using vmi = V<mi>;
 using pmi = pair<mi,mi>;
 using vpmi = V<pmi>;
 
 V<vmi> scmb; // small combinations
 void genComb(int SZ) {
     scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
     FOR(i,1,SZ) F0R(j,i+1) 
         scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
 }
 template<int MOD, int RT>
 std::ostream& operator<<(std::ostream &os, const mint<MOD, RT> &m) {
     return os << m.v;
 }
 
ll solve(vvl &a,ll d) {
    ll n=a.size(),m=a[0].size();
    vector<vector<vector<mi>>> dp(n,vector<vector<mi>>(m,vector<mi>(2,mi(0))));
    reverse(all(a));
    //each(e,a) reverse(all(e));
    FOR(j,0,m){
        if(a[0][j]){
            dp[0][j][0]=mi(1);
        }
    }
    //each(e,a)dbg(e);
    vector<vector<vector<mi>>> pref(n,vector<vector<mi>>(m,vector<mi>(2,mi(0))));
    pref[0][0][0]=dp[0][0][0];
    FOR(j,1,m){
        pref[0][j][0]=pref[0][j-1][0]+dp[0][j][0];
    }
    auto query=[&](ll row,ll val1,ll val2,ll k)->mi{
        if(val1==0){
            return pref[row][val2][k];
        }
        else{
            /*if(row==1 && val2==3 && val1==3 && k==0){
                dbg(pref[row][val2][k],pref[row][val1-1][k],pref[row][val2][k]-pref[row][val1-1][k]);
            }*/
            return pref[row][val2][k]-pref[row][val1-1][k];
        }
    };
    ll dcua=d*d;
    FOR(j,0,m){
        if(!a[0][j]) continue;
        ll alfa1=min((ll)j,d);
        mi contr1=alfa1>=1 ? query(0,j-alfa1,j-1,0) : mi(0);
        ll alfa2=min(d,(m-1-j));
        mi contr2=alfa2>=1 ?query(0,j+1,j+alfa2,0) : mi(0) ;
        dp[0][j][1]+= contr1 + contr2;
    }
    
    pref[0][0][1]=dp[0][0][1];
    FOR(j,1,m){
        pref[0][j][1]=pref[0][j-1][1]+dp[0][j][1];
    }
    
    FOR(i,1,n){
        FOR(j,0,m){
            if(a[i][j]){
                ll beta1=min((ll)sqrtl(dcua-1),(ll)j);
                mi contr1=query(i-1,j-beta1,j,0);
                mi contr3=query(i-1,j-beta1,j,1);
                ll beta2=min((ll)sqrtl(dcua-1),m-1-j);
                mi contr2=beta2>=1 ? query(i-1,j+1,j+beta2,0) : mi(0) ;
                mi contr4=beta2>=1 ? query(i-1,j+1,j+beta2,1) : mi(0) ;
                dp[i][j][0]+= contr1 + contr2 + contr3 + contr4;
                pref[i][j][0]+=dp[i][j][0];
            }
            if(j>0){
                pref[i][j][0]+=pref[i][j-1][0];
            } 
        }
        //dbg(pref[i]);
        FOR(j,0,m){
            if(a[i][j]){
                ll alfa1=min((ll)j,d);
                mi contr1=alfa1>=1 ? query(i,j-alfa1,j-1,0) : mi(0);
                ll alfa2=min(d,(m-1-j));
                mi contr2=alfa2>=1 ?query(i,j+1,j+alfa2,0) : mi(0) ;
                dp[i][j][1]+=contr1+contr2;
                pref[i][j][1]+=dp[i][j][1];
            }
            if(j>0){
                pref[i][j][1]+=pref[i][j-1][1];
            } 
        } 
    }
    //each(e,dp) dbg(e);
    mi res=pref[n-1][m-1][0] + pref[n-1][m-1][1];
    return res.v;
}

void setIn(str s) { freopen(s.c_str(), "r", stdin); }
void setOut(str s) { freopen(s.c_str(), "w", stdout); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    //? Stress Testing
    while(0) {
        RAYA;
    }

    int t = 1;
	cin >> t;
    for(int i = 0; i < t; i++) {
        RAYA;
        RAYA;
		ll n,m,d;
		cin>>n>>m>>d;
		vvl a(n,vl(m,0));
		each(e,a){
            each(e2,e){
                char x;
                cin>>x;
                e2=(x=='X');
            }
        }
        cout<<solve(a,d)<<"\n";
    }
    RAYA;
    RAYA;

    #ifdef LOCAL
        cerr << fixed << setprecision(5);
        cerr << "\033[42m++++++++++++++++++++\033[0m\n";
        cerr << "\033[42mtime = " << time_elapsed() << "ms\033[0m\n";
        cerr << "\033[42m++++++++++++++++++++\033[0m\n";
    #endif
}