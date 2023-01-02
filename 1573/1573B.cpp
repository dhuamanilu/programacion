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
const int MX = 100001;
const int N=1000+3;

void solve(){
    ll n;
    cin>>n;
    mll m;
    vpll v;
    ll a[n],b[n];
    FOR(i,0,n){
        cin>>a[i];
        m[a[i]]=i;
    }
    FOR(i,0,n){
        cin>>b[i];
        v.pb({b[i],i});
    }
    sort(all(v));
    ll mini=LONG_LONG_MAX;
    for(ll i=n-1;i>=0;i--){
        mini=min(mini,v[i].se);
        v[i].se=mini;
    }
    ll ans=LONG_LONG_MAX,j=0;
    for(ll i=1;i<=2*n;i+=2){
        ll x=m[i];
        x+=v[j].se;
        ans=min(ans,x);
        j++;
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








