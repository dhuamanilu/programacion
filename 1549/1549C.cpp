#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map <ll,ll> mll;
typedef vector <pair<ll,ll>> vpll;
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
const int MX = 200005;
const int N=1000+3;


void solve(){
    ll n,m;
    cin>>n>>m;
    vll edges(n+1,0);
    vll menores(n+1,0);
    FOR(i,0,m){
        ll u,v;
        cin>>u>>v;
        edges[u]++;
        edges[v]++;
        if(u<v){
            menores[v]++;
        }
        else{
            menores[u]++;
        }
    }
    ll q,ans=0;
    FOR(i,0,n+1){
        if(edges[i]==menores[i]){
            ans++;
        }
    }
    cin>>q;
    FOR(i,0,q){
        ll tip,u,v;
        cin>>tip;
        if(tip==1){
            cin>>u>>v;
            if(edges[u]==menores[u]) ans--;
            if(edges[v]==menores[v]) ans--;
            edges[u]++;
            edges[v]++;

            if(u<v){
                menores[v]++;
            }
            else{
                menores[u]++;
            }
            if(edges[u]==menores[u]) ans++;
            if(edges[v]==menores[v]) ans++;
        }
        else if(tip==2){
            cin>>u>>v;
            if(edges[u]==menores[u]) ans--;
            if(edges[v]==menores[v]) ans--;
            edges[u]--;
            edges[v]--;
            if(u<v){
                menores[v]--;
            }
            else{
                menores[u]--;
            }
            if(edges[u]==menores[u]) ans++;
            if(edges[v]==menores[v]) ans++;
        }
        else{
            cout<<ans-1<<"\n";
        }
    }
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








