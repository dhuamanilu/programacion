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
    ll n;
    cin>>n;
    ll a[n];
    FOR(i,0,n){
        cin>>a[i];
    }
    sort(a,a+n);
    ll ans=LONG_LONG_MAX;
    FOR(i,0,n){
        ll aux=LONG_LONG_MAX,aux2=LONG_LONG_MAX,aux3=LONG_LONG_MAX;
        if(i+2<n)
            aux=a[i+1]-a[i]+a[i+2]-a[i];
        if(i+2<n)
            aux2=a[i+1]-a[i]+a[i+2]-a[i+1];
        if(i+2<n)
            aux3=a[i+2]-a[i]+a[i+1]-a[i];
        ans=min(ans , min(min(aux,aux2),aux3));
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








