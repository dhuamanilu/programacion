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

pair<str,vector<pair<str,ll>>> solve(vpl &steps,pl &source,pl &destination) {
    
	ll n=steps.size();
    // (a , b)
    vpl suff(n, {0, 0});
    // 0 norte 1 este  2 sur  3 oeste
    vl abs(n,-1);
    ll act=0;
    FOR(i,0,n){
        if(steps[i].f==0){
            act=(act-1+4)%4;
        }
        else if(steps[i].f==1){
            act=(act+1)%4;
        }
        else if(steps[i].f==3){
            if(act==0){
                act=2;
            }
            else if(act==1){
                act=3;
            }
            else if(act==2){
                act=0;
            }
            else if(act==3){
                act=1;
            }
        }
        abs[i]=act;
    }
    for(ll i=n-2;i>=0;i--){
        auto [a,b]=suff[i+1];
        ll absDirection=abs[i],xd=abs[i+1];
        a+=steps[i+1].s;
        pl dir={0ll,0ll};
        if(xd==0){
            dir={b,a};
        }
        else if(xd==1){
            dir={a,-b};
        }
        else if(xd==2){
            dir={-b,-a};
        }
        else{
            dir={-a,b};
        }
        auto [x,y]=dir;
        if(absDirection==0){
            suff[i]={y,x};
        }
        else if(absDirection==1){
            suff[i]={x,-y};
        }
        else if(absDirection==2){
            suff[i]={-y,-x};
        }
        else{
            suff[i]={-x,y};
        }
    }
    dbg(suff);
    dbg(abs);
    ll actX=source.f,actY=source.s;
    ll dirAct=0;
    FOR(i,0,n){
        FOR(k,0,4){
            //if(k==steps[i].f) continue;
            ll x=actX,y=actY;
            ll newDir;
            if(k==0){
                newDir=(dirAct-1+4)%4;
            }
            else if(k==1){
                newDir=(dirAct+1)%4;
            }
            else if(k==3){
                if(dirAct==0){
                    newDir=2;
                }
                else if(dirAct==1){
                    newDir=3;
                }
                else if(dirAct==2){
                    newDir=0;
                }
                else if(dirAct==3){
                    newDir=1;
                }
            }
            auto [a,b]=suff[i];
            if(newDir==0){
                y+=steps[i].s;
                y+=a;
                x+=b;
            }
            else if(newDir==1){
                x+=steps[i].s;
                x+=a;
                y-=b;
            }
            else if(newDir==2){
                y-=steps[i].s;
                y-=a;
                x-=b;
            }
            else{
                x-=steps[i].s;
                x-=a;
                y+=b;
            }
            str enstring;
            if(k==0) enstring="left";
            else if(k==1) enstring="right";
            else if(k==2) enstring="straight";
            else enstring="back";

            str enstring2;
            if(steps[i].f==0) enstring2="left";
            else if(steps[i].f==1) enstring2="right";
            else if(steps[i].f==2) enstring2="straight";
            else enstring2="back";
            if(x==destination.f && y==destination.s){
                vector<pair<str,ll>> res;
                res.pb({enstring2,steps[i].s});
                res.pb({enstring,steps[i].s});
                return {"YES",res};
            }

        }
        
        dirAct=abs[i];
        if(dirAct==0){
            actY+=steps[i].s;
        }
        else if(dirAct==1){
            actX+=steps[i].s;
        }
        else if(dirAct==2){
            actY-=steps[i].s;
        }
        else{
            actX-=steps[i].s;
        }
    }
    return {"NO",{}};
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
		vpl a(n);
		each(e,a){
            str direction;
            cin>>direction;
            if(direction == "left"){
                e.f = 0;
            }
            else if(direction == "right"){
                e.f = 1;
            }
            else if(direction == "straight"){
                e.f = 2;
            }
            else if(direction == "back"){
                e.f = 3;
            }
            cin>>e.s;
        }
        pl source,destination;
        cin>>source.f>>source.s>>destination.f>>destination.s;
        auto xd=solve(a,source,destination);
        if(xd.f=="NO"){
            cout<<xd.f<<"\n";
        }
        else{
            cout<<xd.f<<"\n";
            for(auto e:xd.s){
                cout<<e.f<<" "<<e.s<<"\n";
            }
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








