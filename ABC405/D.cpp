//#pragma GCC optimize ("Ofast")
//? #pragma GCC target ("avx,avx2")
//#pragma GCC optimize ("trapv")
//#undef _GLIBCXX_DEBUG //? for Stress Testing
#include "bits/stdc++.h"
using namespace std;

//* Debugger
string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(char c) {
    return string(1, c);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A>
string to_string(A v);

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "[";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "]";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
cerr << " " << to_string(H);
debug_out(T...);
}

#ifdef LOCAL
#define MACRO(code) do {code} while (false)
#define dbg(x)      {auto xd = x; cout << "Line(" << __LINE__ << "): " << "\033[1;34m" << #x << "\033[0;32m = \033[35m" << to_string(xd) << "\033[0m" << endl;}
#define dbg(...)    MACRO(cout << "Line(" << __LINE__ << "): " << "\033[1;34m" << "[" << #__VA_ARGS__ << "]\033[35m:"; debug_out(__VA_ARGS__); cout << "\033[0m";)

#define GA          dbg(0)
#define RAYA        cout << "\033[101m" << "================================" << "\033[0m" << endl;
#else
#define dbg(x)
#define dbg(...)
#define GA
#define RAYA
#endif
//* /Debugger

using ll = long long;
using db = long double; // or double if tight TL
using str = string;

using pi = pair<int,int>;
using pl = pair<ll, ll>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T,SZ>;
using vi = V<int>;
using vl = V<ll>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MOD = 1e9+7;
const db PI = acos((db)-1);
mt19937 rng(0); // or mt19937_64
//* mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; } // set a = max(a,b)

void setIn(string s) { freopen(s.c_str(), "r", stdin); }
//? /Custom Helpers
//? Generator
int rng_int(int L, int R) { assert(L <= R);
    return uniform_int_distribution<int>(L,R)(rng);  }
ll rng_ll(ll L, ll R) { assert(L <= R);
    return uniform_int_distribution<ll>(L,R)(rng);  }

void solve(){
    ll h,w;
    cin>>h>>w;
    vector<vector<char>> a(h,vector<char>(w));
    for(auto & e : a){
        for(auto & e2 :e ){
            cin>>e2;
        }
    }
   
    const ll BIG=(ll)1e18;
    vector<vl> dist(h,vl(w,BIG));
    vl dx={1,-1,0,0};
    vl dy={0,0,1,-1};
    auto isValid=[&](ll x,ll y){
        return x>=0 && x < h && y >=0 && y< w;
    };
    vector<vector<char>> res=a;
    vector<char> mov={'^','v','<','>'};
    auto bfs=[&](vector<pl> &cands){
        vector<vl> vis(h,vl(w,0));
        
        queue<pl> xd;
        for(auto & e: cands){
            xd.push(e);
            vis[e.first][e.second]=1;
            dist[e.first][e.second]=0;
        }
        while(!xd.empty()){
            pl act=xd.front();
            xd.pop();
            for(ll i=0;i<4;i++){
                ll newX=act.first + dx[i],newY=act.second + dy[i];
                if(isValid(newX,newY)){
                    if(vis[newX][newY] || res[newX][newY]=='#' || res[newX][newY]=='E') continue;
                    vis[newX][newY]=1;
                    if(dist[act.first][act.second] + 1 < dist[newX][newY]){
                        dist[newX][newY] = dist[act.first][act.second] + 1;
                        res[newX][newY]=mov[i];
                        xd.push({newX,newY});
                    }
                }
            }
        }
    };
    vector<pl> cands;
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            if(a[i][j]=='E'){
                cands.push_back({i,j});
            }
        }
    }
    bfs(cands);
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            cout<<res[i][j];
        }
        cout<<"\n";
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    //cin>>t;
    while(t--) solve();
}