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

/**
 * Author: chilli
 * Date: 2019-04-26
 * License: CC0
 * Source: https://cp-algorithms.com/graph/dinic.html
 * Description: Flow algorithm with complexity $O(VE\log U)$ where $U = \max |\text{cap}|$.
 * $O(\min(E^{1/2}, V^{2/3})E)$ if $U = 1$; $O(\sqrt{V}E)$ for bipartite matching.
 * Status: Tested on SPOJ FASTFLOW and SPOJ MATCHING, stress-tested
 */
#pragma once
struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};

struct Dinic {
	
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		FOR(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

void solve(){
    ll n,m;
    cin>>n>>m;
    vl time_inspection(n);
    for(auto & e : time_inspection)cin>>e;
    V<vl> a(n,vl(n,0));
    for(auto & e : a){
        for(auto & e2 : e){
            cin>>e2;
        }
    }
    V<array<ll,3>> info(m);
    for(ll i=0;i<m;i++){
        ll s,f,t;
        cin>>s>>f>>t;
        s--;
        f--;
        info[i]={s,f,t};
    }
    V<vl> dp(n,vl(n));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(i==j){
                dp[i][j]=0;
            }
            else{
                dp[i][j]=a[i][j] + time_inspection[j];
            }
            
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            for(ll k=0;k<n;k++){
                dp[j][k]=min(dp[j][k],dp[j][i] + dp[i][k]);
            }
        }
    }
    Dinic dn((2*m)+2);
    auto puedo=[&](ll i,ll j){
        auto [startI,destinationI, required_timeI] = info[i];
        auto [startJ,destinationJ,required_time_J] = info[j];
        
        ll time_I = required_timeI + a[startI][destinationI] + time_inspection[destinationI];
        ll time_J = time_I + dp[destinationI][startJ];
        if(time_J <=  required_time_J){
            return true;
        }
        else return false;
    };  
    for(ll i=0;i<m;i++){
        for(ll j=0;j<m;j++){
            if(i==j){

            }
            else if(puedo(i,j)){
                //dbg("si",i,j,j+m);
                dn.addEdge(i,j+m,1);
            }
            //else dbg("no",i,j);
        }
    }
    //del source a todas las salidas
    for(ll i=0;i<m;i++){
        dn.addEdge(2*m,i,1);   
    }
    //de todas las llegadas al sink
    for(ll i=0;i<m;i++){
        dn.addEdge(i+m,(2*m)+1,1);   
    }
    //calcular flujo maximo
    ll xd = dn.calc(2*m,(2*m) + 1);
    /*for(ll i=0;i<2*m;i++){
        for(auto & edge : dn.adj[i]){
            cout<<i<<" -> "<<edge.to<<" ,flow: "<<edge.flow()<<"\n";
        }
    }*/
    //dbg(m,xd);
    cout<<m-xd<<"\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    //cin>>t;
    while(t--) solve();
}