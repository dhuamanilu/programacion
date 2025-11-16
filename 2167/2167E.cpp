#pragma GCC optimize ("Ofast")
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
    ll n,k,x;
    cin>>n>>k>>x;
    vl a(n);
    for(auto & e : a)cin>>e;
    sor(a);
    const ll INF = 1e16;
    a.insert(a.begin(),-INF); 
    a.push_back(INF);

    set<array<ll,4>> xd;
    //minima distancia a un elemento , cquien eres , lower bound ,upper bound
    ll tam = a.size();
    for(ll i = 1;i < tam;i++){
        ll point;
        if(i == 1){
            point = 0;
        }
        else if(i == (tam - 1)){
            point = x;
        }
        else{
            point = (a[i] + a[i-1]) / 2;
        }
        ll dist = min(a[i] - point , point - a[i-1]);
        xd.insert({dist, point , a[i-1] , a[i]});
    }
    //dbg(xd);
    vl res;
    map<ll,ll> vis;
    auto add=[&](ll num,array<ll,4> &info){
        auto [dist, ele ,low ,upp] = info;
        ll newDist = min(upp - (num) , (num) - low);
        xd.insert({newDist , num , low, upp});
    };
    while((ll)res.size() < k){
        auto act = prev(xd.end());
        auto info = *act;
        auto [dist, ele ,low ,upp] = info;
        xd.erase(act);
        if(vis[ele]) continue;
        res.push_back(ele);
        vis[ele]++;
        //hacia adelante
        if((ele+1) <=x && !vis.count(ele + 1)){
            add(ele+1 ,info); 
        }

        //hacia atras
        if(ele >=1 && !vis.count(ele - 1)){
            add(ele-1 ,info); 
        }
    }
    sor(res);
    for(auto & e : res)cout<<e<<" ";
    cout<<"\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    cin>>t;
    while(t--) solve();
}