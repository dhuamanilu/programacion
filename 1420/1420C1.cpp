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
    ll n,q;
    cin>>n>>q;
    ll a[n];
    FOR(i,0,n){
        cin>>a[i];
    }
    ll sum1=-(ll)1e18,sum2=0,guarda=0;
    FOR(i,0,n){
        sum1=max(sum1,sum2+a[i]);
        sum2=max(sum2,guarda-a[i]);
        guarda=sum1;
    }
    cout<<max(sum1,sum2)<<"\n";
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








