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
const ll BIG = 1e15;  //? not too close to LLONG_MAX
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

vector<string> types={"BG","BR","BY","GR","GY","RY"};
map <string,ll> id;
vl solve(vs &a,vpl &querys) {
    ll n=a.size();
    ll q=querys.size();
    vector<array<ll,6>> pref(n);
    array<ll,6> pri;
    each(e,pri)e=0;
    pri[id[a[0]]]++;
    pref[0]=pri;
    FOR(i,1,n){
        array<ll,6> act=pref[i-1];
        act[id[a[i]]]++;
        pref[i]=act;
    }
    vector<array<ll,6>> suff(n);
    array<ll,6> priSuf;
    each(e,priSuf)e=0;
    priSuf[id[a[n-1]]]++;
    suff[n-1]=priSuf;
    for(ll i=n-2;i>=0;i--){
        array<ll,6> act=suff[i+1];
        act[id[a[i]]]++;
        suff[i]=act;
    }
    
    
    vl res;
    auto query=[&](ll idx1,ll idx2){
        auto R=pref[idx2];
        if(idx1>=1){
            auto L=pref[idx1-1];
            FOR(i,0,(ll)R.size()){
                R[i]-=L[i];
            }
        }
        return R;
    };
    auto query2=[&](ll idx1,ll idx2){
        //idx1<=idx2
        auto R=suff[idx1];
        if(idx2+1 < n){
            auto L=suff[idx2+1];
            FOR(i,0,(ll)R.size()){
                R[i]-=L[i];
            }
        }
        return R;
    };
    auto isOk=[&](array<ll,6> info,ll id1,ll id2){
        //auto info=query(low,high);
        bool ok=false;
        FOR(it,0,(ll)info.size()){
            if(it==id1 || it==id2) continue;
            //cout<<"it infot en it : "<<it<<" "<<info[it]<<"\n";
            if(info[it]>0){
                ok=true;
                break;
            }
        }
        return ok;
        
    };
    
    each(e,querys){
        ll mini=min(e.f,e.s),maxi=max(e.f,e.s);
        //cout<<"mini max : "<<mini<<" "<<maxi<<"\n";
        ll id1=min(id[a[mini]],id[a[maxi]]),id2=max(id[a[mini]],id[a[maxi]]);
        //handle special case
        if(id1+id2==5){
            //1ERO,verificar si es que dentro del rango mini maxi hay un "puente"
            bool ok=isOk(query(mini,maxi),id1,id2);
            if(ok){
                res.pb(maxi-mini);
            }
            else{
                ll cand=BIG;
                //sino
                //tomar el minimo entre 2 casos 
                //caso 1 <---------- AB CD
                //buscar binariamente el primer indice yendo a la izq 
                //tal que la suma de los que
                //no son id1 id2 es >0
                auto bb2=[&](ll s,ll e){
                    ll m=s+(e-s)/2,guarda=-1;
                    while(s<=e){
                        m=s+(e-s)/2;
                        if(isOk(query2(m,mini-1),id1,id2)){
                            guarda=m;
                            s=m+1;
                        }
                        else e=m-1;
                    }
                    return guarda;
                };
                auto get1=bb2(0,mini-1);
                if(get1!=-1){
                    ckmin(cand,mini-get1);
                }
                //caso 2 AB CD----------->
                //buscar binariamente el primer indice yendo a la der 
                //tal que la suma de los que
                //no son id1 id2 es >0
                auto bb1=[&](ll s,ll e){
                    ll m=s+(e-s)/2,guarda=-1;
                    while(s<=e){
                        m=s+(e-s)/2;
                        if(isOk(query(maxi+1,m),id1,id2)){
                            guarda=m;
                            e=m-1;
                        }
                        else s=m+1;
                    }
                    return guarda;
                };
                auto get2=bb1(maxi+1,n-1);
                if(get2!=-1){
                    ckmin(cand,get2-maxi);
                }
                if(cand==BIG){
                    res.pb(-1);
                }
                else res.pb(maxi-mini+2*cand);
            }
            
        }
        else{
            res.pb(maxi-mini);
        }
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin>>t;
    FOR(i,0,(ll)types.size()){
        id[types[i]]=i;
    }
    for(int idx = 0; idx < t; idx++) {
        RAYA;
        RAYA;
        ll n,q;
        cin>>n>>q;
        //cout<<"n q : "<<n<<" "<<q<<"\n";
        vs a(n);
        each(e,a)cin>>e;
        vpl querys(q);
        each(e,querys){
            cin>>e.f>>e.s;
            //cout<<e.f<<" "<<e.s<<"\n";
            e.f--;
            e.s--;
        }
        auto x=solve(a,querys);
        each(e,x)cout<<e<<"\n";
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








