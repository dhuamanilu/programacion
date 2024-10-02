//? #pragma GCC optimize ("Ofast")
//? #pragma GCC target ("avx,avx2")
//! #pragma GCC optimize ("trapv")
//#undef _GLIBCXX_DEBUG //? for Stress Testing
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

const auto beg_time = std::chrono::high_resolution_clock::now();
// https://stackoverflow.com/questions/47980498/accurate-c-c-clock-on-a-multi-core-processor-with-auto-overclock?noredirect=1&lq=1
double time_elapsed() {
	return chrono::duration<double>(std::chrono::high_resolution_clock::now() -
	                                beg_time)
	    .count();
}

// building blocks
using ll  = long long;
using db  = long double; // or double, if TL is tight
using str = string;      // yay python!
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
#define f first
#define s second

#define tcT template <class T
#define tcTU tcT, class U
//! ^ lol this makes everything look weird but I'll try it
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



// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)



const int MOD = 1e9+7;
const ll BIG = 1e18;  //? not too close to LLONG_MAX
const db PI = acos((db)-1);
mt19937 rng(0); // or mt19937_64



ll cdiv(ll a, ll b) {
	return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
	return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; } // set a = max(a,b)

tcT > void remDup(vector<T> &v) {  // sort and remove duplicates
	sort(all(v));
	v.erase(unique(all(v)), end(v));
}
tcTU > void safeErase(T &t, const U &u) {
	auto it = t.find(u);
	assert(it != end(t));
	t.erase(it);
}



inline namespace FileIO {
void setIn(str s) { freopen(s.c_str(), "r", stdin); }
void setOut(str s) { freopen(s.c_str(), "w", stdout); }
void setIO(str s = "") {
	cin.tie(0)->sync_with_stdio(0);  // unsync C / C++ I/O streams
	//? cout << fixed << setprecision(12);
    //? cerr << fixed << setprecision(12);
	cin.exceptions(cin.failbit);
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) setIn(s + ".in"), setOut(s + ".out");  // for old USACO
}
}  // namespace FileIO



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
//? /Custom Helpers
//? Generator
int rng_int(int L, int R) { assert(L <= R);
	return uniform_int_distribution<int>(L,R)(rng);  }
ll rng_ll(ll L, ll R) { assert(L <= R);
	return uniform_int_distribution<ll>(L,R)(rng);  }
//? /Generator

vl solve(vl &a,ll limit,ll k) {
	ll n=a.size();
	vpl b(n);
	FOR(i,0,n){
		b[i]={a[i],i};
	}
	sort(all(b));
	vl c(n);
	FOR(i,0,n){
		c[i] = b[i].f; 
	}
	ll sum=0;
	each(e,b){
		sum+=e.f;
	}
	vl ans(n,0);
	vl pref(n,0);
	pref[0]=b[0].f;
	FOR(i,1,n){
		pref[i]=pref[i-1]+b[i].f;
	}
	auto query=[&](ll l,ll r){
		if(l==0) return pref[r];
		return pref[r]-pref[l-1];
	};
	auto bb=[&](ll s ,ll r,ll votoAct,ll quedan)->ll{
		dbg("rangos",s,r+1,votoAct);
		long long x = upper_bound(c.begin()+s,c.begin()+r+1,votoAct)-c.begin();
		ll e=x-1,m=s+(e-s)/2,offset=r-x+1,guarda=-offset;
		while(s<=e){
			
			m=s+(e-s)/2;
			ll len=x - m;
			ll act=len*(votoAct+1) - query(m,x-1);
			dbg("gaa estoy en la bb interna",s,e,m,act,quedan);
			if(act<=quedan){

				
				guarda=len;
				dbg("GA34",guarda);
				e=m-1;
			}
			else s=m+1;
		}
		return guarda + offset;
	};
	FOR(i,0,n){
		ll s=0,e=k-sum,m=s+(e-s)/2,guarda=-1;
		while(s<=e){
			m=s+(e-s)/2;
			ll votoAct=b[i].f+m;
			ll quedan=k-sum-m;
			dbg("it",s,e,m,votoAct,quedan);
			ll sumR=0;
			ll act=0;
			auto x = n;
			if(i+1<n){
				x = upper_bound(c.begin()+i+1,c.end(),votoAct)-c.begin();
				//desde i + 1 hasta x - 1
				ll len=x-1-i;
				if(len>0){
					sumR+=len*(votoAct+1) - query(i+1,x-1);
				}
			}
			if(quedan >= sumR){
				
				ll xd=quedan;
				xd-=sumR;
				dbg("ME PERMTIO COMPRAR TODO RIGHT",s,e,m,quedan,xd,sumR);
				act+=n-1-i;
				//buscar desde 0 hasta i-1
				dbg("limites caso 1 comi todo sumr",0,i-1,votoAct,xd);
				ll var=bb(0,i-1,votoAct,xd);
				act+=var;
				dbg(act,var);
			}
			else{
				
				//buscar desde i+1 hasta x-1
				dbg("NO ME PERMTIO COMPRAR TODO RIGHT");
				if(i>=1){
					act+=bb(0,i-1,votoAct,0);
				}
				act+=n-x;
				dbg(x,s,e,m,quedan,act);
				act+=bb(i+1,x-1,votoAct,quedan);
				dbg("act despues de ver cuantos me ganan",act);
			}

			if(act < limit){
				guarda=m;
				e=m-1;
			}
			else s=m+1;
		}
		ans[b[i].s]=guarda;
		RAYA;
		RAYA;
	}
	return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    //cin >> t;

    for(int idx = 0; idx < t; idx++) {
        RAYA;
        RAYA;
		ll n,m,k;
		cin>>n>>m>>k;
		vl a(n);
		each(e,a) cin>>e;
        auto x = solve(a,m,k);
		each(e,x) cout<<e<<" ";
		cout<<"\n";
    }
    RAYA;
    RAYA;

    #ifdef LOCAL
        cerr << fixed << setprecision(5);
        cerr << "\033[42m++++++++++++++++++++\033[0m\n";
        cerr << "\033[42mtime = " << time_elapsed() << "ms\033[0m\n";
        cerr << "\033[42m++++++++++++++++++++\033[0m";
    #endif
}








