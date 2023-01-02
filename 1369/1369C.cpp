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
    ll n,k;
    cin>>n>>k;
    ll a[n];
    FOR(i,0,n){
        cin>>a[i];
    }
    ll w[k];
    FOR(i,0,k){
        cin>>w[i];
    }
    sort(a,a+n);
    sort(w,w+k,greater<ll>());
    ll ans=0,j=n-1;
    FOR(i,0,k){
        if(w[i]==1){
            ans+=2*a[j];
            j--;
        }
    }
    ll l=0;
    FOR(i,0,k){
        if(w[i]==1) break;
        ans+=a[j];
        ll mini=a[j];
        FOR(it,l,l+w[i]-1){
            mini=min(mini,a[it]);
        }
        ans+=mini;
        l=l+w[i]-1;
        j--;
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








