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
    int n,k;
    cin>>n>>k;
    int a[n];
    FOR(i,0,n){
        cin>>a[i];
    }
    vector <int> dp(n,INF);
    dp[0]=0;
    FOR(i,1,n){
        int ans=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0)
                ans=min(dp[i-j]+abs(a[i]-a[i-j]) ,ans);
            //cout<<dp[i]<<" ";
        }
        dp[i]=ans;
        //cout<<" ESTE ES dp[i] : "<<i<<" <--i | dp [i] -->"<<dp[i]<<"\n";
    }

    cout<<dp[n-1]<<"\n";

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
