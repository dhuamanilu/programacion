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
ll pot(ll a, ll n) {
    if (n == 0) return 1;
    ll x = pot(a, n/2);
    if (n % 2 == 0) return x*x;
    return x*x*a;
}
void solve(){
    ll n,k;
    cin>>n>>k;
    ll a[n];
    FOR(i,0,n){
        cin>>a[i];
        a[i]=pot(10,a[i]);
    }
    sort(a,a+n);
    ll ans=0;
    k++;
    FOR(i,0,n){
        ll left=k;
        if(i+1<n){
            left=min(left,a[i+1]/a[i]-1);
        }
        ans+=a[i]*left;
        k-=left;
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








