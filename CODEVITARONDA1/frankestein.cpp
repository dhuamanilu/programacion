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


ll solve(map<str,vector<vs>> &m , str & target,set<str> & potions) {
	map<str,ll> dp;
	auto get=[&](auto &&get , str &act)->ll{
		if(dp.count(act)) return dp[act];
		ll ans=BIG;
		if(m.count(act)){
			for(auto & recipe : m[act]){
				ll actualCost=0;
				for(auto & component : recipe){
					if(!potions.count(component)){
						actualCost++;
					}
					else{
						actualCost+=get(get,component);
					}
				}
				ckmin(ans,actualCost);
			}
			return dp[act]=ans;
		}
		else{
			return dp[act]=1;
		}
		
	};
	return get(get,target)-1;
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
		cin.ignore();
		set<str> potions;
		map<str,vector<vs>> m;
		FOR(i,0,n){
			str s;
			getline(cin, s);
			vs components;
			str result;
			str temp="";
			FOR(j,0,sz(s)){
				if(s[j]=='='){
					
					result=temp;
					potions.insert(result);
					temp="";
				}
				else if(s[j]=='+'){
					components.pb(temp);
					temp="";
				}
				else{
					temp+=s[j];
				}
			}
			if(temp!=""){
				components.pb(temp);
			}
			m[result].pb(components);
			//dbg(result,components);	
		}
		str target;
		cin>>target;
        cout<<solve(m,target,potions)<<"\n";
    }
    RAYA;
    RAYA;
}








