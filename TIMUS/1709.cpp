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

pair<ll,vector<vector<char>>> solve(vector<vl> &G,ll d,ll a) {
    ll n=G.size();
    ll num=0,gran=0;
    vl vis(n,0);
    
    vector<vl> group(n);
    auto dfs=[&](ll ele,ll id,auto &&dfs)->void{
        group[id].pb(ele);
        vis[ele]=1;
        FOR(i,0,n){
            if(G[ele][i] && !vis[i]){
                dfs(i,id,dfs);
            }
        }
    };
    FOR(i,0,n){
        if(!vis[i]){
            num++;
            dfs(i,gran,dfs);
            gran++;
        }
    }
    
    ll aquitar=0;
    vector<vector<char>> res(n,vector<char>(n,'0')); 
    //dbg(group);
    map<pair<ll,ll>,ll> MST;
    FOR(i,0,(ll)group.size()){
        if(group[i].size()==0) continue;
        //hallar el mst
        vl vis2(n,0);   
        queue<ll> cola;
        cola.push(group[i][0]);
        vis2[group[i][0]]=1;
        while(!cola.empty()){
            ll act=cola.front();
            cola.pop();
            
            FOR(k,0,n){
                if(G[act][k] && !vis2[k]){
                    ll mini=min(act,k*1ll),maxi=max(act,k*1ll);
                    MST[{mini,maxi}]++;
                    cola.push(k);
                    vis2[k]=1;
                }
            }
        }
        each(e,group[i]){
            FOR(iter,0,n){
                ll mini=min(e,iter*1ll),maxi=max(e,iter*1ll);
                if(G[mini][maxi] && !MST.count({mini,maxi})){
                    aquitar++;
                    res[mini][maxi]='d';
                    res[maxi][mini]='d';
                }
            }
        }
        ll ulti=group[i].back();
        
        if(i+1<(ll)group.size()){
            if((ll)group[i+1].size()>0){
                ll sgteUlti=group[i+1].back();
                res[ulti][sgteUlti]='a';
                res[sgteUlti][ulti]='a';
            }    
        }

    }
    //dbg(MST,aquitar);
    pair<ll,vector<vector<char>>> ans;
    ans.f=(num-1)*a + d*(aquitar/2);
    ans.s=res;
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    for(int idx = 0; idx < t; idx++) {
        RAYA;
        RAYA;
        ll n;
        cin>>n;
        ll d,a;
        cin>>d>>a;
        vector<vl> G(n,vl(n,0));
        FOR(i,0,n){
            str s;
            cin>>s;
            FOR(j,0,n){
                if(s[j]=='1'){
                    G[i][j]=1;
                }
            }
            
        }
        auto x=solve(G,d,a);
        cout<<x.f<<"\n";
        each(e,x.s){
            each(e2,e){
                cout<<e2;
            }
            cout<<"\n";
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








