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
    ll a[n+1],b[n+1];
    FOR1(i,1,n){
        cin>>a[i];
    }
    FOR1(i,1,n){
        cin>>b[i];
    }
    vector<vll> dp(n+1,vll(2,0));
    FOR1(i,1,n){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]+a[i]);
        dp[i][1]=max(dp[i-1][1],dp[i-1][0]+b[i]);
    }
    cout<<max(dp[n][0],dp[n][1])<<"\n";
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








