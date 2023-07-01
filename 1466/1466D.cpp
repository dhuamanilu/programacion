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
void solve(){
    ll n;
    cin>>n;
    ll a[n];
    FOR(i,0,n){
        cin>>a[i];
    }
    vll deg(n+1,0);
    FOR(i,0,n-1){
        ll u,v;
        cin>>u>>v;
        deg[u]++;
        deg[v]++;
    }
    vll to;
    ll ans=0;
    FOR(i,0,n){
        FOR(j,0,deg[i+1]-1){
            to.pb(a[i]);
        }
        ans+=a[i];
    }
    sort(all(to),greater<ll>());
    for(auto e : to){
        cout<<ans<<" ";
        ans+=e;
    }
    cout<<ans<<"\n";

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








