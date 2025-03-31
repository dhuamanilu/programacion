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
//? /Custom Helpers

//? Template
//? /Template

ll brute(vl &a){
    ll n=a.size(),res=0;
    auto getMex=[](vl &arr,ll ini,ll fin){
        map<ll,ll> m;
        FOR(i,ini,fin+1){
            m[arr[i]]++;
        }
        ll mex=0;
        while(m.count(mex)) mex++;
        return mex;
    };
    FOR(i,0,(1ll<<n)){
        vl b;
        FOR(j,0,n){
            if((1ll<<j)&i){
                b.pb(a[j]);
            }
        }
        bool ok=true;
        ll mini=BIG,tam=b.size();
        FOR(k,0,tam){
            ckmin(mini,b[k]);
            if(mini < getMex(b,k+1,tam-1)){
                ok=false;
                break;
            }
        }
        if(ok){
            ckmax(res,tam);
        }
    }
    return res;
}

ll solve(vl &a) {
    ll idx=-1,n=a.size();
    FOR(i,0,n){
        if(a[i]==0){
            idx=i;
            break;
        }
    }
    if(idx==-1){
        return n;
    }
    else{
        vl izq;
        FOR(i,0,idx){
            izq.pb(a[i]);
        }
        sor(izq);
        map<ll,ll> m;
        FOR(i,idx,n){
            m[a[i]]++;
        }
        ll mex=0;
        while(m.count(mex)){
            mex++;
        }
        ll tam=izq.size();
        ll cant=upper_bound(all(izq),mex)-izq.begin();
        ll cuantos=tam-cant;
        ll res=cuantos + (a[0]==mex) + (n - idx -(m[0]-1));
        FOR(i,1,mex){
            ll contr=m.count(i) ? m[i] : 0ll;
            ll cant2=upper_bound(all(izq),i)-izq.begin();
            ll cuantos2=tam-cant2;
            ll val=((cuantos2)+ (a[0]==i) + (n-idx-(m[0]-1) - contr) );
            ckmax(res,val);         
        }
        set<ll> os;
        each(e,izq){
            os.insert(e);
        }
        ll guardamex=mex,k=idx-1,agregar=0;
        FOR(j,guardamex,n){
            while(!m.count(j) && k>=0){
                m[a[k]]++;
                agregar++;
                auto xd=os.lower_bound(a[k]);
                if(xd!=os.end()){
                    os.erase(xd);   
                }
                k--;
            }
            while(m.count(mex)){
                mex++;
            }
            ll cant2=upper_bound(all(izq),mex)-izq.begin();
            ll cuantos2=tam-cant2;
            dbg(n-idx-(m[0]-1),j,cuantos2,mex,agregar);
            auto it=lower_bound(all(izq),mex);
            ll ctmr=it!=izq.end() ? *it : -1;
            ll val=cuantos2+(n-idx-(m[0]-1))+(ctmr==mex) + agregar;
            ckmax(res,val);
        }
        ckmax(res,n-m[0]);
        return res;
    }
}

void setIn(str s) { freopen(s.c_str(), "r", stdin); }
void setOut(str s) { freopen(s.c_str(), "w", stdout); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    vl asd={11, 1, 11, 3, 3, 12, 2, 7, 11, 0, 7};
    dbg(brute(asd),solve(asd));
    //? Stress Testing
    while(0) {
        ll n=rng_ll(1,15);
        vl a(n);
        each(e,a){
            e=rng_ll(0,15);
        }
        ll ans1=brute(a);
        ll ans2=solve(a);
        if(ans1!=ans2){
            dbg("xd",ans1,ans2,a);
            assert(false);
        }
        else dbg("ok");
    }

    int t = 1;
	cin >> t;
    for(int i = 0; i < t; i++) {
        RAYA;
        RAYA;
		ll n;
		cin>>n;
		vl a(n);
		each(e,a) cin>>e;
        cout<<solve(a)<<"\n";
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