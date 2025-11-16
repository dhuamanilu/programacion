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
void solve(){
    ll n,m;
    cin>>n>>m;
    vl a(n+1);
    ll sum=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    vl b(n+1);
    ll sum2=0;
    for(ll i=1;i<=n;i++){
        cin>>b[i];
        sum2+=b[i];
    }
    V<vl> G(n+1);
    for(ll i=1;i<=m;i++){
        ll p,q;
        cin>>p>>q;
        G[p].push_back(q);
        G[q].push_back(p);
    }
    if(sum!=sum2){
        cout<<"NO\n";
    }
    else{
        Dinic dn((2*n)+3);
        map<ll,ll> left,right;
        for(ll i=1;i<=n;i++){
            if(a[i] > b[i]){
                left[i]=0;
                /*dbg("addind edge del inicio a losl eft",(2*n)+1,i,a[i]-b[i]);
                dn.addEdge((2*n)+1,i,a[i]-b[i]);*/
                for(auto & vec : G[i]){
                    //dbg("addind edge vecinos de mi me sobran",i,n+vec,a[i]-b[i]);
                    dn.addEdge(i,n+vec,a[i]-b[i]);
                }
            }
            else if(a[i]< b[i]){
                right[n+i]=0;
                /*dbg("addind edge de right al sink",n+i,(2*n)+2,b[i]-a[i]);
                dn.addEdge(n+i,(2*n)+2,b[i]-a[i]);*/
                for(auto & vec : G[i]){
                    //dbg("addind edge vecinos de right ",vec,n+i,b[i]-a[i]);
                    dn.addEdge(vec,n+i,b[i]-a[i]);
                }
            }
        }
        for(ll i=1;i<=n;i++){
            dn.addEdge((2*n)+1,i,a[i]);
            dn.addEdge(n+i,(2*n)+2,b[i]);
            dn.addEdge(i,n+i,b[i]);
        }
        //dbg(left,right);
        ll val=dn.calc((2*n)+1,(2*n)+2);
        /*auto imprimir=[&](){
            for(ll i=0;i<dn.adj.size();i++){
                for(auto & edge : dn.adj[i]){
                    cout<<i<<" -> "<<edge.to<<" ,flow: "<<edge.flow()<<"\n";
                }
            }
        };
        imprimir();*/
        /*bool ok=true;
        for(ll i=1;i<=2*n;i++){
            for(auto &edge : dn.adj[i]){
                if(left.count(i) && edge.to!=((2*n)+1)){
                    left[i]+=edge.flow();
                }
                else if(right.count(i) && edge.to == ((2*n)+2)){
                    dbg(i,right);
                    dbg("right",i,edge.to,edge.flow(),b[i-n]-a[i-n]);
                    if(edge.flow()!=(b[i-n]-a[i-n])){
                        ok=false;
                        break;
                    }
                }
            }
            if(!ok) break;
        }
        dbg(left,right,ok);*/
        /*if(ok){
            for(auto & e : left){
                ll botar=a[e.first] - b[e.first];
                dbg(e,botar);
                if(e.second!=botar){
                    ok=false;
                    break;
                }
            }
        }*/
        
        
        V<vl> matrix(n+1,vl(n+1,0));
        for(ll i=1;i<=n;i++){
            for(auto &edge : dn.adj[i]){
                /*if(i==2 && edge.to==5){
                    dbg("cuakk",i,edge.to,edge.flow());
                }*/
                if(edge.to!=((2*n)+1)){
                    ll hacia = edge.to <= n ? n : edge.to - n;
                    //dbg(i,edge.to,hacia);
                    matrix[i][hacia]+=edge.flow();
                }
                else if(edge.to == (n+i)){
                    matrix[i][edge.to-n] += edge.flow(); 
                }
            }
        }
        bool ok=true;
        for(ll i=1;i<=n;i++){
            ll sum=0;
            for(ll j=1;j<=n;j++){
                sum+=matrix[j][i];
            }
            if(sum!=b[i]){
                ok=false;
                break;
            }
        }
        if(ok){
            cout<<"YES\n";
            //dbg("gola");
            for(ll i=1;i<=n;i++){
                for(ll j=1;j<=n;j++){
                    cout<<matrix[i][j]<<" ";
                }
                cout<<"\n";
            }
        }
        else cout<<"NO\n";
        
        

        
    }

}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    //cin>>t;
    while(t--) solve();
}