#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
#define FOR(i, a, b) for (long long i=a; i<(b); i++)
#define FOR1(i, a, b) for (long long i=a; i<=(b); i++)
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
const int MX = 100005;
const int N=1000+3;

vector <ll> values={2,11};
vector <ll> marcas;
void dfs(vector<vector<array<ll, 2>>> &G,ll v,ll p,ll c){
    for(auto e : G[v]){
        if(e[0]!=p){
            marcas[e[1]]=c;
            c^=1;
            dfs(G,e[0],v,c);
        }
    }
}
void solve(){
    ll n;
    cin>>n;
    vector<vector<array<ll, 2>>> G(n);
    vector <ll> deg(n,0);
    FOR(i,0,n-1){
        ll u,v;
        cin>>u>>v;
        u--;
        v--;
        G[u].push_back({v,i});
        G[v].push_back({u,i});
        deg[u]++,deg[v]++;
    }

    if(*max_element(all(deg))>2){
        cout<<"-1\n";
    }
    else{
        marcas.resize(n-1);
        dfs(G,0,-1,0);
        for(auto e : marcas){
            cout<<values[e]<<" ";
        }
        cout<<"\n";

    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}








