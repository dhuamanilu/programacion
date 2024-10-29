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

vs solve(vl &a,vl &b,vpl &queries) {
	ll n=a.size(),m=b.size(),q=queries.size();
	vl posA(n,-1);
	vector<set<ll>> posB(n);
	FOR(i,0,n){
		posA[a[i]]=i;
	}
	FOR(i,0,m){
		posB[b[i]].insert(i);
	}
	vl f(n,0);
	vl start(n,BIG);
	FOR(i,0,n){
		if(posB[i].size()>0){
			start[i]=*(posB[i].begin());
		}
	}
	ll cont=0;
	FOR(i,0,n-1){
		f[i]=(start[a[i]] > start[a[i+1]]);
		cont+=f[i];
	}
	vs ans;
	if(cont==0)ans.pb("YA");
	else ans.pb("TIDAK");
	for(auto &[s,t] : queries){
		//a[posA[b[s]]+1];
		ll sgte=posA[b[s]]+1;
		if(sgte<n)
			cont-=start[sgte-1] > start[sgte];
		
		ll ante=posA[b[s]]-1;
		if(ante>=0)	
			cont-=start[ante] > start[ante+1];

		posB[b[s]].erase(s);
		if(posB[b[s]].size()>0){
			start[b[s]]=*(posB[b[s]].begin());
		}
		else start[b[s]]=BIG;

		ll sgte2=posA[b[s]]+1;
		if(sgte2<n)
			cont+=start[sgte2-1] > start[sgte2];
		
		ll ante2=posA[b[s]]-1;
		if(ante2>=0)	
			cont+=start[ante2] > start[ante2+1];


		b[s]=t;

		ll sgte3=posA[b[s]]+1;
		if(sgte3<n)
			cont-=start[sgte3-1] > start[sgte3];
		
		ll ante3=posA[b[s]]-1;
		if(ante3>=0)	
			cont-=start[ante3] > start[ante3+1];
		
		posB[t].insert(s);
		start[t]=*(posB[t].begin());
			
		ll sgte4=posA[b[s]]+1;
		if(sgte4<n)
			cont+=start[sgte4-1] > start[sgte4];
		
		ll ante4=posA[b[s]]-1;
		if(ante4>=0)	
			cont+=start[ante4] > start[ante4+1];
		
		
		if(cont==0)ans.pb("YA");
		else ans.pb("TIDAK");
	}
	return ans;
	
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;

    for(int idx = 0; idx < t; idx++) {
        RAYA;
        RAYA;
		ll n,m,q;
		cin>>n>>m>>q;
		vl a(n);
		each(e,a){cin>>e; e--;}
		vl b(m);
		each(e,b){cin>>e; e--;}
		vpl queries(q);
		each(e,queries) {cin>>e.f>>e.s; e.f--;e.s--;}
        auto x = solve(a,b,queries);
		each(e,x){
			cout<<e<<"\n";
		}
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








