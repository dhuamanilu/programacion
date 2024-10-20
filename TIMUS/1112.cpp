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
//? Generator
int rng_int(int L, int R) { assert(L <= R);
	return uniform_int_distribution<int>(L,R)(rng);  }
ll rng_ll(ll L, ll R) { assert(L <= R);
	return uniform_int_distribution<ll>(L,R)(rng);  }
vpl brute(vpl &a){
    ll n=a.size();
    auto intersectVacio=[&](ll idx1,ll idx2){
        pl p1=a[idx1],p2=a[idx2];
        vpl aux={p1,p2};
        sort(all(aux));
        return (aux[1].f  >= aux[0].s); 
    };
    vpl ans;
    bool pri=true;
    FOR(i,0,(1ll<<n)){
        vl ind;
        bool ok=true;
        FOR(j,0,n){
            if(((1ll<<j)&i)){
                ind.pb(j);
            }
        }
        ll tam=ind.size();
        //if(i==30) dbg(ind);
        FOR(it1,0,tam){
            FOR(it2,it1+1,tam){
                //if(i==30) dbg(ind[it1],ind[it2],intersectVacio(ind[it1],ind[it2]));
                if(!intersectVacio(ind[it1],ind[it2])){
                    ok=false;
                    break;
                }
            }
        }
        if(ok){
            if(n-tam<(ll)ans.size() || pri){
                pri=false;
                //ans=ind;
                vpl aborrar;
                FOR(j,0,n){
                    if(((1ll<<j)&i)==0){
                        aborrar.pb(a[j]);
                    }
                }
                ans=aborrar;
            }
        }
    }
    return ans;
}
struct info{
    pl par;
    ll idx;
};
vpl solve(vpl &a) {
	ll n=a.size();
    vl act(n,1);
    auto intersectVacio=[&](ll idx1,ll idx2){
        pl p1=a[idx1],p2=a[idx2];
        vpl aux={p1,p2};
        sort(all(aux));
        return (aux[1].f  >= aux[0].s); 
    };
    //map<ll,ll> idxBo;
    while(true){
        vl cont(n,0);
        FOR(i,0,n){
            if(!act[i]) continue;
            FOR(j,0,n){
                if(!act[j] || i==j) continue;
                if(!intersectVacio(i,j)){
                    cont[i]++;
                }
            }
        }
        //dbg(cont);
        ll maxi=0;
        vector<info> cand;
        FOR(i,0,n){
            if(!act[i]) continue;
            if(cont[i]>maxi){
                maxi=cont[i];
                cand.clear();
                info pon;
                pon.par=a[i];
                pon.idx=i;
                cand.pb(pon);
            }
            else if(cont[i]==maxi){
                info pon;
                pon.par=a[i];
                pon.idx=i;
                cand.pb(pon);
            }
        }
        if(maxi==0){
            break;
        }
        sort(all(cand),[&](info &c,info &d){
            return c.par<d.par;
        });
        //each(e,cand){cout<<e.par.f<<" "<<e.par.s<<" "<<e.idx<<"\n";}
        //dbg("borare ",cand[0].idx,cand[0].par);
        act[cand[0].idx]=0;
        //idxBo.pb(cand[0].idx);
    }
    vpl ans;
    FOR(i,0,n){
        if(act[i]) ans.pb(a[i]);
    }
    sort(all(ans));
    return ans;
   
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while(0){
        ll n=rng_ll(1,18);
        vpl b(n);
        each(e,b){
            e.f=rng_ll(-999,998);
            e.s=rng_ll(e.f+1,999);
        }
        auto ans1=solve(b);
        auto ans2=brute(b);
        if(ans1.size()!=ans2.size()){
            dbg("xd :",b,ans1,ans2);
            assert(false);
        }
        else dbg("ok");
    }
    for(int idx = 0; idx < t; idx++) {
        RAYA;
        RAYA;
        ll n;
        cin>>n;
        vpl a(n);
        each(e,a){cin>>e.f;cin>>e.s;}
        auto  x=solve(a);
        cout<<(ll)x.size()<<"\n";
        each(e,x){cout<<e.f<<" "<<e.s<<"\n";}
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








