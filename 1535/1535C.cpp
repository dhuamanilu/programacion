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
    string s;
    cin>>s;
    ll n=s.size();
    ll dp[n+1][2];
    FOR(i,0,n){
        FOR(j,0,2){
            dp[i][j]=0;
        }
    }
    ll ans=0;
    FOR1(i,1,n){
        if(s[i-1]=='?'){
            dp[i][1]=dp[i-1][0]+1;
            dp[i][0]=dp[i-1][1]+1;
        }
        else if(s[i-1]=='0'){
            dp[i][1]=0;
            dp[i][0]=dp[i-1][1]+1;
        }
        else{
            dp[i][1]=dp[i-1][0]+1;
            dp[i][0]=0;
        }
        ans+=max(dp[i][0],dp[i][1]);
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








