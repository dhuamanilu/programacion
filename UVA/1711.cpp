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
V<vl> paths;

void dfs(vl path,ll n,Dinic& dn){
	dbg("visitando ", path);
	if(path.back()==n){
		map<pl,ll> pathActual;
		for(ll i=0;i<path.size()-1;i++){
			ll mini=min(path[i],path[i+1]),maxi=max(path[i],path[i+1]);
			pathActual[{mini,maxi}]++;
		}
		bool ok2=true;
		for(auto & another : paths){
			for(ll i=0;i<another.size()-1;i++){
				ll mini=min(another[i],another[i+1]),maxi=max(another[i],another[i+1]);
				if(pathActual.count({mini,maxi})){
					ok2=false;
					break;
				}
			}
		}
		if(ok2){
			paths.push_back(path);
		}
		return;
	}
	
	for(auto & edge : dn.adj[path.back()]){
		ll mini=min(path.back(),(ll)edge.to),maxi=max(path.back(), (ll)edge.to);
		if(edge.flow() > 0){
			bool ok=true;
			for(auto & ele : path){
				if(ele==edge.to){
					ok=false;
					break;
				}
			}
			if(ok){
				vl nuevo=path;
				nuevo.push_back(edge.to);
				dfs(nuevo,n,dn);
			}
			
		}
	}
}
void solve(){
    ll n,m;
    cin>>n>>m;
    Dinic dn(n+1);
    for(ll i=0;i<m;i++){
        ll a,b,c=1;
        cin>>a>>b;
        dn.addEdge(a,b,c);	
    }
	//GA;
    cout<<dn.calc(1,n)<<"\n";
	//GA;
	/*for(ll i=0;i<dn.adj.size();i++){
		for(auto & edge : dn.adj[i]){
			cout<<i<<" -> "<<edge.to<<" , flow: "<<edge.flow()<<"\n";
		}
	}*/
	//RAYA;
	vl path={1};
	dfs(path,n,dn);
	//GA;
	for(auto & path : paths){
		cout<<path.size()<<"\n";
		for(auto & ele : path){
			cout<<ele<<" ";
		}
		cout<<"\n";
	}
	
 
	/*for(auto & [u,v] : edges){
		bool ok1=dn.leftOfMinCut(u) && !dn.leftOfMinCut(v);
		bool ok2=dn.leftOfMinCut(v) && !dn.leftOfMinCut(u);
		if(ok1 or ok2){
			cout<<u<<" "<<v<<"\n";
		}
	}*/
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    //cin>>t;
    while(t--) solve();
}