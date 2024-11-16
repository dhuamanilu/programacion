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

using ll  = long long;
using db  = long double; 
using str = string;      
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
#define mp make_pair
#define f first
#define s second
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

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MOD = 1e9+7;
const ll BIG = 1e18;  
const db PI = acos((db)-1);
mt19937 rng(0);



ll cdiv(ll a, ll b) {
	return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
	return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } 
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; } 

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

int rng_int(int L, int R) { assert(L <= R);
	return uniform_int_distribution<int>(L,R)(rng);  }
ll rng_ll(ll L, ll R) { assert(L <= R);
	return uniform_int_distribution<ll>(L,R)(rng);  }


ll solve(vector<array<pl,2>> &a) {
	ll n=sz(a);
	map<pl,ll> degree;
	map<pl,vpl> G;
	each(e,a){
		degree[e[0]]++;
		degree[e[1]]++;
		G[e[0]].pb(e[1]);
		G[e[1]].pb(e[0]);
	}
	map<pl,bool> vis;
	ll group=1;
	map<ll,vpl> groups;
	auto dfs=[&](auto &&dfs,pl &act)->void{
		vis[act]=1;
		groups[group].pb(act);
		each(e,G[act]){
			if(!vis[e]){
				dfs(dfs,e);
			}
		}
	};
	each(e,degree){
		auto xd=e.f;
		if(!vis[xd]){
			dfs(dfs,xd);
			group++;
		}
	}
	ll ans=0;
	each(e,groups){
		bool ok=true;
		each(e2,e.s){
			if(degree[e2]!=2){
				ok=false;
				break;
			}
		}
		if(ok){
			ans++;
		}
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
		ll n;
		cin>>n;
		vector<array<pl,2>> a(n);
		each(e,a) each(e2,e)cin>>e2.f>>e2.s;
        cout<<solve(a)<<"\n";
    }
    RAYA;
    RAYA;
}








