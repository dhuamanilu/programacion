//#pragma GCC optimize ("Ofast")
//? #pragma GCC target ("avx,avx2")
//#pragma GCC optimize ("trapv")
//#undef _GLIBCXX_DEBUG //? for Stress Testing
#include <bits/stdc++.h>
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
    V<vl> a(h,vl(w,0));
    for(auto & e : a){
        for(auto & e2 : e){
            char xd;
            cin>>xd;
            if(xd=='#'){
                e2=1;
            }
            else e2=0;
        }
    }
    vl dx={1,-1,0,0};
    vl dy={0,0,1,-1};
    auto isValid=[&](ll i,ll j){
        return i>=0 && i < h && j >= 0 && j < w;
    };
    queue<pl> sgte,actual;
    V<vl> vis(h,vl(w,0));
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            if(a[i][j]==1 || vis[i][j]) continue;
            ll cont=0;
            for(ll k=0;k<4;k++){
                ll newX=i+dx[k],newY=j+dy[k];
                if(isValid(newX,newY)){
                    if(a[newX][newY]==1) cont++;
                }
            }
            if(cont==1){
                vis[i][j]=1;
                actual.push({i,j});
            }
        }
    }
    
    while(true){
        while(!actual.empty()){
            auto xd = actual.front();
            actual.pop();
            //if(vis[xd.f][xd.s]) continue;
            ll cont=0;
            for(ll k=0;k<4;k++){
                ll newX=xd.f+dx[k],newY=xd.s+dy[k];
                if(isValid(newX,newY)){
                    if(a[newX][newY]==1) cont++;
                }
            }
            if(cont==1){
                vis[xd.f][xd.s]=1;
                sgte.push({xd.f,xd.s});
            }
        }
        queue<pl> guarda;
        if(sgte.empty()) break;
        while(!sgte.empty()){
            auto ac = sgte.front();
            sgte.pop();
            vis[ac.f][ac.s]=1;
            a[ac.f][ac.s]=1;
            guarda.push(ac);
        }
        //for(auto & e : a)dbg(e);
        queue<pl> guarda2;
        while(!guarda.empty()){
            auto ac = guarda.front();
            guarda.pop();
            for(ll k=0;k<4;k++){
                ll newX=ac.f+dx[k],newY=ac.s+dy[k];
                if(isValid(newX,newY)){
                    ll cont=0;
                    for(ll it=0;it<4;it++){
                        ll newX2=newX+dx[it],newY2=newY+dy[it];
                        if(isValid(newX2,newY2)){
                            if(a[newX2][newY2]==1) cont++;
                        }
                    }
                    if(cont==1 && !vis[newX][newY] && a[newX][newY]==0){
                        vis[newX][newY]=1;
                        guarda2.push({newX,newY});
                    }
                }
            }
        }
        actual = guarda2;
    }
    
    ll res=0;
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            //dbg(i,j,a[i][j]);
            res+=a[i][j];
        }
    }
    cout<<res<<"\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    //cin>>t;
    while(t--) solve();
}