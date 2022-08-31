#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


typedef pair<int, int> pi;

typedef vector<int> vi;

#define FOR(i, a, b) for (int i=a; i<(b); i++)

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
const int INF=100000000;
void solve(){
    ll n,w;
    cin>>n>>w;
    vector <ll> dp(w+1);
    FOR(i,0,n){
        ll peso,valor;
        cin>>peso>>valor;
        for(int j=w-peso;j>=0;j--){
            dp[j+peso]=max(dp[j+peso],dp[j]+valor);
        }
    }
    ll ans=0;
    for(int i=0;i<=w;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans<<"\n";


}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /*if (fopen("abcd.in", "r")) {
		freopen("billboard.in", "r", stdin);
		freopen("billboard.out", "w", stdout);
    }*/
  	int t=1;
    //cin>>t;

  	while(t--){
        solve();
  	}
	return 0;
}
