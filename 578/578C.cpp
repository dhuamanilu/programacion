#include <bits/stdc++.h>
using namespace std;

//* Debugger
string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
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
//* /Debugger

using ll = long long;
using pl = pair<ll, ll>;

#define tcT template<class T
tcT> using V = vector<T>;
using vl = V<ll>;

#define sz(x) int((x).size())
#define all(x) bg(x), end(x)

#define dbg(x) cout << "Line(" << __LINE__ << "): " << "\033[1;34m" << #x << "\033[0;32m = \033[35m" << to_string(x) << "\033[0m" << endl;
#define GA dbg(0)
#define RAYA   dbg("================================");
struct UF {
	vector<int> e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
const int N=1005;
vector<vl> G(N);

vl vis(N,0);
vl group(N,-1);
vector<pl> sobran;
UF dsu(N);
void dfs(ll ele){
    vis[ele]=1;
    for(auto & e : G[ele]){
        if(!vis[e]){
            dsu.join(e,ele);
            dfs(e);
        }
        else{
            if(dsu.sameSet(e,ele)){
                sobran.emplace_back(make_pair(e,ele));
            }
            else{
                dsu.join(e,ele);
            }
            
        }
        
    }
}
void solve(){
    ll n;
    cin>>n;
    vector<pl> a(n-1);
    for(auto & e : a){
        cin>>e.first>>e.second;
        ll u=min(e.first,e.second),v=max(e.first,e.second);
        G[u].emplace_back(v);
        //G[v].emplace_back(u);
    }
    
    for(ll i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }
    //dbg(sobran);
    vector<array<ll,4>> res;
    while(sobran.size() > 0){
        auto xd=sobran.back();
        sobran.pop_back();
        for(ll i=1;i<=n;i++){
            if(!dsu.sameSet(i,xd.first)){
                res.push_back({xd.first,xd.second,xd.first,i});
                dsu.join(i,xd.first);
                break;
            }
        }
    }
    cout<<res.size()<<"\n";
    for(auto &e : res){
        for(auto & e2 : e){
            cout<<e2<<" ";
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