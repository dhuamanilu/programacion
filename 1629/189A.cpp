#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<ll,ll> mll;
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
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    vll dp(n+1,LONG_LONG_MIN);
    dp[0]=0;
    FOR1(i,a,n){
        dp[i]=max(dp[i],dp[i-a]+1);
    }
    FOR1(i,b,n){
        dp[i]=max(dp[i],dp[i-b]+1);
    }
    FOR1(i,c,n){
        dp[i]=max(dp[i],dp[i-c]+1);
    }
    cout<<dp[n]<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
