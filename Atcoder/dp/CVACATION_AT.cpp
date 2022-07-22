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
    int n;
    cin>>n;
    int a[n][3];
    FOR(i,0,n){
        FOR(j,0,3){
            cin>>a[i][j];
        }
    }
    int dp[n][3];
    dp[0][0]=a[0][0];
    dp[0][1]=a[0][1];
    dp[0][2]=a[0][2];

    FOR(i,1,n){
        dp[i][0]=max(dp[i-1][1],dp[i-1][2])+a[i][0];
        dp[i][1]=max(dp[i-1][0],dp[i-1][2])+a[i][1];
        dp[i][2]=max(dp[i-1][1],dp[i-1][0])+a[i][2];
    }
    int rpta=max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
    cout<<rpta<<"\n";

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
