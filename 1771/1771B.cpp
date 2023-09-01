#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
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
const int MX = 100001;
const int N=1000+3;

void solve(){
    ll n,m;
    cin>>n>>m;
    vll mn(n,n-1);
    FOR(i,0,m){
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        mn[x]=min(mn[x],y-1);
    }
    for(ll i=n-2;i>=0;i--){
        mn[i]=min(mn[i],mn[i+1]);
    }
    ll ans=0;
    FOR(i,0,n){
        ans+=(mn[i]-i+1);
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








