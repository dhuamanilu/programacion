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
 * Source: https://c...content-available-to-author-only...s.com/graph/dinic.html
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
void solve(ll x,ll y,ll p){
    V<V<char>> xd(x,V<char>(y,'1'));
    for(auto &e : xd){
    	for(auto & e2 :e){
    		cin>>e2;
    	}
    }
    V<vl> id(x,vl(y,0));
    ll cont=0;
    for(ll i=0;i<x;i++){
    	for(ll j=0;j<y;j++){
    		id[i][j]=cont++;
    	}
    }
    V<vl> id2(x,vl(y,0));
    for(ll i=0;i<x;i++){
    	for(ll j=0;j<y;j++){
    		id2[i][j]=cont++;
    	}
    }
    Dinic dn((2*(x*y))+2);
    auto isValid=[&](ll i,ll j){
    	return i>=0 && i<x && j>=0 && j < y;
    };
    vl dx={1,-1,0,0};
    vl dy={0,0,1,-1};
    map<char,ll> banned;
    banned['~']++;
    banned['*']++;
    auto obt=[&](ll i,ll j){
    	V<pl> res;
    	for(ll it=0;it<4;it++){
    		ll newX=i+dx[it],newY=j+dy[it];
    		if(isValid(newX,newY) && !banned.count(xd[newX][newY])){
    			res.push_back({newX,newY});
    		}
    	}
    	return res;
    };
    auto agre=[&](ll i,ll j,ll cap=1){
    	V<pl> vecinos=obt(i,j);
		ll idOut=id2[i][j];
		for(auto & ele : vecinos){
			ll cx=ele.first,cy=ele.second;
			ll idIn=id[cx][cy];
			dn.addEdge(idOut,idIn,cap);
		}
    };
    const int INF=1e9;
    ll S=2*x*y,T=(2*x*y)+1;
    for(ll i=0;i<x;i++){
    	for(ll j=0;j<y;j++){
    		if(xd[i][j]=='~') continue;
    		ll idIn=id[i][j],idOut=id2[i][j];
    		if(xd[i][j]=='*'){
    			dn.addEdge(S,idIn,1);
    			dn.addEdge(idIn,idOut,1);
    			agre(i,j);
    		}
    		else if(xd[i][j]=='.'){
    			dn.addEdge(idIn,idOut,1);
    			agre(i,j);
    		}
    		else if(xd[i][j]=='@'){
    			dn.addEdge(idIn,idOut,INF);
    			agre(i,j,INF);
    		}
    		else{
    			agre(i,j,INF);
    			dn.addEdge(idOut,T,p);
    		}
    	}
    }
    ll val=dn.calc(S,T);
    for(ll i=0;i<(x*y);i++){
    	for(auto & edge : dn.adj[i]){
    		cout<<i<<" -> "<<edge.to<<" ,flow: "<<edge.flow()<<"\n";
    	}
    }
    cout<<val<<"\n";

}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    //cin>>t;
    ll x,y,p;
    while(cin>>x>>y>>p){
    	solve(x,y,p);
    }
}