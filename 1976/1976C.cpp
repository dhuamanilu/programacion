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

vl solve(ll n,ll testers,vl &a,vl &b) {
    
    ll tam=a.size();
    vl prog(tam,0),test(tam,0);
    prog[0]=a[0]>b[0] ? 1 : 0;
    test[0]=b[0]>a[0] ? 1 : 0;
    FOR(i,1,tam){
        prog[i]=prog[i-1]+(a[i]>b[i] ? 1 : 0);
        test[i]=test[i-1]+(b[i]>a[i] ? 1 : 0);
    }
    vl valProg(tam,0),valTest(tam,0),optimal(tam,0);
    valProg[0]=a[0];
    valTest[0]=b[0];
    optimal[0]=max(a[0],b[0]);
    FOR(i,1,tam){
        valProg[i]=valProg[i-1]+a[i];
        valTest[i]=valTest[i-1]+b[i];
        optimal[i]=optimal[i-1]+max(a[i],b[i]);
    }
    auto query=[&](vl &v,ll l,ll r){
        return l==0 ? v[r] : v[r]-v[l-1];
    };
    auto get=[&](vl &v,ll x,ll lim){
        ll s=x,e=tam-1,m=s+(e-s)/2,guarda=-1;
        while(s<=e){
            m=s+(e-s)/2;
            ll cant=query(v,x,m);
            if(cant<=lim){
                guarda=m;
                s=m+1;
            }
            else{
                e=m-1;
            }
        }
        return guarda;
    };
    ll actProgr=n,actTest=testers,actVal=0;
    vl res;
    FOR(i,0,tam){
        ll lastProg=get(prog,i+1,actProgr);
        ll lastTest=get(test,i+1,actTest);
        ll xd=actVal;
        dbg(i,tam,lastProg,lastTest,xd);
        if(actProgr>0 && actTest>0){
            dbg("de i puedo buscar binariamente",i,actProgr,actTest);
            if(lastProg<lastTest){
                xd+=query(optimal,i+1,lastProg);
                xd+=query(valTest,lastProg+1,tam-1);
            }
            else{
                xd+=query(optimal,i+1,lastTest);
                xd+=query(valProg,lastTest+1,tam-1);
            }
        }
        else if(actProgr==0){
            dbg("destino decidido puro tester",i);
            xd+=query(valTest,i+1,tam-1);
        }
        else{
            dbg("destino decidido puro programador",i);
            xd+=query(valProg,i+1,tam-1);
        }     
        res.pb(xd);
        if(actProgr>0 && actTest>0){
            if(a[i]>b[i]){
                actVal+=a[i];
                actProgr--;
            }
            else{
                actVal+=b[i];
                actTest--;
            }
        }
        else if(actProgr==0){
            actVal+=b[i];
            actTest--;
        }
        else{
            actVal+=a[i];
            actProgr--;
        }
    }
    return res;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int t = 1;
    cin >> t;
 
    for(int idx = 0; idx < t; idx++) {
        RAYA;
        RAYA;
        ll n,m;
        cin>>n>>m;
        vl a(n+m+1);
        each(e,a) cin>>e;
        vl b(n+m+1);
        each(e,b) cin>>e;
        auto x = solve(n,m,a,b);
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








