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
const int MX = 100001;
const int N=1000+3;

void solve(){
    ll n,ts=0,maxi=LONG_LONG_MIN;
    cin>>n;
    ll a[n];
    FOR(i,0,n){
        cin>>a[i];
        maxi=max(maxi,a[i]);
        ts+=a[i];
    }
    sort(a,a+n);
    ll m;
    cin>>m;
    FOR(i,0,m){
        ll x,y;
        cin>>x>>y;
        ll k=lower_bound(a,a+n,x)-a,ans=2e18;
        if(k){
            ans=min(ans,x-a[k-1]+max(0ll,y-ts+a[k-1]));
        }
        if(k<n){
            ans=min(ans,max(0ll,y-ts+a[k]));
        }
        cout<<ans<<"\n";



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








