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

const int MOD = 1e9 + 7;
const int MX = (int)2e5 + 5;
const ll BIG = 1e18;  //? not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  //? for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int rng_int(int L, int R) { assert(L <= R);
	return uniform_int_distribution<int>(L,R)(rng);  }
ll rng_ll(ll L, ll R) { assert(L <= R);
	return uniform_int_distribution<ll>(L,R)(rng);  }

/**
 * Author: Lucian Bicsi
 * Date: 2017-10-31
 * License: CC0
 * Source: folklore
 * Description: Zero-indexed max-tree. Bounds are inclusive to the left and exclusive to the right.
 * Can be changed by modifying T, f and unit.
 * Time: O(\log N)
 * Status: stress-tested
 */
#pragma once
struct TreeMin {
	typedef long long int T;
	static constexpr T unit = INT_MAX;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	TreeMin(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)

		//e--; // para querear [l,r] en vez de [l,r)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

struct TreeMax {
	typedef long long int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	TreeMax(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		//e--; // para querear [l,r] en vez de [l,r)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};
vs solve(vl &a,str &s,vl &queries) {
    ll n=a.size();
	TreeMax stmax(n);
	TreeMin stmin(n);
	FOR(i,0,n){
		//dbg(i,a[i]);
		stmax.update(i,a[i]);
		stmin.update(i,a[i]);
	}
	/*FOR(i,0,n){
		dbg(i,stmax.query(i,i+1),stmin.query(i,i+1));
	}*/
	set<ll> marcas;	
	map<pl,ll> bad;	
	ll last=-1;		
	FOR(i,0,n){
		if(i==n-1){
			ll l=last + 1 , r = i;
			ll mini = stmin.query(l,r+1);
			ll maxi = stmax.query(l,r+1);
			//dbg(i,l,r,mini,maxi);
			if((l+1)!= mini || (r+1)!=maxi){
				bad[{l,r}]++;
			}
			marcas.insert(i);
			last=i;
		}
		else if((s[i]=='L' && s[i+1]=='R')){
			//dbg("que fue",i,s[i],s[i+1]);
			ll l=last + 1 , r = i;
			ll mini = stmin.query(l,r+1);
			ll maxi = stmax.query(l,r+1);
			//dbg(i,l,r,mini,maxi);
			if((l+1)!= mini || (r+1)!=maxi){
				bad[{l,r}]++;
			}
			marcas.insert(i);
			last=i;
		}
	}
	/*dbg("antes de queries");
	dbg(marcas,bad);*/
	vs ans;
	each(e,queries){
		dbg("estado actual",e,marcas);
		//ver si se mergean !LR LR!
		if((e+1<n && s[e]=='L' && s[e+1]=='R')){
			//dbg("merge algo paso",marcas);
			auto idx=marcas.lower_bound(e);
			ll r2=n-1;
			if(idx != marcas.end() && next(idx)!=marcas.end()){
				r2=*next((idx));
			}
			ll l1=0;
			if(idx!=marcas.begin()){
				l1=*(prev(idx))+1;
			}
			ll r1=e,l2=e+1;
			dbg("limites merge",l1,r1,l2,r2);
			if(bad.count({l1,r1})){
				bad.erase({l1,r1});
			}
			if(bad.count({l2,r2})){
				bad.erase({l2,r2});
			}
			bool ok=true;
			ll mini1=stmin.query(l1,r2+1);
			ll maxi1=stmax.query(l1,r2+1);
			if((l1+1)!=mini1 || (r2+1)!=maxi1){
				ok=false;
			}
			if(!ok){
				bad[{l1,r2}]++;
			}
			marcas.erase(e);
		}
		if((e-1>=0 && s[e]=='R' && s[e-1]=='L')){
			//dbg("merge algo paso",marcas);
			auto idx=marcas.lower_bound(e-1);
			ll r2=n-1;
			if(idx != marcas.end() && next(idx)!=marcas.end()){
				r2=*next((idx));
			}
			ll l1=0;
			if(idx!=marcas.begin()){
				l1=*(prev(idx))+1;
			}
			ll r1=e-1,l2=e;
			dbg("limites merge",l1,r1,l2,r2);
			if(bad.count({l1,r1})){
				bad.erase({l1,r1});
			}
			if(bad.count({l2,r2})){
				bad.erase({l2,r2});
			}
			bool ok=true;
			ll mini1=stmin.query(l1,r2+1);
			ll maxi1=stmax.query(l1,r2+1);
			if((l1+1)!=mini1 || (r2+1)!=maxi1){
				ok=false;
			}
			if(!ok){
				bad[{l1,r2}]++;
			}
			marcas.erase(e-1);
		}
		dbg("antes de ver las particiones",marcas,bad);
		//ver si se crean !RR LL!
		if((e+1<n && s[e]=='R' && s[e+1]=='R')){
			auto idx=marcas.lower_bound(e);
			ll r2=n-1;
			if(idx!=marcas.end()){
				r2=*idx;
			}
			ll l1=0;
			if(idx!=marcas.begin()){
				l1=*(prev(idx))+1;
			}
			ll r1=e,l2=e+1;
			dbg("limites rompedor",l1,r1,l2,r2);
			if(bad.count({l1,r2})){
				bad.erase({l1,r2});
			}
			ll mini1=stmin.query(l1,r1+1);
			ll maxi1=stmax.query(l1,r1+1);
			if((l1+1)!=mini1 || (r1+1)!=maxi1){
				bad[{l1,r1}]++;
			}
			ll mini2=stmin.query(l2,r2+1);
			ll maxi2=stmax.query(l2,r2+1);
			if((l2+1)!=mini2 || (r2+1)!=maxi2){
				bad[{l2,r2}]++;
			}
			marcas.insert(e);	
		}
		if((e-1>=0 && s[e]=='L' && s[e-1]=='L')){
			auto idx=marcas.lower_bound(e-1);
			ll r2=n-1;
			if(idx!=marcas.end()){
				r2=*idx;
			}
			ll l1=0;
			if(idx!=marcas.begin()){
				l1=*(prev(idx))+1;
			}
			ll r1=e-1,l2=e;
			dbg("limites rompedor",l1,r1,l2,r2);
			if(bad.count({l1,r2})){
				bad.erase({l1,r2});
			}
			ll mini1=stmin.query(l1,r1+1);
			ll maxi1=stmax.query(l1,r1+1);
			if((l1+1)!=mini1 || (r1+1)!=maxi1){
				bad[{l1,r1}]++;
			}
			ll mini2=stmin.query(l2,r2+1);
			ll maxi2=stmax.query(l2,r2+1);
			if((l2+1)!=mini2 || (r2+1)!=maxi2){
				bad[{l2,r2}]++;
			}
			marcas.insert(e-1);
		}

		
		dbg("query acutal",bad);
		if(bad.empty()){
			ans.pb("YES");
		}
		else{
			ans.pb("NO");
		}
		s[e]=s[e]=='L'?'R':'L';
	}
	return ans;
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
		ll n,q;
		cin>>n>>q;
		vl a(n);
		each(e,a) cin>>e;
		str s;
		cin>>s;
		vl queries(q);
		each(e,queries){
			cin>>e;
			e--;
		}  
        auto x = solve(a,s,queries);
		each(e,x) cout<<e<<"\n";
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