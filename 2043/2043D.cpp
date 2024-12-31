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
	
using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}
pl brute(ll l,ll r,ll g){
    pl ans={-1,-1};
    for(ll i=l;i<=r;i++){
		if(i%g!=0){
			continue;
		}
        for(ll j=r;j>=i;j--){
			if(j%g!=0) continue;
            if(__gcd(i,j)==g){
                ll distAns=(ans.s-ans.f);
    	        ll distAct=(j-i);
    	        if(distAct > distAns || (ans.f==-1 && ans.s==-1)){
    	            ans=mp(i,j);
    	        }
    	        break;
            }
        }
    }
    return ans;
}
pl solve(ll l,ll r,ll g) {
    pl ans={-1,-1};
	ll L1=cdiv(l,g),R1=fdiv(r,g);
	if(L1==R1){
		if(L1==1){
			return mp(L1*g,R1*g);
		}
		else return mp(-1,-1);
	} 
	for(ll i=L1;i<=R1;i++){
	    if(MillerRabin(i) && __gcd(i,R1)==1){
	        ll distAns=(ans.s-ans.f);
	        ll distAct=g*(R1-i);
	        if(distAct > distAns){
	            //cout<<"primer if mas grande"<<i<<" "<<R1<<"\n";
	            ans=mp(g*(i),g*(R1));
	        }
			if(g==1616){dbg("ultimo",i,R1);}
	        break;
	    }
	    else{
	        for(ll j=R1;j>=i;j--){
	            if(__gcd(i,j)==1 || MillerRabin(j)){
	                ll distAns=(ans.s-ans.f);
        	        ll distAct=g*(j-i);
        	        if(distAct > distAns){
        	            //cout<<"segundo if "<<i<<" "<<j<<"\n";
        	            ans=mp(g*(i),g*(j));
        	        }
        	        break;
	            }
	        }
	    }
	}
	//cout<<"----------\n";
	return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    
    cin >> t;
	const int N=10000000000;
	while(1){
        ll l=rng_ll(1,N);
        ll r=rng_ll(l,N);
        ll g=rng_ll(1,N);
        auto xd1=brute(l,r,g);
        auto xd2=solve(l,r,g);
        if(xd1!=xd2){
        	dbg("algo esta mal ",xd1,xd2,xd2.s-xd2.f,xd1.s-xd1.f);
        	dbg(l,r,g,__gcd(xd1.f,xd1.s),__gcd(xd2.f,xd2.s));
            assert(false);
        }
        else dbg("ok");
		/*FOR(i,1,1000){
			FOR(j,i,1000){
				FOR(g,1,1000){
					auto xd1=brute(i,j,g);
					auto xd2=solve(i,j,g);
					if(xd1!=xd2){
						dbg("algo esta mal ",xd1,xd2);
						dbg(i,j,g);
						assert(false);
					}
					else dbg("ok");
				}
			}
		}*/
    }
    for(int idx = 0; idx < t; idx++) {
        RAYA;
        RAYA;
		ll l,r,g;
		cin>>l>>r>>g;
		auto x=solve(l,r,g);
		cout<<x.f<<" "<<x.s<<"\n";
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