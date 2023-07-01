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
const int MX = 100005;
const int N=1000+3;
void solve(){
    ll n;
    cin>>n;
    ll a[n];
    mll m;
    FOR(i,0,n){
        cin>>a[i];
        m[a[i]]++;
    }
    ll ans=0;
    vll dp(100001,0);
    dp[1]=m.count(1) ? m[1] : 0;
    dp[2]=max(dp[1],m[2]*2);
    FOR1(i,3,1e5){
        dp[i]=max(dp[i-1],dp[i-2]+i*m[i]);
    }
    cout<<dp[(ll)1e5]<<"\n";
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








