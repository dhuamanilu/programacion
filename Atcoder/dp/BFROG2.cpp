#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<long long> vll;
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FOR1(i, a, b) for (int i=a; i<=(b); i++)
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
const long long INF=10000000000;
void solve(){
    ll n,k;
    cin>>n>>k;
    vll h(n);
    FOR(i,0,n){
        cin>>h[i];
    }
    vll dp(n,INF);
    dp[0]=0;
    FOR(i,1,n){
        FOR1(j,1,k){
            if(i>=j)
                dp[i]=min(dp[i],dp[i-j]+abs(h[i]-h[i-j]));
            else break;
        }
    }
    cout<<dp[n-1]<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("frog2.in", "r")) {
		freopen("frog2.in", "r", stdin);
		freopen("frog2.out", "w", stdout);
    }
  	int t=1;
    //cin>>t;
  	while(t--){
        solve();
  	}
	return 0;
}
