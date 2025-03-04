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
vl brute(vl &a){
	ll n=a.size();
	set<ll> values;
	values.insert(0);
	vl pref(n,0);
	pref[0]=a[0];
	FOR(i,1,n){
		pref[i]=pref[i-1]+a[i];
	}
	auto query=[&](ll l,ll r){
		if(l==0) return pref[r];
		return pref[r]-pref[l-1];
	};
	FOR(i,0,n){
		FOR(j,i,n){
			values.insert(query(i,j));
		}
	}
	vl res;
	for(auto x:values){
		res.pb(x);
	}
	return res;
}
//https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
ll maxSubarraySum(vl &arr) {
	if(arr.empty()) return 0;
    ll res = arr[0];
    ll maxEnding = arr[0];

    for (ll i = 1; i < arr.size(); i++) {
      
        // Find the maximum sum ending at index i by either extending 
        // the maximum sum subarray ending at index i - 1 or by
        // starting a new subarray from index i
        maxEnding = max(maxEnding + arr[i], arr[i]);
      
        // Update res if maximum subarray sum ending at index i > res
        res = max(res, maxEnding);
    }
    return max(0ll,res);
}
vl solve(vl &a) {
	ll n=a.size();
	ll idx=0;
	FOR(i,0,n){
		if(a[i]!=1 && a[i]!=-1){
			idx=i;
			break;
		}
	}
	ll L1=BIG,R1=-BIG,L2=BIG,R2=-BIG,sum=0;
	for(ll i=idx-1;i>=0;i--){
		sum+=a[i];
		ckmin(L1,sum);
		ckmax(R1,sum);
	}
	sum=0;
	for(ll i=idx+1;i<n;i++){
		sum+=a[i];
		ckmin(L2,sum);
		ckmax(R2,sum);
	}
	set<ll> values;
	vl a1,a2;
	FOR(i,0,idx){
		a1.pb(a[i]);
	}
	FOR(i,idx+1,n){
		a2.pb(a[i]);
	}
	auto maxiL=maxSubarraySum(a1);
	auto maxiR=maxSubarraySum(a2);
	each(e,a1) e*=-1;
	auto miniL=-1*maxSubarraySum(a1);
	each(e,a2) e*=-1;
	auto miniR=-1*maxSubarraySum(a2);
	dbg(a1,a2,maxiL,maxiR,miniL,miniR);
	FOR(i,miniL,maxiL+1){
		values.insert(i);
	}
	FOR(i,miniR,maxiR+1){
		values.insert(i);
	}
	values.insert(0);
	values.insert(a[idx]);	
	FOR(i,L2,R2+1){
		values.insert(i);
	}
	ll Lfinal=min({L1,L2,L1+L2}),Rfinal=max({R1,R2,R1+R2});
	
	FOR(i,Lfinal,Rfinal+1){
		values.insert(a[idx] + i);
	}
	vl res;
	for(auto x:values){
		res.pb(x);
	}
	return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
	while(0){
		ll n=rng_ll(1,10);
		vl a(n);
		FOR(i,0,n-1){
			ll xd=rng_ll(1,2);
			if(xd==1) a[i]=1;
			else a[i]=-1;
		}
		a[n-1]=rng_ll(-100,100);
		auto x=brute(a);
		auto y=solve(a);
		if(x!=y){
			dbg(a,x,y);
			assert(false);
		}
		else dbg(a,"OK");
	}  
	for(int idx = 0; idx < t; idx++) {
        RAYA;
        RAYA;
		ll n;
		cin>>n;
		vl a(n);
		each(e,a)cin>>e;
		auto x = solve(a);
		cout<<x.size()<<"\n";
		each(e,x)cout<<e<<" ";
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








