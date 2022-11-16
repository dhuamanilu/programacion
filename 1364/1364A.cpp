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
    ll n,x;
    cin>>n>>x;
    ll a[n];
    vector <ll> pref(n,0),suff(n,0);
    FOR(i,0,n){
        cin>>a[i];

    }
    pref[0]=a[0];
    FOR(i,1,n){
        pref[i]=pref[i-1]+a[i];
    }
    suff[n-1]=a[n-1];
    for(ll i=n-2;i>=0;i--){
        suff[i]=suff[i+1]+a[i];
    }
    ll ans=LONG_LONG_MIN;
    FOR(i,0,n){
        if(pref[i]%x){
            ans=max(ans,i+1);
        }
    }
    for(ll i=n-1;i>=0;i--){
        if(suff[i]%x){
            ans=max(ans,n-i);
        }
    }
    if(ans==LONG_LONG_MIN) ans=-1;
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








