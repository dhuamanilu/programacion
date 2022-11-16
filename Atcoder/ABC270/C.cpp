#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define mp make_pair
#define pb push_back
#define f first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 200005;
const int N=1000+3;
const int INF=100000000;
vector <ll> G[MX];
vector <ll> ans;
bool vis[MX];
bool stop;
void dfs(ll x,ll y){
    if(!stop){
        ans.push_back(x);
    }
    if(x==y) stop=true;
    vis[x]=true;
    if(x==y) return;
    for(auto e :G[x] ){
        if(vis[e]) continue;
        dfs(e,y);
    }
    if(!stop){
        ans.pop_back();
    }
}
void solve(){
    ll n,x,y;
    cin>>n>>x>>y;
    FOR(i,0,MX){
        vis[i]=false;
    }
    FOR(i,0,n-1){
        ll u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    stop=false;
    dfs(x,y);
    for(auto e : ans){
        cout<<e<<" ";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  	int t=1;
    //cin>>t;
  	while(t--){
        solve();
  	}
	return 0;
}
