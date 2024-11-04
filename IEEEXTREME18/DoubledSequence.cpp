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



//? Template
const int MOD = 1e9 + 7;
const int MX = (int)2e5 + 5;
const ll BIG = 1e18;  //? not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  //? for every grid problem!!
mt19937 rng(0);



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

//? Generator
int rng_int(int L, int R) { assert(L <= R);
	return uniform_int_distribution<int>(L,R)(rng);  }
ll rng_ll(ll L, ll R) { assert(L <= R);
	return uniform_int_distribution<ll>(L,R)(rng);  }
//? /Generator


//https://susam.net/langford-pairing.html
vl solve(ll n) {
	if(n==0){
		vl xd;
		return xd;
	}
	if(n%4==1 || n%4==2){
		vl xd={-1};	
		return xd;
	}
	ll x=(n%4==0 ? n/4 : (n+1)/4);
	ll a=2*x-1;
	ll b=2*a;
	ll c=b+1;
	ll d=c+1;
	dbg(x,a,b,c,d);
	vl p,q;
	FOR(i,1,a){
		if(i%2==1){
			p.pb(i);
		}
		else q.pb(i);
	}
	vl r,s;
	FOR(i,a+1,b){
		if(i%2==1){
			r.pb(i);
		}
		else s.pb(i);
	}
	dbg(p,q,r,s);
	vl ans;
	if(n%4==0){
		for(ll i=(ll)s.size()-1;i>=0;i--){
			ans.pb(s[i]);
		}
		for(ll i=(ll)p.size()-1;i>=0;i--){
			ans.pb(p[i]);
		}
		ans.pb(b);
		each(e,p) ans.pb(e);
		ans.pb(c);
		each(e,s) ans.pb(e);
		ans.pb(d);
		for(ll i=(ll)r.size()-1;i>=0;i--){
			ans.pb(r[i]);
		}
		for(ll i=(ll)q.size()-1;i>=0;i--){
			ans.pb(q[i]);
		}
		ans.pb(b);
		ans.pb(a);
		each(e,q) ans.pb(e);
		ans.pb(c);
		each(e,r) ans.pb(e);
		ans.pb(a);
		ans.pb(d);
	}
	else{
		for(ll i=(ll)s.size()-1;i>=0;i--){
			ans.pb(s[i]);
		}
		for(ll i=(ll)p.size()-1;i>=0;i--){
			ans.pb(p[i]);
		}
		ans.pb(b);
		each(e,p) ans.pb(e);
		ans.pb(c);
		each(e,s) ans.pb(e);
		ans.pb(a);
		for(ll i=(ll)r.size()-1;i>=0;i--){
			ans.pb(r[i]);
		}
		for(ll i=(ll)q.size()-1;i>=0;i--){
			ans.pb(q[i]);
		}
		ans.pb(b);
		ans.pb(a);
		each(e,q) ans.pb(e);
		ans.pb(c);
		each(e,r) ans.pb(e);
		
	}
	return ans;
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int t = 1; cin >> t;
    for(int i = 0; i < t; i++) {
        RAYA;
        RAYA;
		ll n;
		cin>>n;
		
        auto x = solve(n-1);
		if(!x.empty() && x[0]==-1){
			cout<<"-1\n";
			continue;
		}
		else{
			dbg("xd ???? ",x);
			each(e,x) e++;
			x.pb(1);
			x.pb(1);
			each(e,x) cout<<e<<" ";
			cout<<"\n";
		}
		
		
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
